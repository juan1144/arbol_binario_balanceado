#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//<-------------------------------------------------------------------------------------------------- sub-función para calcular altura ---------------------------------------------------------------------------------------------------->

int altura(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->altura;
}

//<-------------------------------------------------------------------------------------------------- Calcular Máximo ---------------------------------------------------------------------------------------------------->

int max(int a, int b) {
    return (a > b) ? a : b;
}

//<-------------------------------------------------------------------------------------------------- Crear un NODO ---------------------------------------------------------------------------------------------------->

struct Node * newNode(int key) {
    struct Node *node = (struct Node *) malloc(sizeof (struct Node));
    node->key = key;
    node->izquierda = NULL;
    node->derecha = NULL;
    node->altura = 1;
    return (node);
}

//<-------------------------------------------------------------------------------------------------- Obtener el balance ---------------------------------------------------------------------------------------------------->

int obtenerBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return altura(N->izquierda) - altura(N->derecha);
}

//<-------------------------------------------------------------------------------------------------- Valor minimo del NODO ---------------------------------------------------------------------------------------------------->

struct Node *minValorNodo(struct Node *nodo) {
    struct Node *current = nodo;
    while (current->izquierda != NULL)
        current = current->izquierda;
    return current;
}

//<-------------------------------------------------------------------------------------------------- Rotación a IZQ ---------------------------------------------------------------------------------------------------->

struct Node *rotacionIzq(struct Node *X) {
    struct Node *y = X->derecha;
    struct Node *T2 = y->izquierda;
    y->izquierda = X;
    X->derecha = T2;
    X->altura = max(altura(X->izquierda), altura(X->derecha)) + 1;
    y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;
    return y;
}

//<-------------------------------------------------------------------------------------------------- Rotación a DER ---------------------------------------------------------------------------------------------------->

struct Node *rotacionDer(struct Node *y) {
    struct Node *x = y->izquierda;
    struct Node *T2 = x->derecha;
    x->derecha = y;
    y->izquierda = T2;
    y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;
    x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;
    return x;
}

//<-------------------------------------------------------------------------------------------------- Insertar Nodo ---------------------------------------------------------------------------------------------------->

struct Node *insertaNodo(struct Node *node, int key) {
    //Busca la posición correcta para insertar el nodo

    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->izquierda = insertaNodo(node->izquierda, key);
    else if (key > node->key)
        node->derecha = insertaNodo(node->derecha, key);
    else
        return node;

    //Actualiza el balance del factor por nodo y el balance del árbol

    node->altura = 1 + max(altura(node->izquierda),
            altura(node->derecha));
    int balance = obtenerBalance(node);

    //ROTACIONES

    if (balance > 1 && key < node->izquierda->key) //DER ROTACION
        return rotacionDer(node);
    if (balance<-1 && key > node->derecha->key) //IZQ ROTACION
        return rotacionIzq(node);
    if (balance > 1 && key > node->izquierda->key) {//IZQ-DER ROTACION
        node->izquierda = rotacionIzq(node->izquierda);
        return rotacionDer(node);
    }
    if (balance<-1 && key < node->derecha->key) {//Der-Izq ROTACION
        node->derecha = rotacionDer(node->derecha);
        return rotacionIzq(node);
    }
    return node;
}

//<-------------------------------------------------------------------------------------------------- Eliminar un nodo ---------------------------------------------------------------------------------------------------->

struct Node *eliminarNodo(struct Node *root, int key) {
    //Encuentra el nodo y lo elimina
    if (root == NULL)//valor no encontrado
        return root;
    if (key < root->key)
        root->izquierda = eliminarNodo(root->izquierda, key);
    else if (key > root->key)
        root->derecha = eliminarNodo(root->derecha, key);
    else {
        if ((root->izquierda == NULL) || (root->derecha == NULL)) {
            struct Node *temp = root->izquierda ? root->izquierda : root->derecha;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            struct Node *temp = minValorNodo(root->derecha);
            root->key = temp->key;
            root->izquierda = eliminarNodo(root->derecha, temp->key);
        }
    }
    if (root == NULL)
        return root;
    root->altura = 1 + max(altura(root->izquierda),
            altura(root->derecha));
    int balance = obtenerBalance(root);
    if (balance > 1 && obtenerBalance(root->izquierda) >= 0)
        return rotacionDer(root);
    if (balance > 1 && obtenerBalance(root->izquierda) < 0) {
        root->izquierda = rotacionIzq(root->izquierda);
        return rotacionDer(root);
    }
    if (balance < -1 && obtenerBalance(root->derecha) <= 0)
        return rotacionIzq(root);
    if (balance < -1 && obtenerBalance(root->derecha) > 0) {
        root->derecha = rotacionDer(root->derecha);
        return rotacionIzq(root);
    }

    return root;
}

//<-------------------------------------------------------------------------------------------------- Imprimir arbol ---------------------------------------------------------------------------------------------------->

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->izquierda);
        preorder(root->derecha);
    }
}


//<-------------------------------------------------------------------------------------------------- Inorder ---------------------------------------------------------------------------------------------------->

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->izquierda);
        printf("%d ", root->key);
        inorder(root->derecha);
    }
}

//<-------------------------------------------------------------------------------------------------- post order ---------------------------------------------------------------------------------------------------->

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->izquierda);
        postorder(root->derecha);
        printf("%d ", root->key);
    }
}

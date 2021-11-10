/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: juan
 *
 * Created on 10 de noviembre de 2021, 09:11
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef FUNCIONES_H
#define FUNCIONES_H

//<-------------------------------------------------------------------------------------------------- Creación del NODO ---------------------------------------------------------------------------------------------------->

struct Node {
    int key;
    struct Node *izquierda;
    struct Node *derecha;
    int altura;
};

int altura(struct Node *N);
int max(int a, int b);
struct Node * newNode(int key);
int obtenerBalance(struct Node *N);
struct Node *minValorNodo(struct Node *nodo);
struct Node *rotacionIzq(struct Node *X);
struct Node *rotacionDer(struct Node *y);
struct Node *insertaNodo(struct Node *node, int key);
struct Node *eliminarNodo(struct Node *root, int key);
void preorder(struct Node *root);
void inorder(struct Node *root);
void postorder(struct Node *root);

#endif /* FUNCIONES_H */


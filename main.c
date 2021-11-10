/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: juan
 *
 * Created on 10 de noviembre de 2021, 09:07
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/*
 * 
 */
int main(int argc, char** argv) {

    struct Node *root = NULL;
    int val, ch;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.EXIT\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter value : ");
                scanf("%d", &val);
                Output:
                root = insertaNodo(root, val);
                break;
            case 2:
                printf("\nEnter value : ");
                scanf("%d", &val);
                root = eliminarNodo(root, val);
                break;
            case 3:
                printf("\nPreOrder : ");
                preorder(root);
                printf("\nOrder : ");
                inorder(root);
                printf("\nPostOrder : ");
                postorder(root);
                break;
            case 4:
                exit(0);
                break;
        }
    }
    return (EXIT_SUCCESS);
}


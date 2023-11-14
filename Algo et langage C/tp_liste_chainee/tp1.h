//
// Created by Yassine Boulkenafet on 08/11/2023.
//

#ifndef ALGO_ET_LANGAGE_C_TP1_H
#define ALGO_ET_LANGAGE_C_TP1_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Liste_numeros{
    int number;
    struct Liste_numeros * next;
}LSN;

// Fonctions prérequises (dernier cour) :

LSN* addAtEnd(LSN* L,int number){
    LSN * nouveauMaillon = (LSN*)malloc(sizeof(LSN));;
    nouveauMaillon->number = number;
    nouveauMaillon->next = NULL;
    if(L == NULL){
        return  nouveauMaillon;
    }else {
        LSN * P = L;

        while (P->next != NULL) {
            P = P->next;

        }
        P->next = nouveauMaillon;
        return L;
    }
}

int chainLength(LSN* L){
    int n = 0;
    LSN *P = L;
    while(P!=NULL/*P->next*/) {
        P = P->next;
        n++;
    }
    return n;
}

void displayListNumb(LSN*L){
    LSN *P = L;
    if(P == NULL){
        printf("\n\n Le tableau est vide");
    }

    while(P!=NULL){
        printf("\n\n%d\n\n",P->number);
        P = P->next;
    }
}

// Exo 1


void isListEmpty(LSN* L) {
    if (L == NULL) {
        printf("La liste est vide !\n");
    } else {
        printf("La liste n'est pas vide !\n");

    }
}

// Exo 2

int searchInList (LSN * L, int search){
    LSN * P = L;
    while(P!=NULL/*P->next*/) {
        if (P->number == search){
            return 1;
        }
        P = P->next;

    }
    return 0;
}

// Exo 3

int searchPosition (LSN * L, int search){
    LSN * P = L;
    int position = 1;
    while(P!=NULL/*P->next*/) {
        if (P->number == search){
            return position;
        }
        position++;
        P = P->next;

    }
    return -1;
}

//Exo 4

int goToPosition(LSN* L,int position){
    if(position == 0){
        return -1;
    }
    LSN * P = L;
    int indexList = 1;
    while(P != NULL && indexList < position){
        P = P->next;
        indexList++;
    }
    if (P == NULL) {
        return -1;
    }
    return P->number;

}

// Exo 5

int isListSorted(LSN* L) {
    LSN* P = L;
    while (P != NULL && P->next != NULL) {
        if (P->number > P->next->number) {
            return 0;
        }
        P = P->next;
    }
    return 1;
}

#endif //ALGO_ET_LANGAGE_C_TP1_H

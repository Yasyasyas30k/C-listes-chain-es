//
// Created by Yassine Boulkenafet on 09/11/2023.
//

#include <stdio.h>
#include <stdlib.h>



typedef struct Liste_numeros{
    int number;
    struct Liste_numeros * next;
    struct Liste_numeros * prev;
}LSN;

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

LSN* addWherever (LSN * L,int position, int val){
    int n = 1;
    LSN * P = L;
    LSN* nouveauMaillon = (LSN*)malloc(sizeof(LSN));
    nouveauMaillon->number = val;

    while(P != NULL){
        if(position == n) {
            nouveauMaillon->next = P;
            nouveauMaillon->prev = P->prev;

            if (P->prev != NULL) {
                P->prev->next = nouveauMaillon;
            }
            P->prev = nouveauMaillon;

        }
        P = P->next;
        n++;
    }

    return L;
}

int main (){

    return 0;
}
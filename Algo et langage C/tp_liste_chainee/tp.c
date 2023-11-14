//
// Created by Yassine Boulkenafet on 07/11/2023.
//

#include "tp1.h"

int main(){

    LSN * L = NULL;
    int number;
    int nb = 0;
    int i =0;

    printf("Combien de numéros à rentrer? :");
    scanf("%d",&nb);
    for(i;i<nb;i++) {

        printf("\nEntrez le %d e numéro :", i + 1);
        scanf(" %d", &number);
        L = addAtEnd(L,number);
    }
    if(nb == chainLength(L)){
        printf("\nTerminé\n\n");
    }

    int search;

    printf("Entrez un numéro à chercher dans la liste (Exo 2 & 3) :");
    scanf(" %d", &search);

    int position = searchPosition(L,search);


    if(searchInList(L,search)) {
        if (position != -1) {
            printf("L'élément existe, à la %d ème position\n\n", position);
        }
    }
    else {
        printf("L'élément existe pas dans la liste.\n\n");

    }
    int moveTo;

    printf("A quelle position se déplacer? (Exo 4):");
    scanf("%d",&moveTo);

    int resultat = goToPosition(L, moveTo);

    if (resultat != -1) {
        printf("La valeur à la position %d est : %d\n\n",moveTo, resultat);
    } else {
        printf("La position %d est hors-limite.\n\n", moveTo);
    }

    if(isListSorted(L)){
        printf("La liste est triée en ordre croissant\n");
    }
    else{
        printf("La liste n'est pas triée en ordre croissant\n");
    }




    return 0;
}





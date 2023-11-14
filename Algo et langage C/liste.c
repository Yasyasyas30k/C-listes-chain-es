//
// Created by Yassine Boulkenafet on 27/10/2023.
//
#include <stdlib.h>
#include <stdio.h>




typedef struct Liste_caractere{
    char data;
    struct Liste_caractere * next;
}LSC;


typedef struct Liste_numeros{
    int number;
    struct Liste_numeros * next;
    struct Liste_numeros * prev;
}LSN;












void isListEmpty(LSN* L) {
    // Si le pointeur de la tête est nul, la liste est vide
    if (L == NULL) {
        printf("La liste est vide !\n");
    } else {
        printf("La liste n'est pas vide !\n");

    }
}

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

int longueurChaine(LSC* L){
    int n = 0;
    LSC *P = L;
    while(P!=NULL/*P->next*/) {
        P = P->next;
        n++;
    }
        return n;
}

LSN* ajoutTeteNumb(LSN *L,int number){
    LSN *nouveauMaillon;
    if(L==NULL){
        L = (LSN *)malloc(sizeof(LSN));
        L->next = nouveauMaillon;
        L->number = number;
    }
    else {

        LSN *nouveauMaillon = (LSN*)malloc(sizeof(LSN));
        nouveauMaillon->number = number;
        nouveauMaillon->next = L ;
        L = nouveauMaillon;
    }

    return L;
}


LSC* ajoutTete(LSC *L,char data){
    LSC *nouveauMaillon;
    if(L==NULL){
        L = (LSC *)malloc(sizeof(LSC));
        L->next = nouveauMaillon;
        L->data = data;
    }
    else {

        LSC *nouveauMaillon = (LSC*)malloc(sizeof(LSC));
        nouveauMaillon->data = data;
         nouveauMaillon->next = L ;
         L = nouveauMaillon;
    }

return L;
}

void voidAjoutTete(LSC** L, char data) {
    LSC* nouveauMaillon = (LSC*)malloc(sizeof(LSC));

    if(*L==NULL){
        *L = (LSC *)malloc(sizeof(LSC));
        (*L)->next = NULL;
        (*L)->data = data;
    }
    else {
        nouveauMaillon->data = data;
        nouveauMaillon->next = *L; //
        *L = nouveauMaillon;
    }
}

int searchInList (LSC * L, char search){
    LSC * P = L;
    while(P!=NULL/*P->next*/) {
        if (P->data == search){
            return 1;
        }
        P = P->next;

    }
    return 0;
}

LSC* ajoutFin(LSC* L,char data){
    LSC * nouveauMaillon = (LSC*)malloc(sizeof(LSC));;
    nouveauMaillon->data = data;
    nouveauMaillon->next = NULL;
    LSC * P = L;
    if(L == NULL){
        return (L = nouveauMaillon);
    }
        while (P->next!= NULL) {
            P = P->next;

        }
        P->next = nouveauMaillon;
    return P;
}

LSN* ajoutFinNumb(LSN* L,int number){
    LSN * nouveauMaillon = (LSN*)malloc(sizeof(LSN));;
    nouveauMaillon->number = number;
    nouveauMaillon->next = NULL;
    LSN * P = L;
    if(L == NULL){
        return  nouveauMaillon;
    }else {
        while (P->next != NULL) {
            P = P->next;

        }
        P->next = nouveauMaillon;
        return P;
    }
}

void displayList(LSC*L){
    LSC *P = L;
    if(P == NULL){
        printf("\n\n Le tableau est vide");
    }
    while(P!=NULL){
        printf("\n\n%c\n\n",P->data);
        P = P->next;
    }
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

LSC* deleteCar(LSC* L, char dataToDelete) {
    // Si la liste est vide, il n'y a rien à supprimer, retourner la liste inchangée.
    if (L == NULL) {
        return L;
    }

    if (L->data == dataToDelete) {
        LSC* P = L;
        L = L->next;
        free(P);
        return L;
    }

    LSC* current = L;
    while (current->next != NULL) {
        if (current->next->data == dataToDelete) {
            LSC* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return L;
        }
        current = current->next;
    }

    return L;
}

LSC* deleteByIndex(LSC* L, int index) {
    if (L == NULL) {
        return L;
    }

    // Si l'utilisateur souhaite supprimer le premier élément (index == 1), ajuster la tête de la liste.
    if (index == 1) {
        LSC* temp = L;
        L = L->next;
        free(temp);
        return L;
    }

    LSC* current = L;
    int n = 1;
    while (current->next != NULL) {
        if (n + 1 == index) {
            LSC* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return L;
        }
        current = current->next;
        n++;
    }

    return L;
}

void modifWherever(LSC **L) {
    int modif;
    char modifData;
    printf("Quel index souhaitez vous modifier? : ");
    scanf("%d", &modif);
    printf("Entrez le nouveau caractère souhaité:");
    scanf(" %c", &modifData);
    LSC *P = L;
    int n = 1;
    if (modif == 1){
        L = ajoutTete(L,modifData);
        printf("Ajout en début de liste");
    }
    if (modif == longueurChaine(L)){
        L = ajoutFin(L,modifData);
        printf("Ajout en fin de liste");
    }
    else {
    while (P != NULL) {
        P = P->next;

            if (n < modif) {
                P->data = modifData;
            }
        }
        n++;

    }
}

int searchPosition (LSC * L, search){
    LSC * P = L;
    int position = 1;


    while(P!=NULL/*P->next*/) {
        printf("Caractère actuel : %d, Position actuelle : %d\n", P->data, position); // Sortie de débogage

        if (P->data == search){
            return position;
        }
        P = P->next;
        position++;


    }
    return -1;
}

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

int estTriee(LSN* L) {
    LSN* P = L;
    while (P != NULL && P->next != NULL) {
        if (P->number > P->next->number) {
            return 0; // La liste n'est pas triée
        }
        P = P->next;
    }
    return 1; // La liste est triée
}

LSN* addWherever(LSN* L, int position, int val) {
    LSN* nouveauMaillon = (LSN*)malloc(sizeof(LSN));
    nouveauMaillon->number = val;

    if (position == 1) {
        nouveauMaillon->next = L;
        if (L != NULL) {
            L->prev = nouveauMaillon;
        }
        L = nouveauMaillon;
    } else {
        int n = 1;
        LSN* P = L;
        while (P != NULL && n < position - 1) {
            P = P->next;
            n++;
        }

        if (P != NULL) {
            nouveauMaillon->next = P->next;
            nouveauMaillon->prev = P;
            if (P->next != NULL) {
                P->next->prev = nouveauMaillon;
            }
            P->next = nouveauMaillon;
        } else {
            printf("La position spécifiée est hors de la plage de la liste.\n");
            free(nouveauMaillon); // Libérer la mémoire allouée
        }
    }

    return L;
}

LSN* deleteWherever(LSN* L,int val){
    LSN * P = L;

    while(P!= NULL){
        if(P->number == val) {
            if (P->prev != NULL)
            {
                P->prev->next = P->next;
            }
            else{
                L = P->next;
            }
            if (P->next != NULL) {
                P->next->prev = P->prev;
            }
            free(P);
        }
        P = P->next;

    }
    return L;
}


int main(){
   // LSC *L = NULL;
    char data;
    LSN * L = NULL;
    int number;
   // printf("\nEntrez un caractère :")  ;
   // scanf("%c",&data);
  //  L = ajoutFin(L,data);
    //L = ajoutTete(L, data);

    int nb = 0;
    int i =0;
    printf("Combien de numéros à rentrer? :");
    scanf("%d",&nb);
    for(i;i<nb;i++) {

        printf("\nEntrez le %d e numéro :", i + 1);
        scanf(" %d", &number);
        L = addAtEnd(L,number);
    }
    if(nb == longueurChaine(L)){
        printf("\nTerminé\n\n");
    }
    int search;


    int valzer;
    int pos;

   /* printf("\nQuelle valeur souhaitez vous ajouter? :");
    scanf("%d",&valzer);

    printf("\n A quelle position?:");
    scanf("%d",&pos);

    addWherever(L,pos,valzer); */

    int deleteVal;

    printf("Quelle valeur souhaitez vous supprimer?:");
    scanf("%d",&deleteVal);


    deleteWherever(L,deleteVal);

    displayListNumb(L);





    return 0;
}


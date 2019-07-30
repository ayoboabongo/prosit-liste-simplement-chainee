#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    liste  L=NULL;
    int choix,numero,res;
    do
    {
        printf("1-Ajouter locomotive en tete \n");
        printf("2-Ajouter locomotive en queue \n");
        printf("3-Rechercher wagon \n");
        printf("4-Afficher liste train \n");
        printf("5-Supprimer wagon \n");
        printf("6-Ajouter un wagon apres le numero du wagon donne \n");
        printf("7-Liberer la memoire \n");
        printf("0-Quitter\n");
        printf("veuillez entrer votre choix \n");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1 :
            L=ajout_tet(L);
            printf("\n");
            break;
        case 2 :
            L=ajout_queue(L);
            printf("\n");
            break;
        case 3 :
            printf("Entrez le numero du wagon \n");
            scanf("%d",&numero);
            res=recherche_wagon(L,numero);
            printf("\n");
            break;
        case 4 :
            afficher_liste(L);
            printf("\n");
            break;
        case 5 :
            L=supprimer_wagon(L);
            printf("\n");
            break;
        case 6 :
            printf("Entrez le numero du wagon \n");
            scanf("%d",&numero);
            L=ajouter_wagon(L,numero);
            printf("\n");
            break;
        case 7 :
            L=liberer_memoire(L);
            printf("\n");
            break;
        }
    }while(choix!=0);

    return 0;
}

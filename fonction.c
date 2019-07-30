#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

wagon saisir_wag(wagon w)
{
    printf("Numero \n");
    scanf("%d",&w.numero);
    printf("Type :(locomotive ou wagon) \n");
    scanf("%s",w.type);
    printf("Etat  :(panne ou ok) \n");
    scanf("%s",w.type);

    return w;
}

void enregistrement(char nomFichier[])
{
    wagon w;
    FILE* fichier=NULL;
    fichier=fopen(nomFichier,"w");
    if(fichier==NULL)
        printf("impossible d'ouvrir le fichier %s \n",nomFichier);

    else
    {
        fprintf(fichier,"%d %s %s\n",w.numero,w.type,w.etat);
        fclose(fichier);

    }

}

liste ajout_tet(liste L)
{
    wagon w;
    liste nouv;
    nouv=malloc(sizeof(struct cellule));
    if(nouv==NULL)
        printf("Allocation de la memopire non effectue \n");

    else
    {
        w=saisir_wag(w);
        nouv->w=w;
        nouv->suivant=NULL;

        if(L==NULL)
        {
            if(strcmp(w.type,"locomotive")==0)
                L=nouv;
        }

        else
        {
            if(strcmp(w.type,"locomotive")==0)
            {
                nouv->suivant=L;
                L=nouv;
            }

        }
    }

    enregistrement("Fichier.txt");

    return L;
}

liste ajout_queue(liste L)
{

    wagon w;
    liste nouv;
    liste tmp=L;
    nouv=malloc(sizeof(struct cellule));
    if(nouv==NULL)
        printf("Allocation de la memopire non effectue \n");

    else
    {
        w=saisir_wag(w);
        nouv->w=w;
        nouv->suivant=NULL;

        if(L==NULL)
        {
            if(strcmp(w.type,"wagon")==0)
                L=nouv;
        }

        else
        {
            while(tmp->suivant!=NULL)
                tmp=tmp->suivant;

            if(strcmp(w.type,"wagon")==0)
                tmp->suivant=nouv;

        }
    }
    enregistrement("Fichier.txt");

    return L;

}

int recherche_wagon(liste L,int numero)
{
    int res=0;
    liste tmp=L;
    if(L==NULL)
        printf("Liste vide \n");

    else
    {
        while(tmp->suivant!=NULL)
        {
            if(tmp->w.numero==numero)
            {
                printf("\nNumero : %d \nType : %s \nEtat : %s",tmp->w.numero,tmp->w.type,tmp->w.etat);
                printf("\n");
                res=1;
                break;
            }

          tmp=tmp->suivant;
        }

    }

    return res;
}

void afficher_liste(liste L)
{
    liste tmp=L;
     if(L==NULL)
        printf("Liste vide \n");

    else
    {
        while(tmp!=NULL)
        {
            printf("\nNumero : %d \nType : %s \nEtat : %s",tmp->w.numero,tmp->w.type,tmp->w.etat);
            printf("\n");
            tmp=tmp->suivant;
        }
    }
}

liste supprimer_wagon(liste L)
{
    liste tmp,courant;

    if(L==NULL)
        printf("Liste vide \n");

    else
    {
        if(L->suivant==NULL)
        {
            if(strcmp(L->w.etat,"panne")==0)
            {
                free(L);
                L=NULL;

            }

        }
        else
        {
            tmp=L;
            courant=courant->suivant;
            while(courant->suivant!=NULL)
            {
                if(strcmp(courant->w.etat,"panne")==0)
                {
                    tmp->suivant=courant->suivant;
                    free(courant);

                }

                tmp=courant;
                courant=courant->suivant;

            }

        }
    }

    enregistrement("Fichier.txt");

    return L;

}

liste ajouter_wagon(liste L,int numero)
{
    wagon w;
    liste nouv,tmp,courant;
    nouv=malloc(sizeof(struct cellule));
    if(nouv==NULL)
        printf("Allocation non effectuee \n");

    else
    {
        w=saisir_wag(w);
        nouv->w=w;
        nouv->suivant=NULL;

        if(L==NULL)
            printf("Liste vide impossible d'inserer \n");

        else
        {
            if(L->suivant==NULL)
            {
                if(L->w.numero==numero)
                {
                    L->suivant=nouv;
                }
            }

            else
            {
                tmp=L;
                courant=L->suivant;
                while(courant->suivant!=NULL)
                {
                    if(tmp->w.numero==numero)
                    {
                        nouv->suivant=courant;
                        tmp->suivant=nouv;

                    }

                    tmp=courant;
                    courant=courant->suivant;
                }
            }
        }


    }

    enregistrement("Fichier.txt");

    return L;

}

liste liberer_memoire(liste L)
{
    liste tmp;
    if(L==NULL)
        printf("liste vide \n");

    else
    {
        while(L!=NULL)
        {
            tmp=L;
            L=L->suivant;
            free(tmp);
        }
    }

    return L;
}

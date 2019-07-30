#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct
{
    int numero;
    char type[25];
    char etat[25];
}wagon;

typedef struct cellule cellule;
struct cellule
{
    wagon w;
    cellule* suivant;
};
typedef struct cellule* liste;

liste ajout_tet(liste L);

liste ajout_queue(liste L);

int recherche_wagon(liste L,int numero);

void afficher_liste(liste L);

liste supprimer_wagon(liste L);

liste ajouter_wagon(liste L,int numero);

liste liberer_memoire(liste L);



#endif // HEADER_H_INCLUDED

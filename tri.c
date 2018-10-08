#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "init.h"
#include "tri.h"


int tri_chronologique(Oeuvres* ptrOeuvres, int * tableau_a_trier, int taille_a_trier)
/* Permet de trier par ordre chronologique la selection de livre */
{
    int temp = 0;
    int en_desordre = 1;

    while(en_desordre)
    {
        en_desordre = 0;

        for(int i = 0; i < taille_a_trier -1 ; i ++)
        {
            if((int) strtol(((ptrOeuvres+tableau_a_trier[i])->annee), (char **)NULL, 10)        // comparaison des annees en passant par des int
               > (int) strtol(((ptrOeuvres+tableau_a_trier[i+1])->annee), (char **)NULL, 10))
            {
                temp = tableau_a_trier[i + 1];
                tableau_a_trier[i + 1] = tableau_a_trier[i];
                tableau_a_trier[i] = temp;
                en_desordre = 1;
            }
        }
    }
    return 0;
}

int tri_nom_auteur(Oeuvres* ptrOeuvres, int * tableau_a_trier, int taille_a_trier)
/* Permet de trier par ordre alphabetique du nom la selection de livre */
{
    int temp = 0;
    int en_desordre = 1;

    while(en_desordre)
    {
        en_desordre = 0;

        for(int i = 0; i < taille_a_trier -1 ; i ++)
        {
            if(strcmp((ptrOeuvres+tableau_a_trier[i])->auteur_1_nom,(ptrOeuvres+tableau_a_trier[i+1])->auteur_1_nom) == 1)
            {
                temp = tableau_a_trier[i + 1];
                tableau_a_trier[i + 1] = tableau_a_trier[i];
                tableau_a_trier[i] = temp;
                en_desordre = 1;
            }
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "init.h"
#include "menu.h"
#include "affichage.h"
#include "tri.h"

void affichage_menu_principal()
/* Permet l'affichage du menu principal de choix des fonctions de recherches */
{
    printf("\n\n\n\n *** menu *** \n");
    printf(" 0 - Afficher tous les ouvrages\n");
    printf(" 1 - Recherche par nom d'auteur\n");
    printf(" 2 - Recherche par date\n");

    printf(" d - Afficher une oeuvre en detail\n");

    printf(" z - Remise a zero de la selection\n");
    printf(" q - Quitter\n");


    printf("Choisir un menu : ");
}

void affichage_sous_menu_date()
/* Permet l'affichage du sous menu date de choix des fonctions de recherches */
{
    printf("\n\n\n\n *** sous menu date *** \n");
    printf(" 1 - Recherche autour d'une date (+/- 5 ans)\n");
    printf(" 2 - Recherche par intervalle de temps (entre 2 dates)\n");

    printf("Choisir un menu : ");
}

void choix_menu_principal(Oeuvres* ptrLivres, int nbOeuvre)
/* Permet de récupérer le choix de la fonction et de s'y rendre */
{
    char choixMenu[5];
    strcpy(choixMenu, "1");
    int sortie = 0;


    // tant qu'on e croise pas q on reste dans la demande de menu
    while(!sortie)
    {

        int garder_selection = 1;
        int nb_Selection = nbOeuvre;

        int tout_indice[nbOeuvre];
        for(int i = 0; i < nbOeuvre; i++)
        {
            tout_indice[i] = i;
        }

        while(garder_selection)
        {
            affichage_menu_principal();
            scanf("%s", choixMenu);

            if(!strcmp(choixMenu, "0"))
            {
                printf("\n");

                tri_nom_auteur(ptrLivres, tout_indice, nb_Selection);
                for(int i = 0; i < nb_Selection; i++)
                {
                    affichage_selectif_simple(ptrLivres, tout_indice[i], i);
                }
            }
            else if(!strcmp(choixMenu, "1"))
            {
                nb_Selection = rechercheParNomAuteur(ptrLivres, tout_indice, nb_Selection);
            }
            else if(!strcmp(choixMenu, "2"))
            {
                nb_Selection = sous_menu_date(ptrLivres, tout_indice, nb_Selection);
            }
            else if(!strcmp(choixMenu, "d"))
            {
                int a_afficher_en_detail = 0;

                printf("Entrer le numero a afficher en detail : ");
                scanf("%d", &a_afficher_en_detail);

                if(a_afficher_en_detail > 0 && a_afficher_en_detail <= nb_Selection)
                {
                    affichage_selectif_detaille(ptrLivres, tout_indice[a_afficher_en_detail - 1], a_afficher_en_detail);
                }
                else
                {
                    printf("Erreur de selection. \n");
                }


            }
            else if(!strcasecmp(choixMenu, "z"))        // Sortie
            {
                garder_selection = 0;
                printf("\nOn oublie la selection en cours pour faire la prochaine recherche sur l'ensemble des oeuvres\n");
            }
            else if(!strcasecmp(choixMenu, "q"))        // Sortie
            {
                sortie = 1;
                garder_selection = 0;
            }
            else
            {
                printf("Menu incorrect : %s\n", choixMenu);
                strcpy(choixMenu, "\0");
            }
        }
    }
}

int sous_menu_date(Oeuvres* ptrLivres, int *selection, int nb_selectionne)
/* Permet de récupérer le choix de la fonction et de s'y rendre */
/* Sous fonction des dates */
{
    char choixMenu[5];
    strcpy(choixMenu, "1");
    int nbTrouve = 0;

    // tant qu'on e croise pas 99 on reste dans la demande de menu

    affichage_sous_menu_date();

    scanf("%s", choixMenu);

    if(!strcmp(choixMenu, "1"))
    {
        nbTrouve = rechercheAutourDuneDate(ptrLivres, selection, nb_selectionne);
    }
    else if(!strcmp(choixMenu, "2"))
    {
        nbTrouve = rechercheParPeriode(ptrLivres, selection, nb_selectionne);
    }
    else
    {
        printf("Erreur de selection\n");
    }

    return nbTrouve;
}


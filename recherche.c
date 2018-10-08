#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "init.h"
#include "recherche.h"
#include "affichage.h"
#include "tri.h"

int rechercheParNomAuteur(Oeuvres* ptrLivreAChercher, int *selection, int nb_selectionne)
/* Fonction de recherche des noms d'ouvrage à partir d'un nom d'auteur*/
{
    int sizeNom = 100;
    char nomCherche[sizeNom];
    int nbTrouve = 0;
    int indiceTrouve[nb_selectionne];

    printf("Entrer le nom de l'auteur recherche : ");
    scanf("%s", nomCherche);

    for(int i = 0; i < sizeNom; i++)
    // recuperation du nom cherche
    {
        if(nomCherche[i] == '\0')
        {
            sizeNom = i;
        }
    }

    for(int i = 0; i < nb_selectionne; i++)
    {
        if(!strcasecmp((ptrLivreAChercher+selection[i])->auteur_1_nom, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->auteur_2_nom, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->auteur_3_nom, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->auteur_4_nom, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->auteur_5_nom, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_1, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_2, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_3, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_4, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_5, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_6, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_7, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_8, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_9, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_10, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_11, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_12, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_13, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_14, nomCherche) ||
            !strcasecmp((ptrLivreAChercher+selection[i])->recueil_auteur_15, nomCherche)
           )
        {
            nbTrouve++;
            indiceTrouve[nbTrouve - 1] = selection[i];
        }
    }

    if(!nbTrouve)
    // pas de livre correspondant trouvé
    {
        printf("Aucun livre avec l'auteur %s trouve.\n", nomCherche);
    }
    else if(nbTrouve)
    {
        printf("\n%d ouvrages par l'auteur %s\n\n", nbTrouve, nomCherche);

        tri_chronologique(ptrLivreAChercher, indiceTrouve, nbTrouve);

        for(int i = 0; i < nbTrouve; i++)
        {
            affichage_selectif_simple(ptrLivreAChercher, indiceTrouve[i], i);
            selection[i] = indiceTrouve[i];
        }
    }
    else
    {
        printf("\n%d ouvrages par l'auteur %s\n", nbTrouve, nomCherche);
        printf("Pour afficher la liste complete utiliser le menu 0. \n\n");
    }
    return nbTrouve;
}

int rechercheParPeriode(Oeuvres* ptrLivreAChercher, int *selection, int nb_selectionne)
/* Fonction de recherche des noms d'ouvrage par periode */
{
    int date_min = 9999;
    int date_max = 0;
    int nbTrouve = 0;

    printf("\nRecherche entre deux dates \n");
    printf("Entrer la premiere date : ");
    scanf("%d", &date_min);

    printf("Entrer la deuxieme date : ");
    scanf("%d", &date_max);

    if(date_min <= date_max)
    {
        nbTrouve = recherche2Dates(ptrLivreAChercher, selection, nb_selectionne, date_min, date_max);
    }
    else
    {
        printf("Dates incoherentes : %d > %d \n", date_min, date_max);
    }



    return nbTrouve;
}


int rechercheAutourDuneDate(Oeuvres* ptrLivreAChercher, int *selection, int nb_selectionne)
/* Fonction de recherche des noms d'ouvrage autour d'une date */
{
    int ecart = 5;
    int date_min = 9999;
    int date_max = 0;
    int date_temp = 0;
    int nbTrouve = 0;

    printf("\nRecherche autour d'une date (+/- 5 ans) \n");
    scanf("%d", &date_temp);
    date_min = date_temp - ecart;
    date_max = date_temp + ecart;

    nbTrouve = recherche2Dates(ptrLivreAChercher, selection, nb_selectionne, date_min, date_max);

    return nbTrouve;
}

int recherche2Dates(Oeuvres* ptrLivreAChercher, int* selection, int nb_selectionne, int date_min, int date_max)
/* Fonction de recherche des noms d'ouvrage compris entre date_min et date_max */
{
    int nbTrouve = 0;
    int indiceTrouve[nb_selectionne];

    for(int i = 0; i < nb_selectionne; i++)
    {
        if(date_min
           <= ((int) strtol(((ptrLivreAChercher+selection[i])->annee), (char **)NULL, 10))
           && ((int) strtol(((ptrLivreAChercher+selection[i])->annee), (char **)NULL, 10))
           <= date_max)
        {
            nbTrouve++;
            indiceTrouve[nbTrouve - 1] = selection[i];
        }
    }
    if(!nbTrouve)
    // pas de livre correspondant trouvé
    {
        printf("Aucun livre trouve dans la plage de temps %d - %d.\n", date_min, date_max);
    }
    else if(nbTrouve < 15)
    {
        printf("\n%d ouvrages dans la plage de temps %d - %d\n\n", nbTrouve, date_min, date_max);

        tri_chronologique(ptrLivreAChercher, indiceTrouve, nbTrouve);

        for(int i = 0; i < nbTrouve; i++)
        {
            affichage_selectif_simple(ptrLivreAChercher, indiceTrouve[i], i);
            selection[i] = indiceTrouve[i];
        }
    }
    else
    {
        printf("\n%d ouvrages dans la plage de temps %d - %d\n", nbTrouve, date_min, date_max);
        printf("Pour afficher la liste complete utiliser le menu 0. \n\n");
    }

    return nbTrouve;
}

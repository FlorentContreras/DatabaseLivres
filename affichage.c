#include <stdio.h>
#include <stdlib.h>

#include "init.h"
#include "affichage.h"


void affichage(Oeuvres* ptr_livre_a_afficher, int nombre_oeuvres)
/* Affichage de la structure */

/* /!\  Incomplet par rapport à la dernière structure !!! /!\ */
{
    for(int i = 0; i < nombre_oeuvres; ++i)
    {
        printf("\n***** Oeuvre %d : ******\n", i+1);
        printf("Nom : %s \n", (ptr_livre_a_afficher+i)->auteur_1_nom);
        printf("Prenom 1 : %s \n", (ptr_livre_a_afficher+i)->auteur_1_prenom_1);
        printf("Prenom 2 : %s \n", (ptr_livre_a_afficher+i)->auteur_1_prenom_2);
        printf("Annee : %s\n", (ptr_livre_a_afficher+i)->annee);
        printf("Titre : %s\n", (ptr_livre_a_afficher+i)->titre);
        printf("Titre original : %s\n", (ptr_livre_a_afficher+i)->titre_original);
        printf("Possession : %s\n", (ptr_livre_a_afficher+i)->possession);
        printf("Qualite : %s\n", (ptr_livre_a_afficher+i)->qualite);
        printf("Domaine_1 : %s\n", (ptr_livre_a_afficher+i)->domaine_1);
        printf("Domaine_2 : %s\n", (ptr_livre_a_afficher+i)->domaine_2);
        printf("Mot_cles_1 : %s\n", (ptr_livre_a_afficher+i)->mot_cles_1);
        printf("Recueil_auteur_1 : %s\n", (ptr_livre_a_afficher+i)->recueil_auteur_1);
        printf("preface_auteur : %s\n", (ptr_livre_a_afficher+i)->preface_auteur);
    }
}

void affichage_selectif(Oeuvres* ptr_livre_a_afficher, int indice_a_afficher)
/* Affichage de la structure pour un seul ouvrage selectionné par son indice_a_afficher*/
{
    printf("Nom : %s \n", (ptr_livre_a_afficher+indice_a_afficher)->auteur_1_nom);
    printf("Prenom 1 : %s \n", (ptr_livre_a_afficher+indice_a_afficher)->auteur_1_prenom_1);
    printf("Prenom 2 : %s \n", (ptr_livre_a_afficher+indice_a_afficher)->auteur_1_prenom_2);
    printf("Annee : %s\n", (ptr_livre_a_afficher+indice_a_afficher)->annee);
    printf("Titre : %s\n", (ptr_livre_a_afficher+indice_a_afficher)->titre);
    printf("Titre original : %s\n", (ptr_livre_a_afficher+indice_a_afficher)->titre_original);
    printf("Possession : %s\n", (ptr_livre_a_afficher+indice_a_afficher)->possession);
    printf("Qualite : %s\n", (ptr_livre_a_afficher+indice_a_afficher)->qualite);

    printf("\n       ****      \n");
}

void affichage_selectif_simple(Oeuvres* ptr_livre_a_afficher, int indice_a_afficher, int indice)
/* Affichage de la structure pour un seul ouvrage selectionné par son indice_a_afficher*/
{
    indice ++;  // affichage de l'indice en commençant par 1

    alignement(indice);

    printf("%d : %s, %s, %s (%s)\n", indice,
                (ptr_livre_a_afficher+indice_a_afficher)->auteur_1_nom,
                (ptr_livre_a_afficher+indice_a_afficher)->auteur_1_prenom_1,
                (ptr_livre_a_afficher+indice_a_afficher)->titre,
                (ptr_livre_a_afficher+indice_a_afficher)->annee);
}

void affichage_selectif_detaille(Oeuvres* ptr_livre_a_afficher, int indice_a_afficher, int indice)
/* Affichage de la structure pour un seul ouvrage selectionné par son indice_a_afficher*/
{
    printf("\nDetails pour %d :\n\n", indice);
    printf("Nom : %s\n", (ptr_livre_a_afficher+indice_a_afficher)->auteur_1_nom);
    printf("Prenoms : %s %s %s\n",  (ptr_livre_a_afficher+indice_a_afficher)->auteur_1_prenom_1,
                                    (ptr_livre_a_afficher+indice_a_afficher)->auteur_1_prenom_2,
                                    (ptr_livre_a_afficher+indice_a_afficher)->auteur_1_prenom_3);

    if((ptr_livre_a_afficher+indice_a_afficher)->auteur_2_nom[0] != '\0')
    {
        printf("Nom : %s\n", (ptr_livre_a_afficher+indice_a_afficher)->auteur_2_nom);
        printf("Prenoms : %s %s %s\n",  (ptr_livre_a_afficher+indice_a_afficher)->auteur_2_prenom_1,
                                        (ptr_livre_a_afficher+indice_a_afficher)->auteur_2_prenom_2,
                                        (ptr_livre_a_afficher+indice_a_afficher)->auteur_2_prenom_3);
    }

    if((ptr_livre_a_afficher+indice_a_afficher)->auteur_3_nom[0] != '\0')
    {
        printf("Nom : %s\n", (ptr_livre_a_afficher+indice_a_afficher)->auteur_3_nom);
        printf("Prenoms : %s %s %s\n",  (ptr_livre_a_afficher+indice_a_afficher)->auteur_3_prenom_1,
                                        (ptr_livre_a_afficher+indice_a_afficher)->auteur_3_prenom_2,
                                        (ptr_livre_a_afficher+indice_a_afficher)->auteur_3_prenom_3);
    }

    if((ptr_livre_a_afficher+indice_a_afficher)->auteur_4_nom[0] != '\0')
    {
        printf("Nom : %s\n", (ptr_livre_a_afficher+indice_a_afficher)->auteur_4_nom);
        printf("Prenoms : %s %s %s\n",  (ptr_livre_a_afficher+indice_a_afficher)->auteur_4_prenom_1,
                                        (ptr_livre_a_afficher+indice_a_afficher)->auteur_4_prenom_2,
                                        (ptr_livre_a_afficher+indice_a_afficher)->auteur_4_prenom_3);
    }

    if((ptr_livre_a_afficher+indice_a_afficher)->auteur_5_nom[0] != '\0')
    {
        printf("Nom : %s\n", (ptr_livre_a_afficher+indice_a_afficher)->auteur_5_nom);
        printf("Prenoms : %s %s %s\n",  (ptr_livre_a_afficher+indice_a_afficher)->auteur_5_prenom_1,
                                        (ptr_livre_a_afficher+indice_a_afficher)->auteur_5_prenom_2,
                                        (ptr_livre_a_afficher+indice_a_afficher)->auteur_5_prenom_3);
    }


    printf("Titre : %s\n", (ptr_livre_a_afficher+indice_a_afficher)->titre);
    printf("Titre Original: %s\n", (ptr_livre_a_afficher+indice_a_afficher)->titre_original);
    printf("Date : %s %s",  (ptr_livre_a_afficher+indice_a_afficher)->mois,
                            (ptr_livre_a_afficher+indice_a_afficher)->annee);



}

void alignement(int indice)
/* Alignement des noms */
{
    if(indice < 10)
    {
        printf("    ");
    }
    else if(10 <= indice && indice < 100)
    {
        printf("   ");
    }
    else if(100 <= indice && indice < 1000)
    {
        printf(" ");
    }
    else if(1000 <= indice && indice < 10000)
    {
        printf(" ");
    }
}

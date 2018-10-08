#include <stdio.h>
#include <stdlib.h>

#include "main.h"

typedef struct
{
    char auteur_1_nom[taille_entrant];
    char auteur_1_prenom_1[taille_entrant];
    char auteur_1_prenom_2[taille_entrant];
    char auteur_1_prenom_3[taille_entrant];
    char auteur_2_nom[taille_entrant];
    char auteur_2_prenom_1[taille_entrant];
    char auteur_2_prenom_2[taille_entrant];
    char auteur_2_prenom_3[taille_entrant];
    char auteur_3_nom[taille_entrant];
    char auteur_3_prenom_1[taille_entrant];
    char auteur_3_prenom_2[taille_entrant];
    char auteur_3_prenom_3[taille_entrant];
    char auteur_4_nom[taille_entrant];
    char auteur_4_prenom_1[taille_entrant];
    char auteur_4_prenom_2[taille_entrant];
    char auteur_4_prenom_3[taille_entrant];
    char auteur_5_nom[taille_entrant];
    char auteur_5_prenom_1[taille_entrant];
    char auteur_5_prenom_2[taille_entrant];
    char auteur_5_prenom_3[taille_entrant];
    char annee[taille_entrant_court];
    char mois[taille_entrant_court];
    char nature[taille_entrant];
    char titre[taille_entrant_long];
    char titre_original[taille_entrant_long];
    char edition_annee[taille_entrant];
    char edition_num[taille_entrant_court];
    char volume_num1[taille_entrant_court];
    char volume_num2[taille_entrant_court];
    char langue_originale[taille_entrant];
    char langue_ouvrage[taille_entrant];
    char traducteur_1_nom[taille_entrant];
    char traducteur_1_prenom_1[taille_entrant];
    char traducteur_1_prenom_2[taille_entrant];
    char traducteur_2_nom[taille_entrant];
    char traducteur_2_prenom_1[taille_entrant];
    char traducteur_2_prenom_2[taille_entrant];
    char traducteur_3_nom[taille_entrant];
    char traducteur_3_prenom_1[taille_entrant];
    char traducteur_3_prenom_2[taille_entrant];
    char ville_de_publication[taille_entrant];
    char etat_de_publication[taille_entrant];
    char pays_de_publication[taille_entrant];
    char maison_d_edition[taille_entrant];
    char possession[taille_entrant_court];
    char possession_desiree[taille_entrant];
    char format[taille_entrant_court];
    char qualite[taille_entrant_court];
    char domaine_1[taille_entrant];
    char domaine_2[taille_entrant];
    char domaine_3[taille_entrant];
    char domaine_4[taille_entrant];
    char domaine_5[taille_entrant];
    char mot_cles_1[taille_entrant];
    char mot_cles_2[taille_entrant];
    char mot_cles_3[taille_entrant];
    char mot_cles_4[taille_entrant];
    char mot_cles_5[taille_entrant];
    char mot_cles_6[taille_entrant];
    char mot_cles_7[taille_entrant];
    char mot_cles_8[taille_entrant];
    char mot_cles_9[taille_entrant];
    char mot_cles_10[taille_entrant];
    char recueil_auteur_1[taille_entrant];
    char recueil_auteur_2[taille_entrant];
    char recueil_auteur_3[taille_entrant];
    char recueil_auteur_4[taille_entrant];
    char recueil_auteur_5[taille_entrant];
    char recueil_auteur_6[taille_entrant];
    char recueil_auteur_7[taille_entrant];
    char recueil_auteur_8[taille_entrant];
    char recueil_auteur_9[taille_entrant];
    char recueil_auteur_10[taille_entrant];
    char recueil_auteur_11[taille_entrant];
    char recueil_auteur_12[taille_entrant];
    char recueil_auteur_13[taille_entrant];
    char recueil_auteur_14[taille_entrant];
    char recueil_auteur_15[taille_entrant];
    char preface_auteur[taille_entrant];
    char pourcentage_lecture_Claire[taille_entrant_court];
    char pourcentage_etude_Claire[taille_entrant_court];
    char pourcentage_lecture_Florent[taille_entrant_court];
    char pourcentage_etude_Florent[taille_entrant_court];
    char Nombres_de_citations[taille_entrant_court];
    char emplacement_1[taille_entrant_long];
    char emplacement_2[taille_entrant_long];
} Oeuvres;

int remplissage_general(Oeuvres*);
int remplissage_champs_interne(Oeuvres*, int, char, int, int);
void version(FILE*);
void saut_premiere_ligne(FILE*);

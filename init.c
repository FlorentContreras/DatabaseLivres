#include <stdio.h>
#include <stdlib.h>

#include "init.h"

int remplissage_general(Oeuvres* ptr)
/* Fonction permettant de remplir la structure à partir de la DB */
{
    //ouvrir un fichier
    FILE* fichier = NULL;

    //ouverture du fichier
    fichier = fopen(nom_DB, "r+");

    int num_oeuvre = 0;
    if (fichier != NULL)
    {
        saut_premiere_ligne(fichier);



        int sortie = 0;
        while(!sortie)
        {
            int av_struct = 0;
            int mot = 0;
            int carac = 0;

            // On boucle sur le nombre d'oeuvres
            while(av_struct < nbChampsStruct)
            {
                // lecture d'un caractère
                char temp;
                fscanf(fichier, "%c", &temp);

                if(temp=='£')
                {
                    av_struct = nbChampsStruct;
                    sortie = 1;
                    version(fichier);   // appelle de la fonction permettant de récupérer la version de a DB et de l'affficher
                }
                else if(temp=='\n')
                {
                    // ne pas tenir compte de retour charriot de changement de ligne
                    num_oeuvre++;
                }
                else if(temp=='\r')
                {
                    // ne rien faire
                }
                else if(temp==';')      // detection de la séparation des mots par le ';'
                {
                    remplissage_champs_interne(ptr, num_oeuvre,'\0', carac, mot);    // on positionne un \0 à la suite des caractères
                    mot++;
                    carac = 0;
                    av_struct++ ;
                }
                else                    // on avance au caractère suivant
                {
                    remplissage_champs_interne(ptr, num_oeuvre, temp, carac, mot);
                    carac++;
                }
            }
        }
    }
    else
    {
        printf("Impossible de trouver ou d'ouvrir le fichier %s\n", nom_DB);
    }

    // fermeture du fichier
    fclose(fichier);

    printf("Nombre d'ouvrages actuel : %d\n", num_oeuvre);

    return num_oeuvre;
}

int remplissage_champs_interne(Oeuvres* ptr_livre_a_remplir, int oeuvre_en_cours ,char temp, int carac, int mot)
/* remplissage suivant l'avancement dans la structure */
{
    /* remplissage suivant l'avancement dans la structure */
    if(mot == 0)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_1_nom[carac] = temp;
    }
    else if(mot == 1)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_1_prenom_1[carac] = temp;
    }
    else if(mot == 2)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_1_prenom_2[carac] = temp;
    }
    else if(mot == 3)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_1_prenom_3[carac] = temp;
    }
    else if(mot == 4)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_2_nom[carac] = temp;
    }
    else if(mot == 5)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_2_prenom_1[carac] = temp;
    }
    else if(mot == 6)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_2_prenom_2[carac] = temp;
    }
    else if(mot == 7)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_2_prenom_3[carac] = temp;
    }
    else if(mot == 8)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_3_nom[carac] = temp;
    }
    else if(mot == 9)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_3_prenom_1[carac] = temp;
    }
    else if(mot == 10)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_3_prenom_2[carac] = temp;
    }
    else if(mot == 11)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_3_prenom_3[carac] = temp;
    }
    else if(mot == 12)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_4_nom[carac] = temp;
    }
    else if(mot == 13)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_4_prenom_1[carac] = temp;
    }
    else if(mot == 14)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_4_prenom_2[carac] = temp;
    }
    else if(mot == 15)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_4_prenom_3[carac] = temp;
    }
    else if(mot == 16)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_5_nom[carac] = temp;
    }
    else if(mot == 17)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_5_prenom_1[carac] = temp;
    }
    else if(mot == 18)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_5_prenom_2[carac] = temp;
    }
    else if(mot == 19)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->auteur_5_prenom_3[carac] = temp;
    }
    else if(mot == 20)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->annee[carac] = temp;
    }
    else if(mot == 21)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->mois[carac] = temp;
    }
    else if(mot == 22)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->nature[carac] = temp;
    }
    else if(mot == 23)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->titre[carac] = temp;
    }
    else if(mot == 24)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->titre_original[carac] = temp;
    }
    else if(mot == 25)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->edition_annee[carac] = temp;
    }
    else if(mot == 26)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->edition_num[carac] = temp;
    }
    else if(mot == 27)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->volume_num1[carac] = temp;
    }
    else if(mot == 28)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->volume_num2[carac] = temp;
    }
    else if(mot == 29)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->langue_originale[carac] = temp;
    }
    else if(mot == 30)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->langue_ouvrage[carac] = temp;
    }
    else if(mot == 31)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->traducteur_1_nom[carac] = temp;
    }
    else if(mot == 32)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->traducteur_1_prenom_1[carac] = temp;
    }
    else if(mot == 33)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->traducteur_1_prenom_2[carac] = temp;
    }
    else if(mot == 34)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->traducteur_2_nom[carac] = temp;
    }
    else if(mot == 35)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->traducteur_2_prenom_1[carac] = temp;
    }
    else if(mot == 36)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->traducteur_2_prenom_2[carac] = temp;
    }
    else if(mot == 37)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->traducteur_3_nom[carac] = temp;
    }
    else if(mot == 38)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->traducteur_3_prenom_1[carac] = temp;
    }
    else if(mot == 39)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->traducteur_3_prenom_2[carac] = temp;
    }
    else if(mot == 40)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->ville_de_publication[carac] = temp;
    }
    else if(mot == 41)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->etat_de_publication[carac] = temp;
    }
    else if(mot == 42)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->pays_de_publication[carac] = temp;
    }
    else if(mot == 43)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->maison_d_edition[carac] = temp;
    }
    else if(mot == 44)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->possession[carac] = temp;
    }
    else if(mot == 45)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->possession_desiree[carac] = temp;
    }
    else if(mot == 46)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->format[carac] = temp;
    }
    else if(mot == 47)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->qualite[carac] = temp;
    }
    else if(mot == 48)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->domaine_1[carac] = temp;
    }
    else if(mot == 49)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->domaine_2[carac] = temp;
    }
    else if(mot == 50)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->domaine_3[carac] = temp;
    }
    else if(mot == 51)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->domaine_4[carac] = temp;
    }
    else if(mot == 52)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->domaine_5[carac] = temp;
    }
    else if(mot == 53)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->mot_cles_1[carac] = temp;
    }
    else if(mot == 54)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->mot_cles_2[carac] = temp;
    }
    else if(mot == 55)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->mot_cles_3[carac] = temp;
    }
    else if(mot == 56)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->mot_cles_4[carac] = temp;
    }
    else if(mot == 57)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->mot_cles_5[carac] = temp;
    }
    else if(mot == 58)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->mot_cles_6[carac] = temp;
    }
    else if(mot == 59)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->mot_cles_7[carac] = temp;
    }
    else if(mot == 60)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->mot_cles_8[carac] = temp;
    }
    else if(mot == 61)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->mot_cles_9[carac] = temp;
    }
    else if(mot == 62)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->mot_cles_10[carac] = temp;
    }
    else if(mot == 63)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_1[carac] = temp;
    }
    else if(mot == 64)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_2[carac] = temp;
    }
    else if(mot == 65)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_3[carac] = temp;
    }
    else if(mot == 66)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_4[carac] = temp;
    }
    else if(mot == 67)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_5[carac] = temp;
    }
    else if(mot == 68)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_6[carac] = temp;
    }
    else if(mot == 69)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_7[carac] = temp;
    }
    else if(mot == 70)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_8[carac] = temp;
    }
    else if(mot == 71)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_9[carac] = temp;
    }
    else if(mot == 72)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_10[carac] = temp;
    }
    else if(mot == 73)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_11[carac] = temp;
    }
    else if(mot == 74)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_12[carac] = temp;
    }
    else if(mot == 75)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_13[carac] = temp;
    }
    else if(mot == 76)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_14[carac] = temp;
    }
    else if(mot == 77)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->recueil_auteur_15[carac] = temp;
    }
    else if(mot == 78)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->preface_auteur[carac] = temp;
    }
    else if(mot == 79)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->pourcentage_lecture_Claire[carac] = temp;
    }
    else if(mot == 80)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->pourcentage_etude_Claire[carac] = temp;
    }
    else if(mot == 81)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->pourcentage_lecture_Florent[carac] = temp;
    }
    else if(mot == 82)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->pourcentage_etude_Florent[carac] = temp;
    }
    else if(mot == 83)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->Nombres_de_citations[carac] = temp;
    }
    else if(mot == 84)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->emplacement_1[carac] = temp;
    }
    else if(mot == 85)
    {
        (ptr_livre_a_remplir+oeuvre_en_cours)->emplacement_2[carac] = temp;
    }
    else if(mot >= nbChampsStruct)
    {
        printf("Au dela de la structure : %d\n", mot);
    }
    else
    {
        printf("Mot incompris : %d\n", mot);
    }

    return 0;
}

void version(FILE* fichier)
/* Permet de récupérer la date de la DB, et d'afficher la version du logiciel + de la DB*/
{
    char temp;
    int taille_date = 11;
    char date[taille_date];
    int erreur_date_DB = 0;

    for(int i = 0; i < nbChampsStruct; i++)
    // on se décalle à la fin des ;, au dela de la taille de la structure
    {
        fscanf(fichier, "%c", &temp);
    }

    for(int i = 0; i < taille_date - 1; i++)
    // recuperation de la date
    {
        fscanf(fichier, "%c", &temp);

        if(temp == '\n')            // en cas de date absente
        {
            erreur_date_DB = 1;
        }
        else
        {
            date[i] = temp;
        }
    }
    date[taille_date - 1] = '\0';   //ajout eof pour terminer le string

    if(!erreur_date_DB)
    {
        printf("Version du logiciel : %s \nDerniere mise a jour de la DataBase : %s\n", _version, date);
    }
    else
    {
        printf("Version du logiciel : %s \n/!\\ Impossible de trouver la date de mise a jour de la DataBase /!\\ \n", _version);
    }
}

void saut_premiere_ligne(FILE* fichier)
/* Permet de parcourir la première ligne du fichier sans l'interpreter (titres)*/
{
    int fin_de_ligne = 0;
    while(!fin_de_ligne)
    {
        // lecture d'un caractère
        char temp;
        fscanf(fichier, "%c", &temp);
        if(temp == '\n')
        {
            fin_de_ligne = 1;
        }
    }
}



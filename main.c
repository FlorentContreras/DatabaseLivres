#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "init.h"
#include "affichage.h"
#include "menu.h"
#include "recherche.h"


int main()
{
    Oeuvres* ptr_livres;
    int nombre_d_oeuvres = 50000;   // init de nombre large, ramené au nombre d'oeuvres réelles ensuite

    ptr_livres = (Oeuvres*) malloc(nombre_d_oeuvres * sizeof(Oeuvres));

    //remplissage de la structure par le fichier DB
    nombre_d_oeuvres = remplissage_general(ptr_livres);

    //affichage(ptr_livres, nombre_d_oeuvres);

    // Appel de la fonction gérant les menus
    choix_menu_principal(ptr_livres, nombre_d_oeuvres);

    // libération de la mémoire
    free(ptr_livres);
    printf("\n\n");

    return 0;
}






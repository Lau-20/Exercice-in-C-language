/*
--------------------------------------
Nom      : FILET
Prenom   : LAURA
Classe   : 3PSC
Groupe   : 2
Seance   : 2
Exercice : Maison
Version  : 1 
Date     : 04/02/2024
--------------------------------------
*/

#include <stdio.h>
#include <string.h>
#define nmax 50
#define nbnotemax 3
#define notemaxi 20

//--------------------------------
//          Structure
//--------------------------------

typedef struct Etudiant Etudiant;
struct Etudiant
{
    char prenom[30];
    char nom[30];
    int notes[nbnotemax+1];
    float moyenne;

};

//--------------------------------
//      Programme principal
//--------------------------------

exo_maison(){
    int n_etudiant, i, n, somme, rep;
    float moyenne; 

    printf("\n------------------------------");
    printf("\n      Exercice Maison ");
    printf("\n------------------------------");

    do {
        // ---------- saisir nombre d'etudiant -------------
        do {
        printf("\nNombre d'etudiant : ");
        scanf("%d", &n_etudiant);
        } while (n_etudiant<= 0 || n_etudiant > nmax); 
        //nombre compris entre 0 et un nombre prédéfinie 

        Etudiant etudiant[n_etudiant]; //utilisation d'une structure

        // ------- saisir les coordonnees etudiant ----------
        for (i = 0; i < n_etudiant; i++){

            printf("\n\nNom : ");
            scanf("%s", &etudiant[i].nom);
            printf("\nPrenom : ");
            scanf("%s", &etudiant[i].prenom);

            somme = 0;
            for (n = 1; n < nbnotemax+1 ; n++){
                do {
                printf("\nNote %d : ", n);
                scanf("%d", &etudiant[i].notes[n]);
                } while(etudiant[i].notes[n]< 0 || etudiant[i].notes[n]> notemaxi);
                // valeur des notes comprise entre 0 et la note maximale possible

                somme = somme + etudiant[i].notes[n];
            }
            // ----------- calcul de la moyenne --------------
            etudiant[i].moyenne = (float)somme / nbnotemax;   
        }

        printf("\n------------------------------");
        printf("\n  Recapitulatif de la saisie ");
        printf("\n------------------------------");
        
        // --------- affichage des donnees saisies -----------
        for (i = 0; i < n_etudiant; i++){
            printf("\nEtudiant numéro : %d", i);
            printf("\nNom : %s", etudiant[i].nom);
            printf("\nPrenom : %s", etudiant[i].prenom);
            printf("\nNotes :");
            for (n = 1; n < nbnotemax+1; n++){
                printf(" %d /", etudiant[i].notes[n]);
            }
            printf("\nmoyenne : %.2f\n", etudiant[i].moyenne);
        }
        printf("\nVous avez enregistre %d etudiants.", n_etudiant);

        // ------------------ restart ------------------------
        do {
            printf("\n\nVoulez-vous recommencer ? \n(1 : oui    0 : non )\n");
            scanf("%d", &rep);
            } while(rep != 1 && rep != 0);
    } while(rep == 1);
    
    printf("\nMerci à bientot !");
    printf("\n \n");
}
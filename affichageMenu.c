#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "affichageMenu.h"
#define B CouleurParNom("white")
#define N CouleurParNom("black")

/*Menu*/
void initialisation_fenetre (){
  InitialiserGraphique();
  CreerFenetre(50,50,1440,780);
  ChargerImageFond("images/Fondecran.jpg");
  ChoisirCouleurDessin(B);
  EcrireTexte(625,95,"Jeu de paire",2);
}

void revenir_menu(){
  ChargerImageFond("images/Fondecran.jpg");
  ChoisirCouleurDessin(B);
  EcrireTexte(625,95,"Jeu de paire",2);
}

/*Bouton*/
void affichage_bouton_jouer(){
  ChoisirCouleurDessin(B);
  RemplirRectangle(620,560,200,40);
  ChoisirCouleurDessin(N);
  EcrireTexte(692,587,"Jouer",1);
}

void affichage_bouton_quitter(){
  ChoisirCouleurDessin(B);
  RemplirRectangle(620,630,200,40);
  ChoisirCouleurDessin(N);
  EcrireTexte(692,657,"Quitter",1);
}

/*Gestion des clics*/
int clique_bouton_jouer(){
  return (_X>=620 && _X<=820 && _Y>=560 && _Y<=600);
}

int clique_bouton_quitter(){
  return (_X>=620 && _X<=820 && _Y>=630 && _Y<=670);
}


/*Affichage*/

void affichage_fenetre_menu_principal(){
  initialisation_fenetre();
  affichage_bouton_jouer();
  affichage_bouton_quitter();
}

void retour_menu(){
  revenir_menu();
  affichage_bouton_jouer();
  affichage_bouton_quitter();
}
  
  


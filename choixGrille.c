#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "choixGrille.h"
#define B CouleurParNom("white")
#define N CouleurParNom("black")

void affichage_fenetre_difficulte (){
  ChargerImageFond("images/Fondecran.jpg");
  ChoisirCouleurDessin(B);
  EcrireTexte(120,95,"Selection de la difficulte :",1);
}

/*Bouton*/
void difficulte_facile(){
  ChoisirCouleurDessin(N);
  RemplirRectangle(173,198,254,304);
  ChargerImage("images/Facile.png",175,200,0,0,250,300);
  ChoisirCouleurDessin(B);
  EcrireTexte(250,525,"Facile (4x4)",1);
}

void difficulte_moyenne(){
  ChoisirCouleurDessin(N);
  RemplirRectangle(598,198,254,304);
  ChargerImage("images/Moyen.png",600,200,0,0,250,300);
  ChoisirCouleurDessin(B);
  EcrireTexte(675,525,"Moyen (6x6)",1);
}

void difficulte_difficile(){
  ChoisirCouleurDessin(N);
  RemplirRectangle(1023,198,254,304);
  ChargerImage("images/Difficile.png",1025,200,0,0,250,300);
  ChoisirCouleurDessin(B);
  EcrireTexte(1100,525,"Difficile (8x8)",1);
}

void bouton_annuler(){
  ChoisirCouleurDessin(B);
  RemplirRectangle(620,630,200,40);
  ChoisirCouleurDessin(N);
  EcrireTexte(685,657,"Annuler",1);
}
  
/*Gestion clic*/
int clique_bouton_facile(){
  return (_X>=173 && _X<=427 && _Y>=198 && _Y<=502);
}

int clique_bouton_moyen(){
  return (_X>=598 && _X<=852 && _Y>=198 && _Y<=502);
}

int clique_bouton_difficile(){
  return (_X>=1023 && _X<=1277 && _Y>=198 && _Y<=502);
}

int clique_bouton_annuler(){
  return (_X>=620 && _X<=820 && _Y>=630 && _Y<=670);
}


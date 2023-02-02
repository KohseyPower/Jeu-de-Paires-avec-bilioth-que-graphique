#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "choixGrille.h"
#include "affichageMenu.h"
#include "menu.h"
#define b CouleurParNom("white")
#define n CouleurParNom("black")


int choix (){
  int TailleJeu = -2;
  affichage_fenetre_difficulte();
  difficulte_facile();
  difficulte_moyenne();
  difficulte_difficile();
  bouton_annuler();
  while(1) {
    SourisPosition();
    if(SourisCliquee()) {
      if (clique_bouton_annuler()) {
	       retour_menu();
	       break;
      }
      else if (clique_bouton_facile()){
	      TailleJeu = 4;
	      return TailleJeu;
      }
      else if (clique_bouton_moyen()){
	      TailleJeu = 6;
	      return TailleJeu;
      }
      else if (clique_bouton_difficile()){
	      TailleJeu = 8;
	      return TailleJeu;
      }
    }
  }
  return TailleJeu;
}

int menu_principal(){
	int Taille = -1;
	affichage_fenetre_menu_principal();
	while(1) {
		SourisPosition();
		if(SourisCliquee()) {
			if (clique_bouton_jouer()){
				Taille = choix();
				if(Taille>0){
					break;
				}
			} else if (clique_bouton_quitter()) { 
				return Taille;
				FermerGraphique();
			}
		}
		if (Taille>0){
			return Taille;
		}
	}
}

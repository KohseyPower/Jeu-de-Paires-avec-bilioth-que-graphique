#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <graph.h>
#include "squelette.h"
#include "jeuGraphique.h"
#include "jeuDePaires.h"
#include "affichageMenu.h"
#include "timer.h"


#define b CouleurParNom("white")
#define n CouleurParNom("black")
#define r CouleurParNom("red")


void afficher_cartes(Carte* tab, int T, int emplacementCarteX, int emplacementCarteY, int coteCarte){
	int i, j, tmpEmplacementCarteX = emplacementCarteX;
  	char idString[20];
  	for(i=0;i<T;i++){
  		emplacementCarteX = tmpEmplacementCarteX;
  		for(j=0;j<T;j++){
   	  		if(tab[i*T+j].visibilite == 0){
				if(T==4){
					sprintf(idString,"images/Facile/%d.png" ,tab[i*T+j].id);
				}else if(T==6){
					sprintf(idString,"images/Moyen/%d.png" ,tab[i*T+j].id);
				}else{	
					sprintf(idString,"images/Difficile/%d.png" ,tab[i*T+j].id);
				}
      				ChargerImage(idString, emplacementCarteX+1,emplacementCarteY+1,0,0,140,140);
     			}else{
				if(T==4){
					ChargerImage("images/ballon139.jpg",emplacementCarteX+1,emplacementCarteY+1,0,0,140,140);
				}
				else if(T==6){ 
					ChargerImage("images/ballon90.jpg",emplacementCarteX+1,emplacementCarteY+1,0,0,91,91);
				}
				else {
					ChargerImage("images/ballon78.jpg",emplacementCarteX+1,emplacementCarteY+1,0,0,79,79);
				}
      			}
      			emplacementCarteX = emplacementCarteX + coteCarte + 6;
    		}
    		emplacementCarteY = emplacementCarteY + coteCarte + 6;
  	}
}


void mode_tricheur(Carte* tab, int T, int emplacementCarteX, int emplacementCarteY, int coteCarte, unsigned long int debut){
	int i, j, tmpEmplacementCarteX = emplacementCarteX, tmpEmplacementCarteY = emplacementCarteY;
  	char idString[20];
	Carte* tmpTab = tab;
	/* affichage de toutes les cartes */
      	ChoisirCouleurDessin(r);
	for(i=0;i<T;i++){
    		emplacementCarteX = tmpEmplacementCarteX;
   		for(j=0;j<T;j++){
			if(T==4){
				sprintf(idString,"images/Facile/%d.png" ,tab[i*T+j].id);
			}else if(T==6){
				sprintf(idString,"images/Moyen/%d.png" ,tab[i*T+j].id);
			}else{	
				sprintf(idString,"images/Difficile/%d.png" ,tab[i*T+j].id);
			}
      			ChargerImage(idString, emplacementCarteX+1,emplacementCarteY+1,0,0,140,140);
      			emplacementCarteX = emplacementCarteX + coteCarte + 6;
		}
    		emplacementCarteY = emplacementCarteY + coteCarte + 6;
	}
	/* Desaffichage de toutes les cartes */
	emplacementCarteX = tmpEmplacementCarteX;
	emplacementCarteY = tmpEmplacementCarteY;
	ChoisirCouleurDessin(b);
	while(1){
		if(ToucheEnAttente()){
			if(Touche()==XK_t){
				afficher_cartes(tab, T, emplacementCarteX, emplacementCarteY, coteCarte);	
				break;
			}
		}
	}
		mise_a_jour_time(debut);
}

void jeu(int TailleJeu){
  /* affichageMain.c */
  /*fonction qui nous donne la difficulté à faire*/
  int positionCarteCliquee, emplacementCarteX, emplacementCarteY, coteCarte = 80, positionTableauPremiereCarte, positionTableauDeuxiemeCarte, T = TailleJeu, paire;
  unsigned long int debut = 0;
  int* tableauTmpIds = malloc(T*T*sizeof(int));
  Carte* tableauCartes = malloc(T*T*sizeof(Carte));
  srand(time(NULL));

  /* Initialisation */
  initialiser_visibilite(tableauCartes, T);
  /* Generation des ids par paire dans un tableau tampon voir algo de Knuth */
  generation_ids(tableauTmpIds,T);
  /* Affectation dans le tableauCartes des ids par paire */
  affectation_aleatoire_position(tableauCartes, tableauTmpIds, T);
  free(tableauTmpIds);
  /*evenement.c */
  affichage_fenetre();
  /* Redimensionne les Cartes pour les petits jeux de cartes */
  redimensionner(T, &emplacementCarteX, &emplacementCarteY, &coteCarte);
  /* Generation Grephique du Tableau*/
  generation_tableau(T, emplacementCarteX, emplacementCarteY, coteCarte);
  /*Commencer chrono */
  debut = commencer_time(debut);
  /* Boucle While principale du jeu */
  while(gagnant(tableauCartes, T)){
    mise_a_jour_time(debut);
    do{
      mise_a_jour_time(debut);
      afficher_cartes(tableauCartes, T, emplacementCarteX, emplacementCarteY, coteCarte);
      positionTableauPremiereCarte = sur_quelle_carte_est_le_clique(T, coteCarte, emplacementCarteX, emplacementCarteY, debut);
      if(positionTableauPremiereCarte == -2){
        debut = arreter_time(debut);	
	mode_tricheur(tableauCartes,T,emplacementCarteX,emplacementCarteY,coteCarte,debut);
        debut = commencer_time(debut);
      }
    }while(deja_retournee(T, tableauCartes, positionTableauPremiereCarte) || positionTableauPremiereCarte <=-1);
    
    /* Retourner la carte */
    
    retourne_carte_face(tableauCartes, positionTableauPremiereCarte);
    afficher_cartes(tableauCartes, T, emplacementCarteX, emplacementCarteY, coteCarte);
    /* SurQuelleCarteEstLeClique */
    do{
      mise_a_jour_time(debut);
      positionTableauDeuxiemeCarte = sur_quelle_carte_est_le_clique(T, coteCarte, emplacementCarteX, emplacementCarteY, debut);
      if(positionTableauDeuxiemeCarte == -2){
        debut = arreter_time(debut);	
	mode_tricheur(tableauCartes,T,emplacementCarteX,emplacementCarteY,coteCarte,debut);
        debut = commencer_time(debut);
      }
    }while(deja_retournee(T, tableauCartes, positionTableauDeuxiemeCarte) || positionTableauDeuxiemeCarte <=-1);
    retourne_carte_face(tableauCartes, positionTableauDeuxiemeCarte);
    afficher_cartes(tableauCartes, T, emplacementCarteX, emplacementCarteY, coteCarte);
    /* Comparer, renvoie 0 si c'est une paire, 1 si c'est une paire*/
    paire = est_ce_une_paire(tableauCartes, positionTableauPremiereCarte, positionTableauDeuxiemeCarte);
    /* Temporiser 1 seconde */
    if(paire == 1) {
	temps_de_memorisation(debut);
    }
    /* Si clique en attente, alors s'en débarrasser*/
    cliques_accumulees();
    afficher_cartes(tableauCartes, T, emplacementCarteX, emplacementCarteY, coteCarte);
    /*Si c'est pas la meme, retourner les deux dernière carte, sinon laisser*/
  }
  debut = arreter_time(debut);
  free(tableauCartes);
  ecran_fin();
}

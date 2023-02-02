#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "jeuGraphique.h"
#include "timer.h"
#define b CouleurParNom("white")
#define n CouleurParNom("black")
#define r CouleurParNom("red")
#define CYCLE 10000L


void affichage_fenetre (){
  ChargerImageFond("images/Fondecran.jpg");
}


void ecran_fin(){
	char message[] = "Vous avez gagne !";
	ChoisirCouleurDessin(b);
	RemplirRectangle(400,215,640,420);
	ChoisirCouleurDessin(n);
	DessinerRectangle(400,215,640,420);
	EcrireTexte(580, 350,message,2);
	ChargerImage("images/victoire.jpeg",607,380,0,0,225,126);
	EcrireTexte(535,600,"Appuyer sur esc pour quitter",2);
	clique_echap_quitter();
}

void clique_echap_quitter(){
	while (1){
    		if (ToucheEnAttente()){
			if(Touche()==XK_Escape){
				break;
			}
  		}
  	}
  FermerGraphique();
}

/* Genere un tableau avec les cartes du jeu en fonction de la taille */
int generation_tableau(int T, int emplacementCarteX, int emplacementCarteY, int coteCarte){
	/* Une carte mesure **px de cote et l'espace entre chaque carte **px*/
	int i, j;
	ChoisirCouleurDessin(n);	
		 
	/* Affichage du des cartes*/
	for(i=0;i<T;i++){
		for(j=0;j<T;j++){
			DessinerRectangle(emplacementCarteX + i*(coteCarte+6) , emplacementCarteY +j*(coteCarte+6) , coteCarte, coteCarte);
		}
	}
	
}

int sur_quelle_carte_est_le_clique(int T, int coteCarte, int emplacementCarteX, int emplacementCarteY, unsigned long int debut){
	int i=1, j=1, carteClique = 1, emplacementCarteXTmp = emplacementCarteX;
	ChoisirCouleurDessin(r);/*
	printf("coteCarte: %d",coteCarte);*/
	while(carteClique){
		mise_a_jour_time(debut);
		if(!SourisCliquee()){
			if(ToucheEnAttente()){
				if(Touche()==XK_t){
					return -2;
				}
			}	
		}else{
			for(i=1;i<=T;i++){
				for(j=1;j<=T;j++){
					if(_X>=emplacementCarteX && _X<=emplacementCarteX+coteCarte && _Y>=emplacementCarteY && _Y<=emplacementCarteY+coteCarte){
						/*printf("minX=%d , minY=%d, _X=%d, _Y=%d, maxX=%d, minY=%d \n",emplacementCarteX, emplacementCarteY, _X, _Y, emplacementCarteX+coteCarte, emplacementCarteY+coteCarte);*/
						/*DessinerRectangle(emplacementCarteX, emplacementCarteY, coteCarte, coteCarte);*/
						return j-1+T*(i-1);
						/*
						carteClique = 0;
						i=T+1;
						break;
						*/
					}
					emplacementCarteX = emplacementCarteX+coteCarte+6;
				}
				emplacementCarteX = emplacementCarteXTmp;
			emplacementCarteY = emplacementCarteY + coteCarte+6;
			}
		return -1;
		}
	}
}

void temps_de_memorisation(unsigned long int debut){
  unsigned long int start = Microsecondes(), seconde;
  unsigned int a = 0;
  while(1){
    mise_a_jour_time(debut);
    seconde =((Microsecondes() - start) /1000000)-a;
    if (seconde>=1 || ToucheEnAttente()){
      break;
    }
  }

}

void redimensionner(int T, int* curseurX, int* curseurY, int* longueurCarte){
	int tmpLongueurCarte = *longueurCarte;
	*curseurY = 390-T*(tmpLongueurCarte+6)/2+3;
 	while(*curseurY>100){
    	tmpLongueurCarte++;
	*curseurY = 390-T*(tmpLongueurCarte+6)/2+3;
  	}
  	*curseurX = 720-T*(tmpLongueurCarte+6)/2+3;
	*longueurCarte = tmpLongueurCarte;
}

void cliques_accumulees(){
	while(1){
		if(SourisCliquee()){
			cliques_accumulees();
		}else{
			break;
		}
	}
}


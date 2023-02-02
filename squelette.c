#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "squelette.h"
#define NB_CARTES_UNIQUES 32
#define N 64


void initialiser_visibilite(Carte* tab, int T){
	int i;
	/* Les cartes sont retournées, càd tableauCartes[i].visibilite==1 */
	for(i=0;i<T*T;i++){
		tab[i].visibilite = 1;
	}

}

void generation_ids(int* tab, int T){
	int i, im=0, randomG, randomCartesRestantes;
	for(i=0;i<NB_CARTES_UNIQUES && im < T*T/2;i++){
		randomG = NB_CARTES_UNIQUES - i;
		randomCartesRestantes = T*T/2 - im;

		if(rand()%randomG<randomCartesRestantes){
			tab[im] = i + 1;
			tab[T*T/2+im] = i + 1;
			im++;	
		}
	}
}

void affectation_aleatoire_position(Carte* tableauCartes,int*  tableauTmpIds, int T){
	int j, randomPosition;
	for(j=0;j<T*T;j++){
		randomPosition = rand()%(T*T);
		while(1){
			if(tableauTmpIds[randomPosition] != -1){
				tableauCartes[j].id = tableauTmpIds[randomPosition];
				tableauTmpIds[randomPosition] = -1;
				break;
			} else {
				randomPosition = rand()%(T*T);
			}
		}
	}
}
	
/* Affichage dans le terminal des ids de chaque carte du tableau, fonction qui a été utilisée pour vérifier la génération des ids*/
void affichage_ids(Carte* tab, int T){
	int i, j;

	for(j=0;j<T;j++){
		for (i=0;i<T;i++) {
			printf("+------");
		}
			
		printf("+\n");
		for(i=0;i<T;i++) {
			printf("| %3d  ", tab[j*T+i].id);
		
		}
		printf("|\n");
	}
	for (i=0;i<T;i++) {
		printf("+------");
	}
	printf("+\n");
}

/* Affichage dans le terminal de la visibilite de chaque carte du tableau, fonction qui a été utilisée pour vérifier le bon retournement de carte*/
void affichage_visibilite(Carte* tab, int T){
	int i, j;

	for(j=0;j<T;j++){
		for (i=0;i<T;i++) {
			printf("+------");
		}
			
		printf("+\n");
		for(i=0;i<T;i++) {
			printf("| %3d  ", tab[j*T+i].visibilite);
		
		}
		printf("|\n");
	}
	for (i=0;i<T;i++) {
		printf("+------");
	}
	printf("+\n");
}

int deja_retournee(int T, Carte* tab, int pos){
	if(tab[pos].visibilite == 0){
		return 1;
	}
	return 0;
}

void retourne_carte_face(Carte* tab, int pos){
	tab[pos].visibilite = 0;
}

int est_ce_une_paire(Carte* tab, int posPremiereCarte, int posSecondeCarte){
  if(tab[posPremiereCarte].id != tab[posSecondeCarte].id || posPremiereCarte == posSecondeCarte){
    tab[posPremiereCarte].visibilite = 1;
    tab[posSecondeCarte].visibilite = 1;
    return 1;
  }else{
    return 0;
  }
}

int gagnant(Carte* tab, int T){
	int i;
	for(i=0;i<T*T;i++){
		if(tab[i].visibilite == 1){
			return 1;
		}
  	}
	return 0;
}

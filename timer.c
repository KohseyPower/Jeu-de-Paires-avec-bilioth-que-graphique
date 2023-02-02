#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "timer.h"
#define DELTA 1000L
#define N CouleurParNom("black")
#define B CouleurParNom("white")
#define R CouleurParComposante(165,38,10)

/* Initialisation image de fond de timer*/


void mise_a_jour_time(unsigned long int start){
	unsigned int millisecondes  = ((Microsecondes()-start)/DELTA), minutes = 0, secondes = 0;
	char chrono[80];
	while (millisecondes>=1000){
		secondes++;
		millisecondes -=1000;
		while(secondes>=60){
			minutes++;
			secondes -=60;
		}
	}

	ChoisirEcran(1);
	EffacerEcran(R);
	ChoisirCouleurDessin(B);
	sprintf(chrono, "%02d:%02d,%03d", minutes, secondes, millisecondes);
	EcrireTexte(20, 20, chrono, 1);
	CopierZone(1, 0, 0, 0, 120, 30, 660, 0);
	ChoisirEcran(0);
}

unsigned long int commencer_time(unsigned long int start){
	start = Microsecondes()-start;
	mise_a_jour_time(start);
	return start;
}

unsigned long int arreter_time(unsigned long int start){
	return Microsecondes()-start;
}


				
  

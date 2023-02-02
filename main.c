#include "jeuDePaires.h"
#include "menu.h"
#define BLANC CouleurParNom("white")

int main (void){
	int T=-1;
	T = menu_principal();
	while (T>0){
		EffacerEcran(BLANC);
		jeu(T);
		return 0;
	}
	return 0;
}

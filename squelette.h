#ifndef squelette 
#define squelette 

typedef struct {
	int id;
	int visibilite;
} Carte;

void initialiser_visibilite(Carte* tab, int T);
void generation_ids(int* tab, int T);
void affectation_aleatoire_position(Carte* tableauCartes,int*  tableauTmpIds, int T);
void affichage_ids(Carte* tab, int T);
void affichage_visibilite(Carte* tab, int T);
int deja_retournee(int T, Carte* tab, int pos);
void retourne_carte_face(Carte* tab, int pos);
int est_ce_une_paire(Carte* tab, int posPremiereCarte, int posSecondeCarte);
int gagnant(Carte* tab, int T);

#endif

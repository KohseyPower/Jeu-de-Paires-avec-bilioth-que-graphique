#ifndef jeuGraphique
#define jeuGraphique

void affichage_fenetre();
void ecran_fin();
void clique_echap_quitter();
int generation_tableau(int T, int emplacementCarteX, int emplacementCarteY, int coteCarte);
int sur_quelle_carte_est_le_clique(int T, int coteCarte, int emplacementCarteX, int emplacementCarteY, unsigned long int debut);
void temps_de_memorisation(unsigned long int debut);
void redimensionner(int T, int* curseurX, int* curseurY, int* longueurCarte);
void cliques_accumulees();


#endif

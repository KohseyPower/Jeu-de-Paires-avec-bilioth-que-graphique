# fichier Makefile
# CHAPITRE 1 : BUT FINAL

but : run

# CHAPITRE 2 : VARIABLES

OFILES = affichageMenu.o \
	 choixGrille.o \
         menu.o \
	 squelette.o \
         jeuGraphique.o \
	 timer.o \
	 jeuDePaires.o \
	 main.o
CC = gcc

CFLAGS = -ansi -pedantic -g

LDLIBS = -lgraph

# CHAPITRE 3 : DEPENDANCES (REGLES IMPLICITES)

affichageMenu.o : affichageMenu.h

choixGrille.o : choixGrille.h

menu.o : affichageMenu.h choixGrille.h

squelette.o : squelette.h

jeuGraphique.o : jeuGraphique.h

timer.o : timer.h

jeuDePaires.o : squelette.h jeuGraphique.h timer.h

main.o : menu.h jeuDePaires.h

run : $(OFILES)
	$(CC) $(CFLAGS) -o run $(OFILES) $(LDLIBS)

#CHAPITRE 5 : NETTOYAGE DES FICHIERS GENERES

clean :
	-rm -f $(OFILES) run

#CHAPITRE 6 : BUTS FACTICES

.PHONY : but clean



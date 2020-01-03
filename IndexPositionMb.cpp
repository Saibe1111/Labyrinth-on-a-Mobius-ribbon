
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Tab2D.h"
#include "Liste.h"
#include "Chaine.h"
#include "IndexPositionMb.h"
void listecreat(Liste& pos) {
	initialiser(pos);
}
void conex(int ligne, int colone, int face, Liste& posl, Liste& posc, Liste& posf) {
	
	while (longueur(posf) != 0 && !testconex(ligne, colone, face, posl, posc, posf)) {
		supprimer(posf, 0);
		supprimer(posl, 0);
		supprimer(posc, 0);
	}
	inserer(posf, 0, face);
	inserer(posl, 0, ligne);
	inserer(posc, 0, colone);
	//Tant que(!estVide(filAriane) et !Connexe(fileAriane[0], C))
	//for (unsigned int i = 0; i < longueur(posf); ++i)
		//cout << (lire(posf, i)) << endl;
	
}
void destru(Liste& posl, Liste& posc, Liste& posf) {
	detruire(posf);
	detruire(posc);
	detruire(posl);
}
// ouest (x-1, y), sud-ouest(x-1, y+1), sud (x, y+1), sud-est (x+1, y+1),
// est (x+1, y), nord-est (x+1, y-1), nord (x, y-1) et nord-ouest(x-1, y-1)
bool testconex(int ligne, int colone, int face, Liste& posl, Liste& posc, Liste& posf){
	if (lire(posl,0) == ligne-1 && lire(posc, 0) == colone) {// ouest (x-1, y)
		return true;
	}
	else if (lire(posl, 0) == ligne - 1 && lire(posc, 0) == colone + 1) {//sud-ouest(x-1, y+1)
		return true;
	}
	else if (lire(posl, 0) == ligne && lire(posc, 0) == colone + 1) {// sud(x, y + 1)
		return true;
	}
	else if (lire(posl, 0) == ligne + 1 && lire(posc, 0) == colone + 1) {//sud-est (x+1, y+1)
		return true;
	}
	else if (lire(posl, 0) == ligne + 1 && lire(posc, 0) == colone) {//est (x+1, y)
		return true;
	}
	else if (lire(posl, 0) == ligne + 1 && lire(posc, 0) == colone - 1) {//nord-est (x+1, y-1)
		return true;
	}
	else if (lire(posl, 0) == ligne && lire(posc, 0) == colone - 1) {// nord (x, y-1)
		return true;
	}
	else if (lire(posl, 0) == ligne - 1 && lire(posc, 0) == colone - 1) {//nord-ouest(x-1, y-1)
		return true;
	}
	else {
		return false;
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "IndexPositionMb.h"
void listecreat(Liste& pos) {
	initialiser(pos);
}
void conex(int ligne, int colone, int face, Liste& posl, Liste& posc, Liste& posf, Tab2D& tab) {
	
	while (longueur(posf) != 0 && !testconex(ligne, colone, face, posl, posc, posf, tab)) {
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
void afficlist(Liste& posl, Liste& posc, Liste& posf, Tab2D& tab1, Tab2D& tab2) {
	for (int i = 0; i < longueur(posl); i++) {
		//cout << "(" << lire(posl, i) << "," << lire(posc, i) << "," << lire(posf, i) << ")" << endl;
		
		if (lire(posf, i) == 1){
		tab1.tab[lire(posc, i)][lire(posl, i)] = 'C';
		}
		if (lire(posf, i) == 2) {
			tab2.tab[lire(posc, i)][lire(posl, i)] = 'C';
		}
	}


}
void destru(Liste& posl, Liste& posc, Liste& posf) {
	detruire(posf);
	detruire(posc);
	detruire(posl);
}
// ouest (x-1, y), sud-ouest(x-1, y+1), sud (x, y+1), sud-est (x+1, y+1),
// est (x+1, y), nord-est (x+1, y-1), nord (x, y-1) et nord-ouest(x-1, y-1)
bool testconex(int ligne, int colone, int face, Liste& posl, Liste& posc, Liste& posf, Tab2D& tab){
	
	if (lire(posl, 0) == 0) {
		if (lire(posc, 0) == colone + 1) {//sud-est (x+1, y+1)
			return true;
		}
		else if (lire(posc, 0) == colone) {//est (x+1, y)
			return true;
		}
		else if (lire(posc, 0) == colone - 1) {//nord-est (x+1, y-1)
			return true;
		}
	}

	else if (lire(posl, 0) == ligne - 1 && lire(posc, 0) == colone) {// ouest (x-1, y)
		return true;
	}
	else if (lire(posl, 0) == ligne - 1 && lire(posc, 0) == colone + 1) {//sud-ouest(x-1, y+1)
		return true;
	}
	else if (lire(posl, 0) == ligne && lire(posc, 0) == colone + 1) {// sud(x, y + 1)
		return true;
	}

	if (lire(posl, 0) == tab.nbL - 1) {
		if (lire(posc, 0) == colone + 1) {//sud-est (x+1, y+1)
			return true;
		}
		else if (lire(posc, 0) == colone) {//est (x+1, y)
			return true;
		}
		else if (lire(posc, 0) == colone - 1) {//nord-est (x+1, y-1)
			return true;
		}
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

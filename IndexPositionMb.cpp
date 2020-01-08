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
		//std::cout << "SUPPRIME Ligne: " << (lire(posl, 0)) << "Colone: " << (lire(posc, 0)) << "Face: " << (lire(posf, 0)) << endl;
		supprimer(posf, 0);
		supprimer(posl, 0);
		supprimer(posc, 0);
		
	}
	
	inserer(posf, 0, face);
	inserer(posl, 0, ligne);
	inserer(posc, 0, colone);
	//cout << "(" << lire(posl, 0) << "," << lire(posc, 0) << "," << lire(posf, 0) << ")" << endl;

	if (face == tab.pFace && colone ==tab.pColone && ligne ==tab.pLigne-1 ) {
		cout << "stop";
	}
	//cout << "ligne" << ligne;
	//Tant que(!estVide(filAriane) et !Connexe(fileAriane[0], C))
	//for (unsigned int i = 0; i < longueur(posf); ++i)
		//cout << (lire(posf, i)) << endl;
	
}
void afficlist(Liste& posl, Liste& posc, Liste& posf, Tab2D& tab1, Tab2D& tab2) {
	for (int i = 0; i < longueur(posl); i++) {
		//cout << "(" << lire(posl, i) << "," << lire(posc, i) << "," << lire(posf, i) << ")" << endl;
		//std::cout << "Ligne: " << (lire(posl, i)) << "Colone: " << (lire(posc, i)) << "Face: " << (lire(posf, i)) << endl;
		if (lire(posf, i) == 1) {
			tab1.tab[lire(posc, i)][lire(posl, i)] = 'C';
		}
		if (lire(posf, i) == 2) {
			tab2.tab[lire(posc, i)][lire(posl, i)] = 'C';
		}
	}



}

void positionaffi(Liste& posl, Liste& posc, Liste& posf) {
	for (int i = 0; i < longueur(posl); i++) {
		//cout << "(" << lire(posl, i) << "," << lire(posc, i) << "," << lire(posf, i) << ")" << endl;
		//C(5,2,2)->C
		std::cout << "C(" << (lire(posl, i)) << "," << (lire(posc, i)) << "," << (lire(posf, i)) << ")->";
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
	//setup recup du fichier dragon a appliquer ici pour bon para 
	
	if (lire(posl, 0) == 0 && lire(posf,0) == 1) { //face 1
		//std::cout << "Ligne: " << "0" << "Colone: " << (colone) << "Face: " << (face) << endl;
		if (lire(posc, 0) == tab.nbC - colone - 1) {// ouest (x-1, y)
			return true;
		}
		else if (lire(posc, 0) == tab.nbC - colone ) {//sud-ouest(x-1, y+1)
			return true;
		}
		else if (lire(posc, 0) == tab.nbC - colone - 2) {//nord-ouest(x-1, y-1)
			return true;
		}
		else {
			//cout << "faux1";
			//return false;
			
		}
	}
	else if (lire(posl, 0) == 0 && lire(posf, 0) == 2) {//face 2

		if (lire(posc, 0) == colone) {// ouest (x-1, y)
			return true;
		}
		else if (lire(posc, 0) == colone - 1) {//sud-ouest(x-1, y+1)
			return true;
		}
		else if (lire(posc, 0) == colone - 2) {//nord-ouest(x-1, y-1)
			return true;
		}
		else {
			//cout << "faux2";
			//return false;

		}
	}
	else if (lire(posl, 0) == tab.nbL - 1 && lire(posf, 0) == 1) { //face 1
		if (lire(posc, 0) == tab.nbC - colone) {//sud-est (x+1, y+1)
			return true;
		}
		else if (lire(posc, 0) == tab.nbC - colone - 1) {//est (x+1, y)
			return true;
		}
		else if (lire(posc, 0) == tab.nbC - colone - 2) {
			//nord-est (x+1, y-1)
			return true;
		}
		else {
			//cout << tab.nbL;
			//cout << "faux3" << endl;
			//return false;
		}
	}
	else if (lire(posl, 0) == tab.nbL - 1 && lire(posf, 0) == 2) { //face 2
		if (lire(posc, 0) == colone) {//sud-est (x+1, y+1)
			return true;
		}
		else if (lire(posc, 0) == colone - 1) {//est (x+1, y)
			return true;
		}
		else if (lire(posc, 0) == colone + 1) {
			//nord-est (x+1, y-1)
			return true;
		}
		else {
			//cout << "faux4";
			//return false;
		}
	}
	else
	if (lire(posl, 0) == ligne - 1 && lire(posc, 0) == colone) {// ouest (x-1, y)
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

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "IndexPositionMb.h"
void listecreat(Liste& pos) {
	initialiser(pos);//initialise liste
}
void conex(int ligne, int colone, int face, Liste& posl, Liste& posc, Liste& posf, Tab2D& tab) {
	
	while (longueur(posf) != 0 && !testconex(ligne, colone, face, posl, posc, posf, tab)) {
		//std::cout << "SUPPRIME Ligne: " << (lire(posl, 0)) << "Colone: " << (lire(posc, 0)) << "Face: " << (lire(posf, 0)) << endl;
		supprimer(posf, 0);//suprime element dans la liste position 0
		supprimer(posl, 0);//suprime element dans la liste position 0
		supprimer(posc, 0);//suprime element dans la liste position 0
		
	}
	
	inserer(posf, 0, face);//inserer face dans la liste position 0
	inserer(posl, 0, ligne);//inserer ligne dans la liste position 0
	inserer(posc, 0, colone);//inserer colone dans la liste position 0
	//cout << "(" << lire(posl, 0) << "," << lire(posc, 0) << "," << lire(posf, 0) << ")" << endl;
	
}
void afficlist(Liste& posl, Liste& posc, Liste& posf, Tab2D& tab1, Tab2D& tab2) {
	for (int i = 0; i < longueur(posl); i++) { //boucle de taille de la liste
		//cout << "(" << lire(posl, i) << "," << lire(posc, i) << "," << lire(posf, i) << ")" << endl;
		//std::cout << "Ligne: " << (lire(posl, i)) << "Colone: " << (lire(posc, i)) << "Face: " << (lire(posf, i)) << endl;
		if (lire(posf, i) == 1) { //si la face est 1
			tab1.tab[lire(posc, i)][lire(posl, i)] = 'C';//remplace la case par C
		}
		if (lire(posf, i) == 2) {//si la face vaut 1
			tab2.tab[lire(posc, i)][lire(posl, i)] = 'C';//remplace la case par C
		}
	}



}

void positionaffi(Liste& posl, Liste& posc, Liste& posf) {
	for (int i = 0; i < longueur(posl); i++) {//boucle de taille de la liste
		//cout << "(" << lire(posl, i) << "," << lire(posc, i) << "," << lire(posf, i) << ")" << endl;
		//C(5,2,2)->C
		std::cout << "C(" << (lire(posl, i)) << "," << (lire(posc, i)) << "," << (lire(posf, i)) << ")->";//affiche style C(5,2,2)->C
	}
}
void destru(Liste& posl, Liste& posc, Liste& posf) {
	detruire(posf);//detruit liste 
	detruire(posc);//detruit liste 
	detruire(posl);//detruit liste 
}
// ouest (x-1, y), sud-ouest(x-1, y+1), sud (x, y+1), sud-est (x+1, y+1),
// est (x+1, y), nord-est (x+1, y-1), nord (x, y-1) et nord-ouest(x-1, y-1)
bool testconex(int ligne, int colone, int face, Liste& posl, Liste& posc, Liste& posf, Tab2D& tab){	
	//setup recup du fichier dragon a appliquer ici pour bon para 
	//cout << "(" << ligne << "," << colone << "," << face << ")" << endl;
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
	}
	else if (lire(posl, 0) == 0 && lire(posf, 0) == 2) {//face 2
		//cout << "(" << ligne << "," << colone << "," << face << ")" << endl;
		//cout << "(" << lire(posl, 0) << "," << lire(posc, 0) << "," << lire(posf, 0) << ")" << endl;
		if (lire(posc, 0) == tab.nbC - colone) {// ouest (x-1, y)
			return true;
		}
		else if (lire(posc, 0) == tab.nbC - colone - 1) {//sud-ouest(x-1, y+1)
			return true;
		}
		else if (lire(posc, 0) == tab.nbC - colone - 2) {//nord-ouest(x-1, y-1)
			return true;
		}
		else {
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
	}
	else if (lire(posl, 0) == tab.nbL - 1 && lire(posf, 0) == 1) { //face 1
		
		if (lire(posc, 0) == tab.nbC - colone) {//sud-est (x+1, y+1)
			return true;
		}
		else if (lire(posc, 0) == tab.nbC - colone - 1) {//est (x+1, y)
			return true;
		}
		else if (lire(posc, 0) == tab.nbC - colone - 2) {//nord-est (x+1, y-1)
			return true;
		}
		else {
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

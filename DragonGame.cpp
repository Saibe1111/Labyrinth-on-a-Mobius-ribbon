#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "DragonGame.h"
void recherche(Tab2D& tab1, Tab2D& tab2) {
	Pile ligne;
	Pile colone;
	Pile face; 
	initialiser(ligne, 10);
	initialiser(colone, 10);
	initialiser(face, 10);
	char test = 'D';
	for (int i = 0; i < tab1.nbC; i++) {
		for (int j = 0; j < tab1.nbL; j++) {
			if (tab1.tab[i][j] == test) {
				empiler(ligne, i);
				empiler(colone, j);
				empiler(face, 1);
			}
		}
	}

	cout << "(" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ")";
	detruire(ligne);
	detruire(colone);
	detruire(face);
}
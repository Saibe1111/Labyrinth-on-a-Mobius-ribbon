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
//empiler l’index de position (iD, jD) de l’entrée du labyrinthe sur la pile p 
	for (int i = 0; i < tab1.nbC; i++) {
		for (int j = 0; j < tab1.nbL; j++) {
			if (tab1.tab[i][j] == 'D') {
				empiler(ligne, j);
				empiler(colone, i);
				empiler(face, 1);
			}
		}
	}
	for (int i = 0; i < tab2.nbC; i++) {
		for (int j = 0; j < tab2.nbL; j++) {
			if (tab2.tab[i][j] == 'D') {
				empiler(ligne, j);
				empiler(colone, i);
				empiler(face, 1);
			}
		}
	}
	//recherche de position de P
	int colP, ligP, faceP;
	for (int i = 0; i < tab1.nbC; i++) {
		for (int j = 0; j < tab1.nbL; j++) {
			if (tab1.tab[i][j] == 'P') {
				ligP =  j;
				colP = i;
				faceP = 1;
			}
		}
	}
	for (int i = 0; i < tab2.nbC; i++) {
		for (int j = 0; j < tab2.nbL; j++) {
			if (tab2.tab[i][j] == 'P') {
				ligP = j;
				colP = i;
				faceP = 2;
			}
		}
	}
//tant_que (le Dragon n’a pas trouvé les Plans du Monde et que p n’est pas vide)
	//while ((ligP != sommet(ligne)) && (faceP != sommet(face)) && (colP != sommet(colone)) && !estVide(ligne)){
		/*if (ligP != sommet(ligne))
			printf("pas bonne ligne");
		if (faceP != sommet(face))
			printf("pas bonne face");
		if (colP != sommet(colone))
			printf("pas bonne colone");
		if (!estVide(ligne))
			printf("pas vide");*/

		//(i, j) <- sommet(p) 
		int i, j, k;
		i = sommet(ligne);
		j = sommet(colone);
		k = sommet(face);
		//  dépiler l’index de position(i, j) de la pile p
		depiler(ligne);
		depiler(colone);
		depiler(face);
	//mettre à jour le « chemin connexe » de l’entrée du labyrinthe au Dragon
		if ((ligP != i) && (faceP != k) && (colP != j)) {
			// empiler impérativement dans l’ordre relatif au référentiel défini
			// ouest (x-1, y), sud-ouest(x-1, y+1), sud (x, y+1), sud-est (x+1, y+1),
			// est (x+1, y), nord-est (x+1, y-1), nord (x, y-1) et nord-ouest(x-1, y-1)
			if (tab1.tab[j][i - 1] == '+'){
				empiler(ligne, j - 1);
				empiler(colone, i);
				empiler(face, 1);
			}
			if (tab1.tab[j + 1][i - 1] == '+') {
				empiler(ligne, j - 1);
				empiler(colone, i);
				empiler(face, 1);
			}
			if (tab1.tab[j + 1][i] == '+') {
				empiler(ligne, j - 1);
				empiler(colone, i);
				empiler(face, 1);
			}
			if (tab1.tab[j + 1][i + 1] == '+') {
				empiler(ligne, j - 1);
				empiler(colone, i);
				empiler(face, 1);
			}
			if (tab1.tab[j][i + 1] == '+') {
				empiler(ligne, j - 1);
				empiler(colone, i);
				empiler(face, 1);
			}
			if (tab1.tab[j - 1][i + 1] == '+') {
				empiler(ligne, j - 1);
				empiler(colone, i);
				empiler(face, 1);
			}
			if (tab1.tab[j - 1][i] == '+') {
				empiler(ligne, j - 1);
				empiler(colone, i);
				empiler(face, 1);
			}
			if (tab1.tab[j - 1][i - 1] == '+') {
				empiler(ligne, j - 1);
				empiler(colone, i);
				empiler(face, 1);
			}
		}

	//}



	cout << "D = (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ")" << endl;
	cout << "P =(" << ligP << "," << colP << "," << faceP << ")" << endl;
	detruire(ligne);
	detruire(colone);
	detruire(face);
}
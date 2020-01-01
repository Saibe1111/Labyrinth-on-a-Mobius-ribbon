#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "DragonGame.h"
void recherche() {
	Pile ligne;
	Pile colone;
	Pile face; 
	initialiser(ligne, 10);
	initialiser(colone, 10);
	initialiser(face, 10);
	empiler(ligne,6);
	empiler(colone, 1);
	empiler(face, 1);
	cout << "(" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ")";
	cout << "(" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ")";
	detruire(ligne);
	detruire(colone);
	detruire(face);
}
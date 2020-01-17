// Projet-SDA.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Tab2D.h"
#include "DragonGame.h"
#include "IndexPositionMb.h"
#include "Liste.h"
#include "Chaine.h"

int main()
{

	Tab2D tabf1; //creation face 1
	Tab2D tabf2; //creation face 2
	initialiserTab(tabf1, tabf2); //initialiser face 1 et face 2
	enregistrerTab(tabf1); //enregistrer tableau 1
	enregistrerTab(tabf2); //enregistrer tableau 2
	afficherPara(tabf1); //affiche les parametres du tableau
	recherche(tabf1, tabf2); //recherche les chemins sur les 2 faces
	detruireTab(tabf1); //destruction tableau 1
	detruireTab(tabf2);//destruction tableau 2
	return 0;
}
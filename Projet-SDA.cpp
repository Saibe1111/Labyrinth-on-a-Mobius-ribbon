// Projet-SDA.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Tab2D.h"
#include "DragonGame.h"


int main()
{
	Tab2D tabf1;
	Tab2D tabf2;
	initialiserTab(tabf1,tabf2);
	enregistrerTab(tabf1);
	enregistrerTab(tabf2);
	afficherPara(tabf1);
	afficherTabSp1(tabf1);
	afficherTabSp1(tabf2);
	recherche(tabf1, tabf2);
	afficherTabSp1(tabf1);
	afficherTabSp1(tabf2);
	detruireTab(tabf1);
	detruireTab(tabf2);
	return 0;
}

//Codez a)les fonctions initialiser et detruire de TableauMbet
//b)les fonctions initialiser, detruire, et afficherSp1de LabyrintheMb.Spécialisez ItemMben caractère.
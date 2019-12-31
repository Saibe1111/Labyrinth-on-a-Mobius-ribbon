// Projet-SDA.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Tab2D.h"



int main()
{
	Tab2D tab;
	initialiserTab(tab);
	detruireTab(tab);
	return 0;
}

//Codez a)les fonctions initialiser et detruire de TableauMbet
//b)les fonctions initialiser, detruire, et afficherSp1de LabyrintheMb.Spécialisez ItemMben caractère.
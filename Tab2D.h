#ifndef _Tab2D_
#define _Tab2D_

#include "Item.h"

struct Tab2D {
	Item** tab;// adresse du tableau bidimensionnel		// en mémoire dynamique 
	int nbL;  	// nombre de lignes de la matrice 
	int nbC; 	// nombre de colonnes de la matrice
};


void initialiserTab(Tab2D& tab1, Tab2D& tab2);
void detruireTab(Tab2D& tab);
void afficherTab(Tab2D& tab);
void enregistrerTab(Tab2D& tab);
#endif /*_Tab2D_*/



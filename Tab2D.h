#ifndef _Tab2D_
#define _Tab2D_

#include "Item.h"
#include "Tab2D.h"
struct Tab2D {
	Item** tab;// adresse du tableau bidimensionnel		// en mémoire dynamique 
	int nbL;  	// nombre de lignes de la matrice 
	int nbC; 	// nombre de colonnes de la matrice
	int pFace; //face de p	
	int pLigne; //ligne de p	
 	int pColone; //colone de p
};

/**
 * @brief initialiser 2 face d'un tableau en 2d
 * @param[in]  tableau face 1
  * @param[in] tableau face 2
 */
void initialiserTab(Tab2D& tab1, Tab2D& tab2);
/**
 * @brief detruire un tableau en 2d
 * @see initialiser,
  * @param[in] tableau a detruire
 */
void detruireTab(Tab2D& tab);
/**
 * @brief afficher les dimensions un tableau en 2d
 * @param[in]  tableau 
 */
void afficherPara(Tab2D& tab);
/**
 * @brief affiche le tableau
 * @param[in]  tableau face 
 */
void afficherTabSp1(Tab2D& tab);
/**
 * @brief enregistrer un tableau en 2d
 * @param[in]  tableau
 */
void enregistrerTab(Tab2D& tab);
/**
 * @brief initialiser 2 face d'un tableau en 2d avec des #
 * @param[in]  tableau face 1
  * @param[in] tableau face 2
 */
void ini(Tab2D& tab);
#endif /*_Tab2D_*/



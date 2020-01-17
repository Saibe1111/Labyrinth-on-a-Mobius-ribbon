#ifndef _IndexPositionMb_
#define _IndexPositionMb_
#include "Item.h"
#include "Pile.h"
#include "Tab2D.h"
#include "IndexPositionMb.h"
#include "Liste.h"
#include "Chaine.h"

/**
 * @brief initialiser la liste
 * @param[in]  liste 
 */
void listecreat(Liste& pos);
/**
 * @brief ajoute la position a la liste si elle est connexe
 * @param[in]  ligne
  * @param[in] colone
  * @param[in] face
  * @param[in] liste ligne
  * @param[in] liste colone
  * @param[in] liste face
  * @param[in] tableau
 */
void conex(int ligne, int colone, int face, Liste& posl, Liste& posc, Liste& posf, Tab2D& tab);
/**
 * @brief verifie si la position donnée est connexe avec la derniere de la liste
 * @param[in]  ligne
  * @param[in] colone
  * @param[in] face
  * @param[in] liste ligne
  * @param[in] liste colone
  * @param[in] liste face
  * @param[in] tableau 
  * @return true si les positions son connexe
 */
bool testconex(int ligne, int colone, int face, Liste& posl, Liste& posc, Liste& posf, Tab2D& tab);
/**
 * @brief affiche C sur les cases connex
  * @param[in] liste ligne
  * @param[in] liste colone
  * @param[in] liste face
  * @param[in] tableau face 1
  * @param[in] tableau face 2
 */
void afficlist(Liste& posl, Liste& posc, Liste& posf, Tab2D& tab1, Tab2D& tab2);
/**
 * @brief detruit la liste
 * @param[in] liste ligne
 * @param[in]  liste colone
  * @param[in] liste face
  * @param[in] tableau face 1 
  * @param[in] tableau face 2
 */
void destru(Liste& posl, Liste& posc, Liste& posf);
/**
 * @brief affiche les positions du chemins connexe
 * @param[in]  tableau face 1
  * @param[in] tableau face 2
 */
void positionaffi(Liste& posl, Liste& posc, Liste& posf);
#endif /*_IndexPositionMb_*/
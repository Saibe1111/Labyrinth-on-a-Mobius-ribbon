

#include <iostream>
#include <cassert>

#include "Pile.h"

 /**
 * @brief Initialiser une pile vide
 * la pile est allouée en mémoire dynamique
 * @see detruire, pour une désallocation en fin d’utilisation
 * @param[out] p : la pile à initialiser
 * @param[in] c : capacité de la pile (nb maximum d‘items stockés)
 * @pre c>0
 */
void initialiser(Pile& p, unsigned int c) {
    assert(c > 0);
    p.capacite = c;
    p.tab = new Case[c];
    p.sommet = -1;
}

/**
 * @brief Désallouer une pile
 * @see initialiser, la pile a déjà été initialisée
 * @param[in,out] p : la pile à désallouer
 */
void detruire(Pile& p) {
    delete[] p.tab;
    p.tab = NULL;
}

/**
 * @brief Test de pile pleine
 * @param[in] p : la pile testée
 * @return true si p est pleine, false sinon
 */
bool estPleine(const Pile& p) {
    return (p.sommet == (p.capacite - 1));
}

/**
 * @brief Test de pile vide
 * @param[in] p : la pile testée
 * @return true si p est vide, false sinon
 */
bool estVide(const Pile& p) {
    return (p.sommet == -1);
}

/**
 * @brief Lire l'item au sommet de pile
 * @param[in] p : la pile
 * @return la valeur de l'item au sommet de pile
 * @pre la pile n’est pas vide
 */
Case sommet(const Pile& p) {
    assert(!estVide(p));
    return p.tab[p.sommet];
}

/**
 * @brief Empiler un item sur une pile
 * @param[in,out] p : la pile
 * @param[in] it : l'item à empiler
 * @pre la pile n’est pas pleine
 */
void empiler(Pile& p, const Case& it) {
    assert(!estPleine(p));
    p.sommet++;
    p.tab[p.sommet] = it;
}

/**
 * @brief Dépiler l’item au sommet de pile
 * @param[in,out] p : la pile
 * @pre la pile n’est pas vide
 */
void depiler(Pile& p) {
    assert(!estVide(p));
    p.sommet--;
}

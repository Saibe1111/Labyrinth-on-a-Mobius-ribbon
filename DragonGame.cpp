#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cassert>
using namespace std;
#include "DragonGame.h"
#include "Tab2D.h"
#include "Liste.h"
#include "Chaine.h"
#include "IndexPositionMb.h"

void recherche(Tab2D& tab1, Tab2D& tab2) {
	Pile ligne;
	Pile colone;
	Pile face; 
	Liste Lligne;
	Liste Lcolone;
	Liste Lface;
	listecreat(Lligne);
	listecreat(Lcolone);
	listecreat(Lface);
	initialiser(ligne, tab1.nbC*tab1.nbL*4);
	initialiser(colone, tab1.nbC * tab1.nbL * 4);
	initialiser(face, tab1.nbC * tab1.nbL * 4);
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
				tab1.tab[i][j] = '+';
			}
		}
	}
	for (int i = 0; i < tab2.nbC; i++) {
		for (int j = 0; j < tab2.nbL; j++) {
			if (tab2.tab[i][j] == 'P') {
				ligP = j;
				colP = i;
				faceP = 2;
				tab2.tab[i][j] = '+';
			}
		}
	}
//tant_que (le Dragon n’a pas trouvé les Plans du Monde et que p n’est pas vide)
	int step = 0;
	int i, j, k;
	while ((ligP != sommet(ligne)) || (faceP != sommet(face)) || (colP != sommet(colone)) && !estVide(ligne)){
		//while(step < 20) {
			//(i, j) <- sommet(p) 
		j = sommet(colone);
		i = sommet(ligne);
		k = sommet(face);

		//  dépiler l’index de position(i, j) de la pile p
		depiler(ligne);
		depiler(colone);
		depiler(face);
		
		
		//std::cout << "depile : i" << i << "j" << j << "k" << k << endl;
		//mettre à jour le « chemin connexe » de l’entrée du labyrinthe au Dragon
		if ((ligP != i) || (faceP != k) || (colP != j)) {
			conex(i, j, k, Lligne, Lcolone, Lface, tab1);
			// empiler impérativement dans l’ordre relatif au référentiel défini
			// ouest (x-1, y), sud-ouest(x-1, y+1), sud (x, y+1), sud-est (x+1, y+1),
			// est (x+1, y), nord-est (x+1, y-1), nord (x, y-1) et nord-ouest(x-1, y-1)
			//std::cout << "i" << i << "j" << j ;
			if (k == 1) {
				//cout << "k1" << endl;
				if (i > -1) {
					if (i == 0 && tab2.tab[(tab1.nbC - j - 1)][tab1.nbL - 1] == '+') {// ouest (x-1, y)
						assert((tab1.nbL - j - 1) < 150);;
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
						empiler(ligne, tab1.nbL - 1);
						empiler(colone, (tab1.nbC - j -1) );
						empiler(face, 2);
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
					}
					
					else if (tab1.tab[j][i - 1] == '+') {// ouest (x-1, y)
						assert(j < 150);
						empiler(ligne, i - 1);
						empiler(colone, j);
						empiler(face, 1);
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
					}
					if (i == 0 && tab2.tab[(tab1.nbC - j - 1) - 1][tab1.nbL - 1] == '+') {//sud-ouest(x-1, y+1)
						assert(j + 1 < 150);
						empiler(ligne, tab1.nbL - 1);
						empiler(colone, (tab1.nbC - j - 1) - 1);
						empiler(face, 2);
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
					}
					else if (tab1.tab[j + 1][i - 1] == '+') {//sud-ouest(x-1, y+1)
						assert(j + 1 < 150);
						empiler(ligne, i - 1);
						empiler(colone, j + 1);
						empiler(face, 1);
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
					}
				}
				if (tab1.tab[j + 1][i] == '+') { //sud (x, y+1)
					assert(j + 1 < 150);
					empiler(ligne, i);
					empiler(colone, j + 1);
					empiler(face, 1);
					//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
				}

				// debug changement de face 
				if (i == tab1.nbL - 1 && tab2.tab[(tab1.nbC - j - 1) - 1][0] == '+') {//sud-est (x+1, y+1)
					assert((tab1.nbC - j - 2)  < 150);
					empiler(ligne, 0);
					empiler(colone, (tab1.nbC - j - 1) - 1);
					empiler(face, 2);
					//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
				}
				else if (tab1.tab[j + 1][i + 1] == '+') {//sud-est (x+1, y+1)
					assert(j + 1 < 150);
					empiler(ligne, i + 1);
					empiler(colone, j + 1);
					empiler(face, 1);
					//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
				}
				
				// debug changement de face 
				if (i == tab1.nbL - 1 && tab2.tab[(tab1.nbC - j - 1)][0] == '+') {// est (x+1, y)
					assert(j < 150);
					empiler(ligne, 0);
					empiler(colone, (tab1.nbC - j -1));
					empiler(face, 2);
					//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
				}
				else if (tab1.tab[j][i + 1] == '+') {// est (x+1, y)
					assert(j < 150);
					empiler(ligne, i + 1);
					empiler(colone, j);
					empiler(face, 1);
					//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
				}
				
				if (j > 0) {
					// debug changement de face 
					if (i == tab1.nbL - 1 && tab2.tab[tab1.nbC - j ][0] == '+') {//nord-est (x+1, y-1)
						assert((tab1.nbC - j - 2) < 150);
						empiler(ligne, 0);
						empiler(colone, (tab1.nbC - j ));
						empiler(face, 2);
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
					}
					else if (tab1.tab[j - 1][i + 1] == '+') {//nord-est (x+1, y-1)
						assert(j - 1 < 150);
						empiler(ligne, i + 1);
						empiler(colone, j - 1);
						empiler(face, 1);
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
					}
					
					if (tab1.tab[j - 1][i] == '+') {//nord (x, y-1)
						assert(j - 1 < 150);
						empiler(ligne, i);
						empiler(colone, j - 1);
						empiler(face, 1);
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
					}
					if (i > -1) {
						if (i == 0 && tab2.tab[(tab1.nbC - j - 1) + 1][tab1.nbL - 1] == '+') {//nord-ouest(x-1, y-1)
							assert(j - 1 < 150);
							empiler(ligne, tab1.nbL - 1);
							empiler(colone, (tab1.nbC - j - 1) + 1);
							empiler(face, 2);
							//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
						}
						else if (tab1.tab[j - 1][i - 1] == '+') {//nord-ouest(x-1, y-1)
							assert(j - 1 < 150);
							empiler(ligne, i - 1);
							empiler(colone, j - 1);
							empiler(face, 1);
							//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
						}
					}
				}
				tab1.tab[j][i] = 'V';
				//std::cout << "V en  : i" << i << "j" << j << "k" << 1 << endl;
			}

			//face 2 
			
			else if (k == 2) {
				//cout << "k2" << endl;
				if (i > -1) {
					if (i == 0 && tab1.tab[(tab1.nbC - j - 1)][tab1.nbL - 1] == '+') {// ouest (x-1, y)
						assert((tab1.nbC - j - 1) < 150);
						empiler(ligne, tab1.nbL - 1);
						empiler(colone, (tab1.nbC - j - 1));
						empiler(face, 1);
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
					}

					else if (tab2.tab[j][i - 1] == '+') {// ouest (x-1, y)
						assert(j < 150);
						empiler(ligne, i - 1);
						empiler(colone, j);
						empiler(face, 2);
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
					}
					if (i == 0 && tab1.tab[(tab1.nbC - j - 1) - 1][tab1.nbL - 1] == '+') {//sud-ouest(x-1, y+1)
						assert(((tab1.nbC - j - 1) - 1) < 150);
						empiler(ligne, tab1.nbL - 1);
						empiler(colone, (tab1.nbC - j - 1)  - 1);
						empiler(face, 1);
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
					}
					else if (tab2.tab[j + 1][i - 1] == '+') {//sud-ouest(x-1, y+1)
						assert(j + 1 < 150);
						empiler(ligne, i - 1);
						empiler(colone, j + 1);
						empiler(face, 2);
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
					}
				}
				if (tab2.tab[j + 1][i] == '+') { //sud (x, y+1)
					assert(j + 1 < 150);
					empiler(ligne, i);
					empiler(colone, j + 1);
					empiler(face, 2);
					//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
				}

				// debug changement de face 
				if (i == tab1.nbL - 1 && tab1.tab[(tab1.nbC - j - 1) - 1][0] == '+') {//sud-est (x+1, y+1)
					assert(((tab1.nbC - j - 1) - 1) < 150);
					empiler(ligne, 0);
					empiler(colone, (tab1.nbC - j - 1) - 1);
					empiler(face, 1);
					//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
				}
				else if (tab2.tab[j + 1][i + 1] == '+') {//sud-est (x+1, y+1)
					assert(j + 1 < 150);
					empiler(ligne, i + 1);
					empiler(colone, j + 1);
					empiler(face, 2);
					//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
				}

				// debug changement de face 
				if (i == tab1.nbL - 1 && tab1.tab[tab1.nbC - j - 1][0] == '+') {// est (x+1, y)
					assert((tab1.nbC - j - 1) < 150);
					empiler(ligne, 0);
					empiler(colone, (tab1.nbC - j - 1));
					empiler(face, 1);
					//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
				}
				else if (tab2.tab[j][i + 1] == '+') {// est (x+1, y)
					assert(j < 150);
					empiler(ligne, i + 1);
					empiler(colone, j);
					empiler(face, 2);
					//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
				}

				if (j > 0) {
					// debug changement de face 
					if (i == tab2.nbL - 1 && tab1.tab[tab1.nbC - j - 1][0] == '+') {//nord-est (x+1, y-1)
						assert((tab1.nbC - j - 1) < 150);
						empiler(ligne, 0);
						empiler(colone, (tab1.nbC - j - 1));
						empiler(face, 1);
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
					}
					else if (tab2.tab[j - 1][i + 1] == '+') {//nord-est (x+1, y-1)
						assert(j - 1 < 150);
						empiler(ligne, i + 1);
						empiler(colone, j - 1);
						empiler(face, 2);
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
					}

					if (tab2.tab[j - 1][i] == '+') {//nord (x, y-1)
						assert(j - 1 < 150);
						empiler(ligne, i);
						empiler(colone, j - 1);
						empiler(face, 2);
						//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
					}
					if (i > -1) {
						if (i == 0 && tab1.tab[(tab1.nbC - j - 1) + 1][tab1.nbL - 1] == '+') {//nord-ouest(x-1, y-1)
							assert((tab1.nbC - j - 1) + 1 < 150);
							empiler(ligne, tab1.nbL - 1);
							empiler(colone, (tab1.nbC - j - 1) + 1);
							empiler(face, 1);
							//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
						}
						else if (tab2.tab[j - 1][i - 1] == '+') {//nord-ouest(x-1, y-1)
							assert(j - 1 < 150);
							empiler(ligne, i - 1);
							empiler(colone, j - 1);
							empiler(face, 2);
							//cout << "Empile : (" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
						}
					}
				}
				tab2.tab[j][i] = 'V';
				//std::cout << "V en  : i" << i << "j" << j << "k" << 2 << endl;
			}
			step++;
			//afficherTabSp1(tab1);
			//afficherTabSp1(tab2);
			//cout << "(" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") " << endl;
			//std::cout << step;
			
		}
	}

	
	if (faceP == 2) {
		tab2.tab[colP][ligP] = 'C';
	}
	else if(faceP == 1) {
		tab1.tab[colP][ligP] = 'C';
	}
	//si(l’index de position est celui des Plans du Monde)
		// le Dragon a trouvé les Plans, il est heureux !!!
		//afficher le bonheur du Dragon…
		//éditer la solution // suite des index de position du chemin
		 // de l’entrée du labyrinthe aux Plans du Monde
		//sinon
		// tout le labyrinthe a été exploré (p est vide)// Plans inaccessibles
		//afficher le feu du mécontentement du Dragon…
		//fin_si
	//if ((ligP == i) && (faceP == k) && (colP == j)) {
		//cout << "le Dragon a trouvé les Plans, il est heureux !!!" << endl;
	
	for (int i = 0; i < tab1.nbC; i++) {
		for (int j = 0; j < tab1.nbL; j++) {
			if (tab1.tab[i][j] == 'V') {
				tab1.tab[i][j] = '+';
			}
		}
	}
	for (int i = 0; i < tab2.nbC; i++) {
		for (int j = 0; j < tab2.nbL; j++) {
			if (tab2.tab[i][j] == 'V') {
				tab2.tab[i][j] = '+';
			}
		}
	}

		afficlist(Lligne, Lcolone, Lface, tab1, tab2);
		afficherTabSp1(tab1);
		afficherTabSp1(tab2);
		//sprint 2
		//int max = ligne.sommet;
		//for (int r = 0; r < max +1; r++) {
		//	cout << "(" << sommet(ligne) << "," << sommet(colone) << "," << sommet(face) << ") ";
		//	depiler(ligne);
		//	depiler(colone);
		//	depiler(face);
		//}
		//cout << endl;
	//}

	detruire(ligne);
	detruire(colone);
	detruire(face);
}
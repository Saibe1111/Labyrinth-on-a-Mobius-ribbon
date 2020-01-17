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
	Pile ligne; //declaration pile ligne
	Pile colone;//declaration pile colone
	Pile face; // declaration pile face
	Liste Lligne;//declaration liste ligne
	Liste Lcolone;//declaration liste colone
	Liste Lface;//declaration liste face
	listecreat(Lligne);//creation liste ligne
	listecreat(Lcolone);//creation liste colone
	listecreat(Lface);//creation liste face
	initialiser(ligne, tab1.nbC*tab1.nbL*8); //imitialisation tableau
	initialiser(colone, tab1.nbC * tab1.nbL * 8);//imitialisation tableau
	initialiser(face, tab1.nbC * tab1.nbL * 8);//imitialisation tableau
//empiler l’index de position (iD, jD) de l’entrée du labyrinthe sur la pile p 
	for (int i = 0; i < tab1.nbC; i++) {//parcour toute les cases possible 
		for (int j = 0; j < tab1.nbL; j++) {
			if (tab1.tab[i][j] == 'D') { //on cherche D
				empiler(ligne, j);//empile ligne D
				empiler(colone, i);//empile colone D
				empiler(face, 1);//empile face D a 1
				
			}
		}
	}
	for (int i = 0; i < tab2.nbC; i++) {//parcour toute les cases possible 
		for (int j = 0; j < tab2.nbL; j++) {
			if (tab2.tab[i][j] == 'D') {//on cherche D
				empiler(ligne, j);//empile ligne D
				empiler(colone, i);//empile colone D
				empiler(face, 2);//empile face D a 2
			}
		}
	}
	//recherche de position de P
	int colP, ligP, faceP;
	for (int i = 0; i < tab1.nbC; i++) {
		for (int j = 0; j < tab1.nbL; j++) {
			if (tab1.tab[i][j] == 'P') {
				ligP =  j; //stock valeur de ligne p
				colP = i;//stock valeur de colone p
				faceP = 1;//faceP =1
				tab1.pLigne = j;//stock valeur de ligne p
				tab1.pColone = i;//stock valeur de colone p
				tab1.pFace = 1; //stock face 1
				tab1.tab[i][j] = '+'; //remplace pos de P par +
			}
		}
	}
	for (int i = 0; i < tab2.nbC; i++) {
		for (int j = 0; j < tab2.nbL; j++) {
			if (tab2.tab[i][j] == 'P') {
				ligP = j;//stock valeur de ligne p
				colP = i;//stock valeur de colone p
				faceP = 2;//faceP =2
				tab1.pLigne = j;//stock valeur de ligne p
				tab1.pColone = i;//stock valeur de colone p
				tab1.pFace = 2;//stock face 2
				
				tab2.tab[i][j] = '+';//remplace pos de P par +
			}
		}
	}
//tant_que (le Dragon n’a pas trouvé les Plans du Monde et que p n’est pas vide)
	int step = 0;
	int i = 0, j = 0, k = 0;// initialisation i,j,k a 0

	
	
	//std::cout << faceP ;

		if (faceP == 2) {
			if (tab2.tab[colP][ligP - 1] == '#' && tab2.tab[colP][ligP + 1] == '#' && tab2.tab[colP - 1][ligP - 1] == '#' && tab2.tab[colP - 1][ligP + 1] == '#' && tab2.tab[colP - 1][ligP] == '#' && tab2.tab[colP + 1][ligP] == '#' && tab2.tab[colP + 1][ligP + 1] == '#' && tab2.tab[colP + 1][ligP - 1] == '#') {
				for (int i = 0; i < tab1.nbC; i++) {
					for (int j = 0; j < tab1.nbL; j++) {
						tab1.tab[i][j] = '#';//remise des tableau a #
						tab2.tab[i][j] = '#';//remise des tableau a #
					}
				}
				tab2.tab[colP][ligP] = 'P';// mise de P sur ces coordoné
				afficherTabSp1(tab1);//affiche tab face1 
				afficherTabSp1(tab2);//affiche tab face2
				exit(1);//quitte le prog
			}

		}
		else if (faceP == 1) {
			if (tab1.tab[colP][ligP - 1] == '#' && tab1.tab[colP][ligP + 1] == '#' && tab1.tab[colP - 1][ligP - 1] == '#' && tab1.tab[colP - 1][ligP + 1] == '#' && tab1.tab[colP - 1][ligP] == '#' && tab1.tab[colP + 1][ligP] == '#' && tab1.tab[colP + 1][ligP + 1] == '#' && tab1.tab[colP + 1][ligP - 1] == '#') {

				for (int i = 0; i < tab1.nbC; i++) {
					for (int j = 0; j < tab1.nbL; j++) {
						tab1.tab[i][j] = '#';//remise des tableau a #
						tab2.tab[i][j] = '#';//remise des tableau a #
					}
				}
					tab1.tab[colP][ligP] = 'P';// mise de P sur ces coordoné
	
				afficherTabSp1(tab1);//affiche tab face1
				afficherTabSp1(tab2);//affiche tab face2
				exit(1);//quitte le prog
			}

		}
		

	while ((ligP != sommet(ligne)) || (faceP != sommet(face)) || (colP != sommet(colone)) && !estVide(ligne)){
			//(i, j) <- sommet(p) 
		j = sommet(colone); //stock sommet de colone dans j
		i = sommet(ligne);//stock sommet de ligne dans i
		k = sommet(face);//stock sommet de face dans k

		//  dépiler l’index de position(i, j) de la pile p
		depiler(ligne); //depile
		depiler(colone);//depile
		depiler(face);//depile
		
		
		//std::cout << "depile : i" << i << "j" << j << "k" << k << endl;
		//mettre à jour le « chemin connexe » de l’entrée du labyrinthe au Dragon
		if ((ligP != i) || (faceP != k) || (colP != j)) { // si coordoné différent de celle de P
			conex(i, j, k, Lligne, Lcolone, Lface, tab1);//on regarde la connectivité
			// empiler impérativement dans l’ordre relatif au référentiel défini
			// ouest (x-1, y), sud-ouest(x-1, y+1), sud (x, y+1), sud-est (x+1, y+1),
			// est (x+1, y), nord-est (x+1, y-1), nord (x, y-1) et nord-ouest(x-1, y-1)
			//std::cout << "i" << i << "j" << j ;
			if (k == 1) {
				//cout << "k1" << endl;
				//cout << "i: " << i << " j: " << j << " 1 " << endl;
				if (i > -1) {
					if (i == 0 && tab2.tab[(tab1.nbC - j - 1)][tab1.nbL - 1] == '+') {// ouest (x-1, y)
						assert((tab1.nbL - j - 1) < 150);;
						
						empiler(ligne, tab1.nbL - 1);
						empiler(colone, (tab1.nbC - j -1) );
						empiler(face, 2);
						
					}
					
					else if (tab1.tab[j][i - 1] == '+') {// ouest (x-1, y)
						assert(j < 150);
						empiler(ligne, i - 1);
						empiler(colone, j);
						empiler(face, 1);
						
					}
					if (j + 1 < tab1.nbC) {
						if (i == 0 && tab2.tab[(tab1.nbC - j - 1) - 1][tab1.nbL - 1] == '+') {//sud-ouest(x-1, y+1)
							assert(j + 1 < 150);
							empiler(ligne, tab1.nbL - 1);
							empiler(colone, (tab1.nbC - j - 1) - 1);
							empiler(face, 2);
							
						}
						else if (tab1.tab[j + 1][i - 1] == '+') {//sud-ouest(x-1, y+1)
							assert(j + 1 < 150);
							empiler(ligne, i - 1);
							empiler(colone, j + 1);
							empiler(face, 1);
							
						}
					}
				}
				if (j + 1 < tab1.nbC) {
					if (tab1.tab[j + 1][i] == '+') { //sud (x, y+1)
						assert(j + 1 < 150);
						empiler(ligne, i);
						empiler(colone, j + 1);
						empiler(face, 1);
						
					}
				}
				// debug changement de face 
				if (j + 1 < tab1.nbC) {
					if (i == tab1.nbL - 1 && tab2.tab[(tab1.nbC - j - 1) - 1][0] == '+') {//sud-est (x+1, y+1)
						assert((tab1.nbC - j - 2) < 150);
						empiler(ligne, 0);
						empiler(colone, (tab1.nbC - j - 1) - 1);
						empiler(face, 2);
						
					}
					else if (tab1.tab[j + 1][i + 1] == '+') {//sud-est (x+1, y+1)
						assert(j + 1 < 150);
						empiler(ligne, i + 1);
						empiler(colone, j + 1);
						empiler(face, 1);
						
					}
				}
				// debug changement de face 
				if (i == tab1.nbL - 1 && tab2.tab[(tab1.nbC - j - 1)][0] == '+') {// est (x+1, y)
					assert(j < 150);
					empiler(ligne, 0);
					empiler(colone, (tab1.nbC - j -1));
					empiler(face, 2);
					
				}
				else if (tab1.tab[j][i + 1] == '+') {// est (x+1, y)
					assert(j < 150);
					empiler(ligne, i + 1);
					empiler(colone, j);
					empiler(face, 1);
					
				}
				
				if (j > 0) {
					// debug changement de face 
					if (i == tab1.nbL - 1 && tab2.tab[tab1.nbC - j ][0] == '+') {//nord-est (x+1, y-1)
						assert((tab1.nbC - j - 2) < 150);
						empiler(ligne, 0);
						empiler(colone, (tab1.nbC - j ));
						empiler(face, 2);
						
					}
					else if (tab1.tab[j - 1][i + 1] == '+') {//nord-est (x+1, y-1)
						assert(j - 1 < 150);
						empiler(ligne, i + 1);
						empiler(colone, j - 1);
						empiler(face, 1);
						
					}
					
					if (tab1.tab[j - 1][i] == '+') {//nord (x, y-1)
						assert(j - 1 < 150);
						empiler(ligne, i);
						empiler(colone, j - 1);
						empiler(face, 1);
						
					}
					if (i > -1) {
						if (i == 0 && tab2.tab[(tab1.nbC - j - 1) + 1][tab1.nbL - 1] == '+') {//nord-ouest(x-1, y-1)
							assert(j - 1 < 150);
							empiler(ligne, tab1.nbL - 1);
							empiler(colone, (tab1.nbC - j - 1) + 1);
							empiler(face, 2);
							
						}
						else if (tab1.tab[j - 1][i - 1] == '+') {//nord-ouest(x-1, y-1)
							assert(j - 1 < 150);
							empiler(ligne, i - 1);
							empiler(colone, j - 1);
							empiler(face, 1);
							
						}
					}
				}
				tab1.tab[j][i] = 'V';
				//std::cout << "V en  : i" << i << "j" << j << "k" << 1 << endl;
			}

			//face 2 
			
			else if (k == 2) {
				//cout << "i: " << tab1.nbC << " j: "<< tab1.nbL << " 2" << endl;
				
				if (i > -1) {
					if (i == 0 && tab1.tab[(tab1.nbC - j - 1)][tab1.nbL - 1] == '+') {// ouest (x-1, y)
						assert((tab1.nbC - j - 1) < 150);
						empiler(ligne, tab1.nbL - 1);
						empiler(colone, (tab1.nbC - j - 1));
						empiler(face, 1);
						
					}

					else if (tab2.tab[j][i - 1] == '+') {// ouest (x-1, y)
						assert(j < 150);
						empiler(ligne, i - 1);
						empiler(colone, j);
						empiler(face, 2);
						
					}
					//cout << j + 1;
					//cout << "'"<< tab1.nbC;
					if (j + 1 < tab1.nbC){
					if (i == 0 && tab1.tab[(tab1.nbC - j - 1) - 1][tab1.nbL - 1] == '+' ) {//sud-ouest(x-1, y+1)
						assert(((tab1.nbC - j - 1) - 1) < 150);
						empiler(ligne, tab1.nbL - 1);
						empiler(colone, (tab1.nbC - j - 1)  - 1);
						empiler(face, 1);
						
					}
					

					else if (tab2.tab[j + 1][i - 1] == '+' ) {//sud-ouest(x-1, y+1)
						assert(j + 1 < 150);
						empiler(ligne, i - 1);
						empiler(colone, j + 1);
						empiler(face, 2);
						
					}
					}
				}
				if (j + 1 < tab1.nbC) {
					if (tab2.tab[j + 1][i] == '+') { //sud (x, y+1)
						assert(j + 1 < 150);
						empiler(ligne, i);
						empiler(colone, j + 1);
						empiler(face, 2);
						
					}

					// debug changement de face 
					if (i == tab1.nbL - 1 && tab1.tab[(tab1.nbC - j - 1) - 1][0] == '+') {//sud-est (x+1, y+1)
						assert(((tab1.nbC - j - 1) - 1) < 150);
						empiler(ligne, 0);
						empiler(colone, (tab1.nbC - j - 1) - 1);
						empiler(face, 1);
						
					}

					else if (tab2.tab[j + 1][i + 1] == '+') {//sud-est (x+1, y+1)
						assert(j + 1 < 150);
						empiler(ligne, i + 1);
						empiler(colone, j + 1);
						empiler(face, 2);
						
					}
				}
				// debug changement de face 
				if (i == tab1.nbL - 1 && tab1.tab[tab1.nbC - j - 1][0] == '+') {// est (x+1, y)
					assert((tab1.nbC - j - 1) < 150);
					empiler(ligne, 0);
					empiler(colone, (tab1.nbC - j - 1));
					empiler(face, 1);
					
				}
				else if (tab2.tab[j][i + 1] == '+') {// est (x+1, y)
					assert(j < 150);
					empiler(ligne, i + 1);
					empiler(colone, j);
					empiler(face, 2);
					
				}

				if (j > 0) {
					// debug changement de face 
					if (i == tab2.nbL - 1 && tab1.tab[tab1.nbC - j - 1][0] == '+') {//nord-est (x+1, y-1)
						assert((tab1.nbC - j - 1) < 150);
						empiler(ligne, 0);
						empiler(colone, (tab1.nbC - j - 1));
						empiler(face, 1);
						
					}
					else if (tab2.tab[j - 1][i + 1] == '+') {//nord-est (x+1, y-1)
						assert(j - 1 < 150);
						empiler(ligne, i + 1);
						empiler(colone, j - 1);
						empiler(face, 2);
						
					}

					if (tab2.tab[j - 1][i] == '+') {//nord (x, y-1)
						assert(j - 1 < 150);
						empiler(ligne, i);
						empiler(colone, j - 1);
						empiler(face, 2);
						
					}
					if (i > -1) {
						if (i == 0 && tab1.tab[(tab1.nbC - j - 1) + 1][tab1.nbL - 1] == '+') {//nord-ouest(x-1, y-1)
							assert((tab1.nbC - j - 1) + 1 < 150);
							empiler(ligne, tab1.nbL - 1);
							empiler(colone, (tab1.nbC - j - 1) + 1);
							empiler(face, 1);
							
						}
						else if (tab2.tab[j - 1][i - 1] == '+') {//nord-ouest(x-1, y-1)
							assert(j - 1 < 150);
							empiler(ligne, i - 1);
							empiler(colone, j - 1);
							empiler(face, 2);
							
						}
					}
				}
				tab2.tab[j][i] = 'V'; //marque visité la case
				//std::cout << "V en  : i" << i << "j" << j << "k" << 2 << endl;
			}
		}
	}
//
	if (faceP == 2) {// remplace case P par C pour face 2
		tab2.tab[colP][ligP] = 'C';
	}
	else if(faceP == 1) {// remplace case P par C pour face 1
		tab1.tab[colP][ligP] = 'C';
	}

	for (int i = 0; i < tab1.nbC; i++) {//remplace les V du sprint 3 par des +
		for (int j = 0; j < tab1.nbL; j++) {
			if (tab1.tab[i][j] == 'V') {
				tab1.tab[i][j] = '+';
			}
		}
	}
	for (int i = 0; i < tab2.nbC; i++) {//remplace les V du sprint 3 par des +
		for (int j = 0; j < tab2.nbL; j++) {
			if (tab2.tab[i][j] == 'V') {
				tab2.tab[i][j] = '+';
			}
		}
	}

		afficlist(Lligne, Lcolone, Lface, tab1, tab2);// remplace les + par C pour case connex
		afficherTabSp1(tab1);//afficher tab1
		afficherTabSp1(tab2);//afficher tab2
		if (faceP == 2) {//si face =2
			std::cout << "C(" << ligP << "," << colP << "," << 2 << ")->";//affiche style C(5,2,2)->C
		}
		else if (faceP == 1) {//si face =1
			std::cout << "C(" << ligP << "," << colP << "," << 1 << ")->";//affiche style C(5,2,2)->C
		}
		
		positionaffi(Lligne, Lcolone, Lface);//affiche style C(5,2,2)->C
		std::cout << endl;//saut ligne

	detruire(ligne);//detruit pile
	detruire(colone);//detruit pile
	detruire(face);//detruit pile
}
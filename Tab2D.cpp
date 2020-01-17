#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Tab2D.h"


void initialiserTab(Tab2D& tab1, Tab2D& tab2) {
	//cout << "Ligne : ";
	cin >> tab1.nbL; //nombre de ligne dans tab1
	tab2.nbL = tab1.nbL; //nombre de ligne dans tab2
	//cout << "Colone : "; 
	cin >> tab1.nbC; //nombre de colone de tab1 
	tab2.nbC = tab1.nbC;//nombre de colone de tab2
}
void enregistrerTab(Tab2D& tab) {
	tab.tab = new Item * [tab.nbC]; //declaration
	for (int i = 0; i < tab.nbC; i++) //boucle ligne
		tab.tab[i] = new Item[tab.nbL];
	for (int i = 0; i < tab.nbC; i++) {//boucle colone
		for (int j = 0; j < tab.nbL; j++) {
			cin >> tab.tab[i][j]; //enregistre chaque casw
		}
	}
}
void ini(Tab2D& tab) {
	tab.tab = new Item * [tab.nbC];//declaration
	for (int i = 0; i < tab.nbC; i++)//boucle ligne
		tab.tab[i] = new Item[tab.nbL];
	for (int i = 0; i < tab.nbC; i++) {//boucle colone
		for (int j = 0; j < tab.nbL; j++) {//enregistre chaque case
			tab.tab[i][j] == '#'; //place # sur toute case
		}
	}
}

void afficherPara(Tab2D& tab) {
	cout << tab.nbL << " " << tab.nbC << endl;//affichage parametre style (30,4)
}
void afficherTabSp1(Tab2D& tab) {
	for (int i = 0; i < tab.nbC; i++) {//boucle affichage colone
		for (int j = 0; j < tab.nbL; j++) {//boucle affichage ligne
			cout << tab.tab[i][j];//affiche case i,j
		}
		cout << endl;//saut ligne
	}
	cout << endl;//saut ligne
}

void detruireTab(Tab2D& tab){
	for (int i = 0; i < tab.nbC; i++)//boucle destruction
		delete[] tab.tab[i];//destruction
	delete[] tab.tab;//destructuin

}




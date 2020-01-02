#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Tab2D.h"

void initialiserTab(Tab2D& tab1, Tab2D& tab2) {
	//cout << "Ligne : ";
	cin >> tab1.nbL;
	tab2.nbL = tab1.nbL;
	//cout << "Colone : ";
	cin >> tab1.nbC;
	tab2.nbC = tab1.nbC;
}
void enregistrerTab(Tab2D& tab) {
	tab.tab = new Item * [tab.nbC];
	for (int i = 0; i < tab.nbC; i++)
		tab.tab[i] = new Item[tab.nbL];
	for (int i = 0; i < tab.nbC; i++) {
		for (int j = 0; j < tab.nbL; j++) {
			cin >> tab.tab[i][j];
		}
	}
}
void afficherPara(Tab2D& tab) {
	cout << tab.nbL << " " << tab.nbC << endl;
}
void afficherTabSp1(Tab2D& tab) {
	for (int i = 0; i < tab.nbC; i++) {
		for (int j = 0; j < tab.nbL; j++) {
			cout << tab.tab[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void detruireTab(Tab2D& tab){
	for (int i = 0; i < tab.nbC; i++)
		delete[] tab.tab[i];
	delete[] tab.tab;

}




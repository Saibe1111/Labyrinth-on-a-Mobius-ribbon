

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Tab2D.h"

void initialiserTab(Tab2D& tab) {
	cout << "Colone : ";
	cin >> tab.nbC;
	cout << "Ligne : ";
	cin >> tab.nbL;

	tab.tab = new int* [tab.nbC];
	for (int i = 0; i < tab.nbC; i++)
		tab.tab[i] = new int[tab.nbL];
	tab.tab[1][1] = 3;
	cout << tab.tab[1][1];
	
}
void detruireTab(Tab2D& tab){
	for (int i = 0; i < tab.nbC; i++)
		delete[] tab.tab[i];
	delete[] tab.tab;

	}




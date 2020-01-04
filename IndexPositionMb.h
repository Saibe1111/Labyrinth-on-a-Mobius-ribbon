#ifndef _IndexPositionMb_
#define _IndexPositionMb_
#include "Item.h"
#include "Pile.h"
#include "Tab2D.h"
#include "IndexPositionMb.h"
#include "Liste.h"
#include "Chaine.h"

void listecreat(Liste& pos);
void conex(int ligne, int colone, int face, Liste& posl, Liste& posc, Liste& posf, Tab2D& tab);
bool testconex(int ligne, int colone, int face, Liste& posl, Liste& posc, Liste& posf, Tab2D& tab);
void afficlist(Liste& posl, Liste& posc, Liste& posf, Tab2D& tab1, Tab2D& tab2);
void destru(Liste& posl, Liste& posc, Liste& posf);
#endif /*_IndexPositionMb_*/
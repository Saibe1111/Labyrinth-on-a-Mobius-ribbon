#ifndef _IndexPositionMb_
#define _IndexPositionMb_
#include "Liste.h"
#include "Chaine.h"

void listecreat(Liste& pos);
void conex(int ligne, int colone, int face, Liste& posl, Liste& posc, Liste& posf);
bool testconex(int ligne, int colone, int face, Liste& posl, Liste& posc, Liste& posf);
void destru(Liste& posl, Liste& posc, Liste& posf);
#endif /*_IndexPositionMb_*/
#pragma once
#include <stdlib.h>
#include <stdio.h>
#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt;// le tableau d’entiers
	int size;// la taille de ce tableau d’entiers
	int eltsCount;// le nombre d’éléments dans le tableau
} TABLEAU;

int incrementArraySize(TABLEAU* tab, int incrementValue);
#include <stdlib.h>
#include <stdio.h>

#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt;// le tableau d’entiers
	int size;// la taille de ce tableau d’entiers
	int eltsCount;// le nombre d’éléments dans le tableau
} TABLEAU;

TABLEAU newArray() {
	int* elt = NULL;
	int size = TAILLEINITIALE;
	int eltsCount = 0;
	elt = (int*)malloc(TAILLEINITIALE * sizeof(int));

	if (elt == NULL) { printf("mémoire insuffisante"); TABLEAU tableau1 = { NULL,size,eltsCount }; return(tableau1); }
	else {

		TABLEAU tableau = { elt,size,eltsCount };
		return tableau;
	}
}


int incrementArraySize(TABLEAU* tab, int incrementValue) {
	int* tpm;
	tab->size = tab->size + incrementValue; // On augmente la taille du tableau ou size.heure 

	if (tab->elt == NULL) {
		return 0;
	}
	else {
		tpm = (int*)realloc(tab->elt, tab->size * sizeof(int));
		//On réalloue de la mémoire
		if (tpm == NULL) {
			return 0;  //renvoie 0 si l'allocation a échouée 	
		}
		else {
			tab->elt = tpm;
			return tab->size;//Renvoie la taille du tableau après incrémentation
		}
	}
	free(tab->elt);
}



int setElement(TABLEAU* tab, int pos, int element) {
	if (pos > tab->eltsCount) {
		for (int i = tab->eltsCount; i < pos - 1; i++) {
			tab->elt[i] = 0;
		}
		tab->elt[pos - 1] = element;
		return pos;
	}
	else if (pos > tab->size) { //En dehors du tableau
		return 0;// si on veut changer la taille du tableau on incrementarraysize(pos-size) et on fait une boucle for pour mettre des zéros 
		// incrementarraysize(pos-tab->size)
		//for (int i = tab->eltsCount; i < pos - 1; i++) {
		//tab->elt[i] = 0;
	}		//tab->elt[pos - 1] = element;

	else {
		*(tab->elt + pos - 1) = element;
		return pos;
	}
}


int DisplayElements(TABLEAU* tab, int StartPos, int EndPos) {
	if (StartPos<1 || EndPos>tab->size) { //En dehors du tableau renvoie 0
		return 0;
	}
	else {
		for (int i = StartPos; i < EndPos; i++)
		{
			printf("%d ", *(tab->elt + i)); //Affichage du tableau
		}
		printf("\n");
		return 1;
	}
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	int* tpm;
	int sizeinit = TAILLEINITIALE;//taille initiale du tableau
	int size = TAILLEINITIALE - (endPos - startPos);//taille finale du tableau

	/*if (startPos > endPos) {//pour echanger les deux positions
		//echanger
	}*/
	int position = startPos;
	do {
		for (int i = startPos; i < sizeinit - 1; i++) {
			*(tab->elt + i) = *(tab->elt + (i + 1));
		}
		position++;
	} while (position < endPos);
	if (tab->elt == NULL) {
		return 0;
	} //Renvoie la taille du tableau après incrémentation
	else {
		tpm = (int*)realloc(tab->elt, (TAILLEINITIALE - (endPos - startPos)) * sizeof(int));
		//On réalloue de la mémoire
		if (tpm == NULL) {
			return 0; //Renvoie 0 si l'allocation mémoire à echouée	
		}
		else {
			tab->elt = tpm;
		}
		return size;
		free(tab->elt);
		// si l'allocation est reussie renvoie la taille du tableau
	}
	//	return size;
}



int main() {
	TABLEAU tab = newArray(); //Initialisation de tab
	printf("Taille initiale : %d \n", tab.size); //Impression de sa taille
	incrementArraySize(&tab, 2); //Incrémentation de 2
	printf("Taille incrementee : %d \n", tab.size);
	printf("%d", setElement(&tab, 5, 3));
	printf("%d", DisplayElements(&tab, 0, 5));
	for (int i = 0; i < TAILLEINITIALE; i++) {
		tab.elt[i] = i;
		printf("%d ", tab.elt[i]);
	}
	printf("\n");
	printf("%d ", deleteElements(&tab, 23, 50));
	printf("\n");
	for (int i = 0; i < TAILLEINITIALE - (50 - 23); i++) {
		printf("%d ", (tab.elt[i]));
	}

}
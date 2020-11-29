#include <stdlib.h>
#include <stdio.h>
#include "exo2_TP5.h"


#define TAILLEINITIALE 100


TABLEAU newArray() {//on initialise le tableau avec les variables de l'
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

void PERMUTER(int *A, int *B)
{
	int tmp;
	tmp = *A;
	*A = *B;
	*B = tmp;
}




int setElement(TABLEAU* tab, int pos, int element) {
	if (tab->elt == NULL || tab->size < 0 || pos < 1) { return 0; }
	

	if (pos > tab->eltsCount) {
		for (int i = tab->eltsCount; i < pos; i++) {
			tab->elt[i] = 0;
		}
		tab->elt[pos - 1] = element;
		return pos;
	}
	else {
		*(tab->elt + tab->size - 1) = element;
		tab->eltsCount = pos;
		return pos;
	}
	
}


int DisplayElements(TABLEAU* tab, int StartPos, int EndPos) {
	if (StartPos<1 || EndPos>tab->size+1||tab->elt == NULL) { //En dehors du tableau renvoie 0
		return 0;
	}
	if (EndPos < StartPos) {
		PERMUTER(&EndPos, &StartPos);
	}
	for (int i = StartPos; i < EndPos; i++)
		{
			printf("%d ", *(tab->elt + i)); //Affichage du tableau
		}
		printf("\n");
		return 1;	
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	int* tpm;
	int sizeinit = TAILLEINITIALE;//taille initiale du tableau
	int size = TAILLEINITIALE - (endPos - startPos);//taille finale du tableau

	if (startPos > endPos) {//pour echanger les deux positions
		PERMUTER(&startPos,&endPos);
	}
	int Valeurs = endPos - startPos + 1;
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
		tab->size -= Valeurs;
		return tab->size;
		free(tab->elt);
		// si l'allocation est reussie renvoie la taille du tableau
	}

	
}




int main() {
	TABLEAU tab = newArray(); //Initialisation de tab
	printf("Taille initiale : %d \n", tab.size); //Impression de sa taille
	
	incrementArraySize(&tab, 2); //Incrémentation de 2
	printf("\n");
	for (int i = 0; i < TAILLEINITIALE+1; i++) {//On rempli le tableau avec des valeurs pour le test
		tab.elt[i] = i;
		printf("%d ", tab.elt[i]);
	}
	printf("\n");
	printf("Taille incrementee : %d \n", tab.size);//Impression de la taille après agrandissement 
	printf("%d", setElement(&tab, 5, 3));//Inclus 3 au rang 5
	printf("\nLes elements du tableau sont : ");
	DisplayElements(&tab, 1, 5);//Donne les élements du rang 0 à 5
	printf("\n");
	printf("%d ", deleteElements(&tab, 23, 50));//Supprime les élements du rang 23 à 50
	printf("\n");
	for (int i = 0; i < tab.size-1 ; i++) {//imprime le tableau final 
		printf("%d ", *(tab.elt+i));
	}

}
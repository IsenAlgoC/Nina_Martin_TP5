#include <stdlib.h>
#include <stdio.h>

#define TAB2SIZE 100
#define TAILLEAJOUT 50


int initTab1(int* tab, int size) {//Itinitialise le tableau avec des 0
	if (tab == NULL || size < 0) {
		return -1;
	}
	else {
		for (int i = 0; i < size; i++) {
			tab[i] = 0;

		}
	}return size;
}

int afficheTab(int* tab, int size, int nbElts) {//Affiche les premiers nbELts du tableau
	if (tab == NULL || size < 0 || nbElts>size) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf("%d ", tab[i]);
		}
		return 0;
	}
}
int remplirtableau(int* tab, int size, int* nbElts, int nombre) {
	if (tab == NULL || size < 0) {
		return -1;
	}
	else {
		for (int i = 0; i < nombre; i++) {
			*(tab + i) = i + 1;
			*nbElts += 1;
		}

	}return 0;
}




int* ajouteElementDansTableau(int* tab, int* size, int* nbElts, int element) {

	if (tab == NULL || *size < 0 || *nbElts < 0) { return NULL; } //Si problème retourne NULL

	if (*size > * nbElts) {// Taille suffisante pour element 
		*(tab + *nbElts) = element;
		*nbElts += 1;
	}

	else {// Si taille pas suffissante 
		*size += TAILLEAJOUT;//La taille est incrémentée de Tailleajout en tailleajout
		int* tabSave = tab;
		tab = (int*)realloc(tab, *size * sizeof(int));//On réalloue de la mémoire au tableau
		if (tab == NULL) { tab = tabSave; return NULL; }// Si l'allocation échoue
		*(tab + *nbElts) = element;//On ajoute l'élement dans le tableau à la place souhaitée
		*nbElts += 1;// et le nombre d'élement total du tableau augmente
		}
		
	return tab;
	

}

int main() {
	
	int* myTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 0;
	printf("\n");
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));//Initialisation dynamique du tableau
	if (myTab2 != NULL) { initTab1(myTab2, tabSize); }
	else { printf("mémoire insuffisante"); return(-1); }
	printf("%d\n", initTab1(myTab2, 100));//Initialise le tableau
	printf("Le tableau initialise est :");
	for (int i = 0; i < TAB2SIZE; i++) {
		printf("%d", myTab2[i]);
	}
	printf("\n");
	remplirtableau(myTab2, tabSize, &nbElts, tabSize);
	for (int j = 0; j < 100; j++) {//Remplie le tableau à 100
		printf("%d ", *(myTab2 + j));
	}
	printf("\n");
	afficheTab(myTab2, TAB2SIZE, 20);//affiche les 20 élements
	if (myTab2 != NULL) {
		//initTab1(tab3, 100);
		printf("\n");
		ajouteElementDansTableau(myTab2, &tabSize, &nbElts, 101);//test de l'ajout et de l'aggrandissement du tableau
		for (int i = 0; i < 101; i++) {
			printf("%d ", *(myTab2 + i));
		}
	}
	else { printf("mémoire insuffisante"); }
	free(myTab2);

}
#include <stdlib.h>
#include <stdio.h>


#define TAB2SIZE 100
#define TAILLEAJOUT 50


int initTab1(int* tab, int size) {
	if (tab == NULL || size < 0) {
		return -1;
	}
	else {
		for (int i = 0; i < size; i++) {
			tab[i] = 0;

		}
	}return size;
}

int afficheTab(int* tab, int size, int nbElts) {
	if (tab == NULL || size < 0 || nbElts>size) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf("%d", tab[i]);
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
	}
}


/*int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (tab == NULL || *size < 0 || *nbElts < 0) { return NULL; }
	else {
		if (*nbElts ==* size) {
			*size += TAILLEAJOUT;
			int* oldtab = tab;
			tab = (int*)realloc(tab, (*size ) * sizeof(int)); //Allocation de la mémoire
			if (tab == NULL) {tab = oldtab; return NULL;}​​​​​​​​
				* (tab + *nbElts) = element;
			*nbElts += 1;
			return tab;
		}
		else {
			*(tab + *nbElts) = element;
			*nbElts += 1;
			return tab;
		}
	}
}

*/
int* ajouteElementDansTableau(int* tab, int* size, int* nbElts, int element) {

	if (tab == NULL || *size < 0 || *nbElts < 0) { return NULL; } //Si problème 

	if (*size > * nbElts) {// Taille suffisante pour element 
		*(tab + *nbElts) = element;
		*nbElts += 1;
	}
	else {// Si taille pas suffissante 
		*size += TAILLEAJOUT;//La taille est incrémentée de Tailleajout en tailleajout
		int* tabSave = tab;
		tab = (int*)realloc(tab, *size * sizeof(int));//On réalloue de la mémoire au tableau
		if (tab == NULL) { tab = tabSave; return NULL; }// SI l'allocation échoue
		*(tab + *nbElts) = element;//On ajoute l'élement dans le tableau à la place souhaitée
		*nbElts += 1;// et le nombre d'élement total du tableau augmente
		}
		
	return tab;
	

}

int main() {
	int tab[4] = { 1,3,4,3 };
	printf("%d\n", initTab1(tab, 4));
	printf("Le tableau initialise est :");
	for (int i = 0; i < 4; i++) {
		printf("%d", tab[i]);
	}
	printf("\n");
	afficheTab(tab, 4, 2);
	int* myTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 0;
	printf("\n");
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (myTab2 != NULL) { initTab1(myTab2, tabSize); }
	else { printf("mémoire insuffisante"); return(-1); }
	printf("%d\n", initTab1(myTab2, 100));
	printf("Le tableau initialise est :");
	for (int i = 0; i < TAB2SIZE; i++) {
		printf("%d", myTab2[i]);
	}
	for (int j = 0; j < 20; j++) {
		myTab2[j] = j + 1;
	}
	printf("\n");
	afficheTab(myTab2, TAB2SIZE, 20);
	free(myTab2);
	int* tab3 = NULL;
	tab3 = (int*)malloc(100 * sizeof(int));
	initTab1(tab3, tabSize);//test d'initialisation

	if (tab3 != NULL) {
		initTab1(tab3, 100);
		printf("\n");
		ajouteElementDansTableau(tab3, &tabSize, &nbElts, 102)//test de l'ajout 
		for (int i = 0; i < tabSize; i++) {
			printf("%d", *(tab3 + i));
		}
	}
	else { printf("mémoire insuffisante"); }
	free(tab3);

}
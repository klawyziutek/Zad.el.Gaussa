#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int i, j, k;

	/* Sprawdzenie czy macierz A jest kwadratowa i czy wektor b i 
	 * macierz A mają tyle samo wierszy */

	if (mat->r != mat->c || mat->r != b->r){
		return 2;
	}

	int n = mat->r; //liczba wierszy 
	
	/* Pętla po skosie */
	for(k = 0; k < n - 1; k++){

		/* Sprawdzanie dzielenia przez 0 */
		if(mat->data[k][k] == 0){
			return 1; //macierz osobliwa
		}

		/* Pętla schodkowania */
		for(i = k + 1; i < n; i++){
		
			/* Współczynnik do zerowania */
			double factor = mat->data[i][k] / mat->data[k][k];

			/* Odejmujemy wiersz k od wiersza i */
			for(j = k; j < n; j++){
				mat->data[i][j] -= factor * mat->data[k][j];
			}

			/*Zmiany w wektorze b */
			b->data[i][0] -= factor * b->data[k][0];
		}
	}


	return 0;
}


#include "gauss.h"
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int i, j, k, l;

	/* Sprawdzenie czy macierz A jest kwadratowa i czy wektor b i 
	 * macierz A mają tyle samo wierszy */

	if (mat->r != mat->c || mat->r != b->r){
		return 2;
	}

	int n = mat->r; //liczba wierszy 
	
	/* Pętla po skosie */
	for(k = 0; k < n - 1; k++){
		
		double max_value = fabs(mat->data[k][k]);
		int max_r = k;

		/* Wybór elementu głównego */
		for(l = k + 1; l < n; l++){
			if(fabs(mat->data[l][k]) > max_value){
				max_value = fabs(mat->data[l][k]);
				max_r = l;
			}
		}

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


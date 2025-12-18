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

	/* reszta */


	return 0;
}


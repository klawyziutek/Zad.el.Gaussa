#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	
	if((mat->r != mat->c) || (mat->r < 2) || (mat-> c < 2)){
		return 2;
	}

	/* To ponizej jest przepisaniem b do x. */
	
	int i;
	for (i =0; i < x->r; i++) {
		x->data[i][0] = b->data[i][0];
	}

	// Petla iterujaca od konca macierzy
	for (i = i - 1 ; i >= 0; i--){
		double suma = 0;

		if ( i != x->r - 1){ 
			for(int j = mat->c; j > i+1 ; j--){                            /* Obliczanie sumy wartosci zmiennych po prawej stronie od przekatnej */
				suma = suma + mat->data[i][j-1] * x->data[j-1][0];
			}
		}

		x->data[i][0] = (x->data[i][0] - suma) / mat->data[i][i];              /* Zapis wyniku do wektora x */
	}
	return 0;
}



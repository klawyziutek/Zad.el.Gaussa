#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char ** argv) {
	printf("Program sprawdza czy wynik otrzymany zgadza sie z wynikiem przewidywanym. dziala tylko dla plikow: DaneTestowe i b.\n\n");
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
		
		printToScreen(x);
		if(fabs(x->data[0][0] - (-30)) > 0.0001 || fabs(x->data[1][0] - 20) > 0.0001){ 
			printf("Zly wynik, poprawny to x1 = -30, x2 = 20.\n");
		}
		else{
			printf("Dobry wynik, program dziala poprawnie\n");
		}
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}

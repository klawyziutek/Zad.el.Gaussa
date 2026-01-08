#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Funkcja pomocnicza do porównywania macierzy z tolerancją błędu (epsilon) */
int compare_matrices(Matrix *a, Matrix *b) {
    int i, j;
    double epsilon = 0.000001; // Dopuszczalny błąd zaokrągleń

    if (a->r != b->r || a->c != b->c) {
        printf("BŁĄD: Niezgodne wymiary wyników! Otrzymano %dx%d, oczekiwano %dx%d\n",
               a->r, a->c, b->r, b->c);
        return 0; // Różne
    }

    for (i = 0; i < a->r; i++) {
        for (j = 0; j < a->c; j++) {
            double diff = fabs(a->data[i][j] - b->data[i][j]);
            if (diff > epsilon) {
                printf("BŁĄD: Zła wartość w wierszu %d! Otrzymano %f, oczekiwano %f\n",
                       i, a->data[i][j], b->data[i][j]);
                return 0; // Różne
            }
        }
    }
    return 1; // Macierze są identyczne (w granicach błędu)
}

/* Faktyczna funkcja testująca */

void run_test(char *test_name, char *file_A, char *file_b, char *file_expected_x, int expected_exit_code) {
    printf("Uruchamiam %s... ", test_name);
    
    Matrix *A = readFromFile(file_A);
    Matrix *b = readFromFile(file_b);
    Matrix *x;
    Matrix *expected_x = NULL;
    int res = 0;

    if (A == NULL || b == NULL) {
        if (expected_exit_code == -1) printf("OK (Poprawnie wykryto błąd pliku)\n");
        else printf("BŁĄD (Nie udało się wczytać plików wejściowych)\n");
        
        if (A) freeMatrix(A);
        if (b) freeMatrix(b);
        return;
    }

    res = eliminate(A, b);

    if (res != 0) {
        if (res == expected_exit_code) {
            printf("OK (Oczekiwany kod błędu eliminacji: %d)\n", res);
        } else {
            printf("BŁĄD (Eliminacja zwróciła %d, oczekiwano %d)\n", res, expected_exit_code);
        }
    } else {
        x = createMatrix(b->r, 1);
        if (x != NULL) {
            res = backsubst(x, A, b);
            
            if (res == expected_exit_code) {
                // JEŚLI MAMY PLIK WZORCOWY - SPRAWDZAMY WYNIKI
                if (file_expected_x != NULL) {
                    expected_x = readFromFile(file_expected_x);
                    if (expected_x != NULL) {
                        if (compare_matrices(x, expected_x)) {
                            printf("OK (Wynik liczbowy poprawny)\n");
                        } else {
                            printf("BŁĄD (Niepoprawny wynik liczbowy)\n");
                        }
                        freeMatrix(expected_x);
                    } else {
                        printf("OSTRZEŻENIE: Nie można wczytać pliku wzorcowego %s\n", file_expected_x);
                    }
                } else {
                     printf("OK (Kod powrotu poprawny, brak wzorca do sprawdzenia liczb)\n");
                }
            } else {
                 printf("BŁĄD (Backsubst zwrócił %d, oczekiwano %d)\n", res, expected_exit_code);
            }
            freeMatrix(x);
        } else {
            printf("BŁĄD (Nie udało się utworzyć wektora x)\n");
        }
    }

    freeMatrix(A);
    freeMatrix(b);
}


int main() {
    printf("=== ROZPOCZYNAM AUTOMATYCZNE TESTY ===\n");

    // Test 1: Poprawne dane - sprawdzamy wynik z test1_x.txt
    run_test("Test 1 (Poprawne dane 2x2)", 
             "dane/test1_A.txt", "dane/test1_b.txt", "dane/test1_x.txt", 0);

    // Test 2: Potrzeba skorzystania z wyboru elementu głównego - sprawdzamy wynik z test2_x.txt
    run_test("Test 2 (Selekcja elementu głównego - zamiana wierszy)", 
             "dane/test2_A.txt", "dane/test2_b.txt", "dane/test2_x.txt", 0);

    // Test 3: Macierz osobliwa 
    run_test("Test 3 (Macierz osobliwa)", 
             "dane/test3_A.txt", "dane/test3_b.txt", NULL, 1);

    // Test 4: Zły format 
    run_test("Test 4 (Zły format danych)", 
             "dane/test4_A.txt", "dane/test4_b.txt", NULL, -1);

    printf("=== KONIEC TESTÓW ===\n");
    return 0;
}i

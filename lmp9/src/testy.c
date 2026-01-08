#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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

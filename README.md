# Eliminacja Gaussa - Projekt JIMP

Projekt realizuje program rozwiązujący układy równań liniowych metodą eliminacji Gaussa z wyborem elementu głównego.

## Struktura projektu

* `src/` - kody źródłowe programu (moduły: main, gauss, backsubst, mat_io)
* `dane/` - pliki tekstowe z danymi testowymi (macierze A i wektory b)
* `bin/` - katalog na pliki wykonywalne (tworzony automatycznie podczas kompilacji)
* `Makefile` - plik konfiguracji budowania i testowania projektu

## Budowanie i Uruchamianie (Makefile)

Projekt obsługiwany jest automatycznie. Dostępne są następujące komendy:

### 1. Kompilacja całego projektu - make
Buduje program główny (`gauss`) oraz moduł testowy (`testy`). Pliki wynikowe trafiają do katalogu `bin/`.

### 2. Automatyczne testy - make test
Kompiluje (jeśli trzeba) i uruchamia automat testujący, który sprawdza poprawność obliczeń oraz obsługę błędów (np. macierz osobliwa, złe formaty).

### 3. Czyszczenie - clean
Usuwa skompilowane pliki wykonywalne z katalogu bin/.

### 4. Ręczne uruchomienie programu
Po wpisaniu 'make', program można uruchomić ręcznie na dowolnych danych, np.
./bin/gauss dane/test1_A.txt dane/test1_b.txt

### Autorzy:

* Mikołaj Waszkiewicz
* Jakub Gierek

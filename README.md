# AAL
Projekt z przedmiotu Analiza algorytmów realizowanego przeze mnie w semestrze 18Z.

## O autorze
**Imiona i nazwisko:** Kamil Krzysztof Lipski
**Numer albumu:** 283689
**Adres e-mail:** 01121776@pw.edu.pl
**Prowadzacy:** dr inz. Tomasz Trzcinski
**Numer zadania:** 12

## Tresc zadania
Do walizki o ograniczonej pojemnosci *C* chcemy zaladowac przedmioty o jak najwiekszej wartosci, majac jednak na uwadze, ¿e ka¿dy z nich zajmuje pewna objetosc. Majac *n* przedmiotów
wraz z *n*-elementowa tablica odpowiadajacych im wartosci {*p<sub>i</sub>*} oraz objetosci {*c<sub>i</sub>*}, znajdz zestaw rzeczy mieszczacych sie w walizce o najwiekszej sumarycznej
wartosci. *Uwaga:* Mo¿emy dobierac maksymalnie *m* przedmiotów tego samego typu (tzn. tej samej wartosci i tej samej objetosci). Ocen zlo¿onosc algorytmu.

## Aktywacja programu
1. Pobranie z pliku wejsciowego i wyplucie do wyjsciowego:
```
*aal -m1 <in.txt >out.txt*
```
2. Wygenerowanie instancji problemu i rozwiazanie:
```
*aal -m2 -n10 -mv100 -b2 >out.txt*
```
gdzie *n* - ilosc przedmiotów, *mv* - pojemnosc walizki, *b* - maks. liczba przedmiotów tego samego typu
3. Przeprowadzenie calego procesu testowania z pomiarem czasu dla rosnacego n i porównanie ze zlo¿onoscia teoretyczna:
```
*aal -m3 -n1000 -mv100 -b10 -k30 -step500 -r10 >out.txt*
```
czyli pomiar czasu dla 30 problemów o wielkosciach 1000, 1500, 2000 itd.; dla ka¿dej wielkosci losowanych 10 instancji problemu

## Dane wejsciowe i prezentacja wyników
Struktura pliku z danymi wejsciowymi:
```
*ilosc_przedmiotow*
*pojemnosc_walizki*
*maksymalna_liczba_przedmiotow_tego_samego_typu*
*objetosc1 wartosc1*
*...*
```
Przykladowe pliki z danymi wejsciowymi: *[in.txt](in.txt)*, *[in2.txt](in2.txt)*.

Wyniki dzialania programu sa zapisywane do pliku *out.txt* (lub innego podanego w poleceniu aktywacji programu).
Pierwszy tryb dzialania wypisuje najwieksza mo¿liwa do uzyskania wartosc przedmiotów umieszczonych w walizce przy zachowaniu ograniczenia w postaci jej pojemnosci. Podany zostaj
równie¿ zestaw umieszczonych w niej przedmiotów.
W wyniku dzialania drugiego trybu programu wypisywane sa dodatkowo wzgledem pierwszego wygenerowane przedmioty.
Trzeci tryb dzialania prezentuje tabelke, której kolumnami sa: ilosc przedmiotów, czas wykonania algorytmu dla danej ilosci przedmiotów (bedacy usrednieniem z *r* wykonan) oraz pewna
wartosc *q(n)*. Dla n bedacego mediana wszystkich problemów wartosc ta wynosi *1.0*, dzieki czemu jest mo¿liwe oszacowanie trafnosci oceny zlo¿onosci algorytmu (patrz: [dokumentacja
koncowa] (Dokumentacja koncowa.pdf)). Jesli *q(n)* przyjmuje wartosci w pobli¿u *1.0*, oszacowanie jest poprawne.

## Metoda rozwiazania, zastosowane algorytmy i struktury danych
Na potrzeby zadania zostala zdefiniowana struktura *dataCollection*, przechowujaca dane odpowiadajace danej instancji problemu. W poczatkowym przetwarzaniu jest ona poddawana
dzialaniu algorytmu wykorzystujacego zliczania kubelkowego, w celu usuniecia przedmiotów "nadmiarowych" (przedmioty danego typu, których ilosc w zestawie danych przekracza narzucone
ograniczenie). Nastepnie zostaje rozwiazana wlasciwa czesc problemu - w tym celu zostaje u¿yty algorytm programowania dynamicznego. W przekroju calego programu czesto u¿ywana
struktura danych jest *vector*.

## Pliki zródlowe
Pliki naglówkowe:
- *[algorithm.h](aal/algorithm.h)* - algorytmy i utworzona na potrzeby programu struktura danych
- *[generator.h](aal/generator.h)* - generator danych testowych
- *[interface.h](aal/interface.h)* - interakcja z u¿ytkownikiem
- *[pch.h](aal/pch.h)* - plik utworzony na potrzeby tworzenia projektu w Microsoft Visual Studio 2017

Pliki implementacyjne:
- *[algorithm.cpp](aal/algorithm.cpp)* - implementacja algorytmów i metod utworzonej na potrzeby programu struktury danych
- *[generator.cpp](aal/generator.cpp)* - implementacja generatora danych testowych
- *[interface.cpp](aal/interface.cpp)* - implementacja metod odpowiedzielnych za interakcje z u¿ytkownikiem
- *[main.cpp](aal/main.cpp)* - podstawowy modul programu
- *[pch.cpp](aal/pch.cpp)* - plik utworzony na potrzeby tworzenia projektu w Microsoft Visual Studio 2017

## Dodatkowe informacje
W programie na potrzeby generowania danych wprowadzono ograniczenie dotyczacej maksymalnej wartosci generowanych przedmiotów (makro *MAX_VALUE*). Jest ono obecnie ustawione na 10000.
Ograniczenie to jednak¿e nie dotyczy u¿ytkownika, który podajac wlasne dane nie jest zobligowany do jego przestrzegania. Ponadto w ka¿dej chwili ta wartosc mo¿e zostac zmieniona:
wystarczy zmienic wartosc liczbowa przy *MAX_VALUE* w pliku *[pch.h](aal/pch.h)*. 
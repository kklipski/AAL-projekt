# AAL
Projekt z przedmiotu Analiza algorytm�w realizowanego przeze mnie w semestrze 18Z.

## O autorze
**Imiona i nazwisko:** Kamil Krzysztof Lipski
**Numer albumu:** 283689
**Adres e-mail:** 01121776@pw.edu.pl
**Prowadzacy:** dr inz. Tomasz Trzcinski
**Numer zadania:** 12

## Tresc zadania
Do walizki o ograniczonej pojemnosci *C* chcemy zaladowac przedmioty o jak najwiekszej wartosci, majac jednak na uwadze, �e ka�dy z nich zajmuje pewna objetosc. Majac *n* przedmiot�w
wraz z *n*-elementowa tablica odpowiadajacych im wartosci {*p<sub>i</sub>*} oraz objetosci {*c<sub>i</sub>*}, znajdz zestaw rzeczy mieszczacych sie w walizce o najwiekszej sumarycznej
wartosci. *Uwaga:* Mo�emy dobierac maksymalnie *m* przedmiot�w tego samego typu (tzn. tej samej wartosci i tej samej objetosci). Ocen zlo�onosc algorytmu.

## Aktywacja programu
1. Pobranie z pliku wejsciowego i wyplucie do wyjsciowego:
```
*aal -m1 <in.txt >out.txt*
```
2. Wygenerowanie instancji problemu i rozwiazanie:
```
*aal -m2 -n10 -mv100 -b2 >out.txt*
```
gdzie *n* - ilosc przedmiot�w, *mv* - pojemnosc walizki, *b* - maks. liczba przedmiot�w tego samego typu
3. Przeprowadzenie calego procesu testowania z pomiarem czasu dla rosnacego n i por�wnanie ze zlo�onoscia teoretyczna:
```
*aal -m3 -n1000 -mv100 -b10 -k30 -step500 -r10 >out.txt*
```
czyli pomiar czasu dla 30 problem�w o wielkosciach 1000, 1500, 2000 itd.; dla ka�dej wielkosci losowanych 10 instancji problemu

## Dane wejsciowe i prezentacja wynik�w
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
Pierwszy tryb dzialania wypisuje najwieksza mo�liwa do uzyskania wartosc przedmiot�w umieszczonych w walizce przy zachowaniu ograniczenia w postaci jej pojemnosci. Podany zostaj
r�wnie� zestaw umieszczonych w niej przedmiot�w.
W wyniku dzialania drugiego trybu programu wypisywane sa dodatkowo wzgledem pierwszego wygenerowane przedmioty.
Trzeci tryb dzialania prezentuje tabelke, kt�rej kolumnami sa: ilosc przedmiot�w, czas wykonania algorytmu dla danej ilosci przedmiot�w (bedacy usrednieniem z *r* wykonan) oraz pewna
wartosc *q(n)*. Dla n bedacego mediana wszystkich problem�w wartosc ta wynosi *1.0*, dzieki czemu jest mo�liwe oszacowanie trafnosci oceny zlo�onosci algorytmu (patrz: [dokumentacja
koncowa] (Dokumentacja koncowa.pdf)). Jesli *q(n)* przyjmuje wartosci w pobli�u *1.0*, oszacowanie jest poprawne.

## Metoda rozwiazania, zastosowane algorytmy i struktury danych
Na potrzeby zadania zostala zdefiniowana struktura *dataCollection*, przechowujaca dane odpowiadajace danej instancji problemu. W poczatkowym przetwarzaniu jest ona poddawana
dzialaniu algorytmu wykorzystujacego zliczania kubelkowego, w celu usuniecia przedmiot�w "nadmiarowych" (przedmioty danego typu, kt�rych ilosc w zestawie danych przekracza narzucone
ograniczenie). Nastepnie zostaje rozwiazana wlasciwa czesc problemu - w tym celu zostaje u�yty algorytm programowania dynamicznego. W przekroju calego programu czesto u�ywana
struktura danych jest *vector*.

## Pliki zr�dlowe
Pliki nagl�wkowe:
- *[algorithm.h](aal/algorithm.h)* - algorytmy i utworzona na potrzeby programu struktura danych
- *[generator.h](aal/generator.h)* - generator danych testowych
- *[interface.h](aal/interface.h)* - interakcja z u�ytkownikiem
- *[pch.h](aal/pch.h)* - plik utworzony na potrzeby tworzenia projektu w Microsoft Visual Studio 2017

Pliki implementacyjne:
- *[algorithm.cpp](aal/algorithm.cpp)* - implementacja algorytm�w i metod utworzonej na potrzeby programu struktury danych
- *[generator.cpp](aal/generator.cpp)* - implementacja generatora danych testowych
- *[interface.cpp](aal/interface.cpp)* - implementacja metod odpowiedzielnych za interakcje z u�ytkownikiem
- *[main.cpp](aal/main.cpp)* - podstawowy modul programu
- *[pch.cpp](aal/pch.cpp)* - plik utworzony na potrzeby tworzenia projektu w Microsoft Visual Studio 2017

## Dodatkowe informacje
W programie na potrzeby generowania danych wprowadzono ograniczenie dotyczacej maksymalnej wartosci generowanych przedmiot�w (makro *MAX_VALUE*). Jest ono obecnie ustawione na 10000.
Ograniczenie to jednak�e nie dotyczy u�ytkownika, kt�ry podajac wlasne dane nie jest zobligowany do jego przestrzegania. Ponadto w ka�dej chwili ta wartosc mo�e zostac zmieniona:
wystarczy zmienic wartosc liczbowa przy *MAX_VALUE* w pliku *[pch.h](aal/pch.h)*. 
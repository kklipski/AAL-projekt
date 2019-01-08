# AAL

## O autorze
**Imiona i nazwisko:** Kamil Krzysztof Lipski

**Numer albumu:** 283689

**Adres e-mail:** 01121776@pw.edu.pl

**Prowadzący:** dr inz. Tomasz Trzciński

**Numer zadania:** 12

## Treść zadania
Do walizki o ograniczonej pojemności *C* chcemy załadować przedmioty o jak największej wartości, mając jednak na uwadze, że każdy z nich zajmuje pewną objetość. Majac *n* przedmiotów wraz z *n*-elementową tablicą odpowiadających im wartości {*p<sub>i</sub>*} oraz objętości {*c<sub>i</sub>*}, znajdź zestaw rzeczy mieszczących się w walizce o największej sumarycznej wartości. *Uwaga:* Możemy dobierać maksymalnie *m* przedmiotów tego samego typu (tzn. tej samej wartości i tej samej objętości). Oceń złożoność algorytmu.

## Aktywacja programu
1. Pobranie z pliku wejściowego i wyplucie do wyjściowego:
```
aal -m1 <in.txt >out.txt
```
2. Wygenerowanie instancji problemu i rozwiązanie:
```
aal -m2 -n10 -mv100 -b2 >out.txt
```
gdzie *n* - ilość przedmiotów, *mv* - pojemność walizki, *b* - maks. liczba przedmiotów tego samego typu

3. Przeprowadzenie całego procesu testowania z pomiarem czasu dla rosnącego *n* i porównanie ze złożonoscią teoretyczną:
```
aal -m3 -n1000 -mv100 -b10 -k30 -step500 -r10 >out.txt
```
czyli pomiar czasu dla 30 problemów o wielkosciach 1000, 1500, 2000 itd.; dla każdej wielkosci losowanych 10 instancji problemu

## Dane wejściowe i prezentacja wyników
Struktura pliku z danymi wejściowymi:
```
ilosc_przedmiotow
pojemnosc_walizki
maksymalna_liczba_przedmiotow_tego_samego_typu
objetosc1 wartosc1
...
objetoscN wartoscN
```
Przykładowe pliki z danymi wejściowymi: [in.txt](aal/in.txt), [in2.txt](aal/in2.txt).

Wyniki działania programu są zapisywane do pliku out.txt (lub innego podanego w poleceniu aktywacji programu).

Pierwszy tryb działania wypisuje największą możliwą do uzyskania wartość przedmiotów umieszczonych w walizce przy zachowaniu ograniczenia w postaci jej pojemności. Podany zostaje również zestaw umieszczonych w niej przedmiotów.

W wyniku działania drugiego trybu programu wypisywane sa dodatkowo względem pierwszego wygenerowane przedmioty.

Trzeci tryb działania prezentuje tabelkę, której kolumnami sa: ilość przedmiotów, czas wykonania algorytmu dla danej ilości przedmiotów (będący uśrednieniem z *r* wykonań) oraz pewna wartość *q(n)*. Dla *n* będacego medianą wszystkich problemów wartość ta wynosi 1.0, dzięki czemu jest możliwe oszacowanie trafności oceny złożonosci algorytmu (patrz: [dokumentacja końcowa](Dokumentacja.pdf)). Jesli *q(n)* przyjmuje wartości w pobliżu 1.0, oszacowanie jest poprawne.

## Metoda rozwiązania, zastosowane algorytmy i struktury danych
Na potrzeby zadania została zdefiniowana struktura *dataCollection*, przechowująca dane odpowiadające danej instancji problemu. W początkowym przetwarzaniu jest ona poddawana działaniu algorytmu wykorzystującemu zliczanie kubełkowe, w celu usunięcia przedmiotów "nadmiarowych" (przedmioty danego typu, których ilość w zestawie danych przekracza narzucone ograniczenie). Następnie zostaje rozwiązana właściwa część problemu - w tym celu zostaje użyty algorytm programowania dynamicznego. W przekroju całego programu często używaną strukturą danych jest *vector*.

## Pliki źródłowe
Pliki nagłówkowe:
- [algorithm.h](aal/algorithm.h) - algorytmy i utworzona na potrzeby programu struktura danych
- [generator.h](aal/generator.h) - generator danych testowych
- [interface.h](aal/interface.h) - interakcja z użytkownikiem
- [pch.h](aal/pch.h) - plik utworzony na potrzeby tworzenia projektu w Microsoft Visual Studio 2017

Pliki implementacyjne:
- [algorithm.cpp](aal/algorithm.cpp) - implementacja algorytmów i metod utworzonej na potrzeby programu struktury danych
- [generator.cpp](aal/generator.cpp) - implementacja generatora danych testowych
- [interface.cpp](aal/interface.cpp) - implementacja metod odpowiedzielnych za interakcję z użytkownikiem
- [main.cpp](aal/main.cpp) - podstawowy moduł programu
- [pch.cpp](aal/pch.cpp) - plik utworzony na potrzeby tworzenia projektu w Microsoft Visual Studio 2017

## Dodatkowe informacje
W programie na potrzeby generowania danych wprowadzono ograniczenie dotyczące maksymalnej wartości generowanych przedmiotów (makro *MAX_VALUE*). Jest ono obecnie ustawione na 10000. Ograniczenie to jednakże nie dotyczy użytkownika, który podając własne dane nie jest zobligowany do jego przestrzegania. Ponadto w każdej chwili wartość ta może zostać zmieniona: wystarczy zmienić wartość liczbową znajdującą się przy *MAX_VALUE* w pliku [pch.h](aal/pch.h). 

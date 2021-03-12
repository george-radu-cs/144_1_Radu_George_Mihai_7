# Grupa 144

## Cerinta

Tema 7. Clasa ”Lista_dublu_inlantuita”
Se considera Class Nod{ int info; Nod* prev, next;}

- constructori de inițializare și parametrizati pentru clasa Nod;
- destructor pentru clasa Nod;
Clasa Lista_dublu_inlantuita are:
- doi membri privati „Nod*” reprezentând primul și ultimul element;
- metoda publica de adaugare a unui element pe o poziție;
- supraincarcare a operatorului >> realizata prin utilizarea succesiva a metodei
decarata anterior;
- supraincarcare a operatorului << pentru afisarea listei in ambele sensuri, in
aceeasi funcție;
- metoda publica de stergere a unui element de pe o poziție;
- supraincarcarea operatorului +, care sa efectueze concatenarea a doua liste
dublu inlantuite, rezultand într-o noua lista dublu inlantuita.
Codul ruleaza.

## Cerinte bonus

- suprascriere operator= – done+teste
- operator == si operator != – done+teste
- operator [] se furnizeaza o referinta la elementul de pe pozitia x (ca info,
nu la nod) - done+teste
- operator += – done+teste
- operator ! testeaza pozitiv daca lista este goala – done+teste
- operatorii <, <=, >, >= done+teste
– compararea element cu element (in ordinea parcurgerii)
– compararea cu un intreg, element cu element – done+teste
- operator ^ concatenare cu sine de n ori – done+teste
- membru iterator – done+teste
- metoda resetarea iteratorului la inceput – done+teste
- membru pentru sens parcurgere – am renuntat la acest membru
- metoda next – done+teste
- metoda back – done+teste
- metoda schimbare sens parcurgere – am modificat aceasta metoda intr-o metoda
care inverseaza ordinea elementelor din lista – done+teste

## compilare si rulare program

> \$ cmake CMakeLists.txt && make

Se vor crea 2 executabile:

- unul pentru teste

> \$ ./teste

- unul pentru programul interactiv

> \$ ./project1

## detalii clasa ListaDubluInlantuita

- indexul pentru noduri incepe de la 0 pentru a ramane consistenti cu alte
structuri de date deja existente in C/C++
- la adaugareElement & stergeElement daca avem pozitie negativa consideram ca
vrem sa adaugam la inceput de lista, iar daca avem poz mai mare decat lungimea
listei vom considera ca adaugam la final
- la comparari testam conditia ceruta pana cand nu mai este respectata sau cand
una din liste se termina, daca conditia impusa ramane adevarata schimbam
conditia in lungimea listei pentru a obtine rezultatul

Exemple:

[0,1] < [0, 2] false (avem primele elemente egale)

[0,1] < [0, 1] false (analog)

[0,1] <= [0, 1] true (toate elementele sunt egale + lungimea lor)

[0, 1] <= [0, 1, 2] true (primele 2 elemente sunt egale, dupa prima lista nu mai
are elemente deci comparam dupa lungime)

## notite

- Am facut cateva teste si am acoperit toate cazurile la care m-am putut gandi.
- Clasa nod este prea mica pentru a o separa in doua fisiere .h si .cpp

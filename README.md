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

## notite

- Am facut cateva teste si am acoperit toate cazurile la care m-am putut gandi.
- Clasa nod este prea mica pentru a o separa in doua fisiere .h si .cpp

## TODO

- momentan programul pare complet, de reverificat maine pentru greseli in gandire,
typo uri si poate cleaning

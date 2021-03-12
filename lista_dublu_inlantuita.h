#ifndef LISTA_DUBLU_INLANTUITA_H
#define LISTA_DUBLU_INLANTUITA_H

#include "nod.cpp"
#include <cassert>
#include <iostream>

class ListaDubluInlantuita {
private:
  Nod *m_head, *m_tail; /* primul si ultimul element din lista */
  Nod *m_iterator;      /* iterator pentru parcurgerea liste */

public:
  /* constructor de initializare fara parametrii */
  ListaDubluInlantuita();
  /* constructor de initializare cu 2 parametrii (headul si tailul) */
  ListaDubluInlantuita(Nod *head, Nod *tail);
  /* destructor */
  ~ListaDubluInlantuita();

  /* getters si setters pentru acces membri privati */
  Nod *getHead() const { return m_head; }
  Nod *getTail() const { return m_tail; }
  /* OBS: inainte de a apela aceasta metoda folositi mai intai metoda
   * resetareIterator() */
  Nod *getIterator() const { return m_iterator; }

  Nod *begin() { return m_head; }
  Nod *end() { return m_tail; }

  void setHead(const Nod *n = nullptr) { m_head = new Nod(n->getInfo()); }
  void setTail(const Nod *n = nullptr) { m_tail = new Nod(n->getInfo()); }

  /* metoda de adaugare a unui element el la pozitia poz  el trebuie sa fie de
   * tip integer poz trebuie sa fie un nr natural, indexarea listei se face de
   * la 0, pentru un poz > lungimea listei vom adauga nodul la final */
  void adaugaElement(int el, int poz);

  /* metoda de stergere a unui element de pe o poziție */
  void stergeElement(int poz);

  /* sterge toate elementele din lista */
  void stergeLista();

  /* obtine lungimea listei */
  int lungime() const;

  /* setam iteratorul la capatul listei */
  void resetareIterator();
  /* inaintam cu iteratorul daca putem */
  void next();
  /* mergem inapoi cu iteratorul daca putem */
  void back();

  void inversareLista();

  /* overlod subscript operator, accesam nodul prin referinta */
  Nod &operator[](int index);

  /* testam pozitiv daca lista este goala */
  bool operator!() const;

  /* overload operator = */
  ListaDubluInlantuita &operator=(const ListaDubluInlantuita &ldi);

  /* supraincarcarea metodei de citire a listei de la tastatura, cerem neaparat
   * ca lista sa contina minim 2 elemente */
  friend std::istream &operator>>(std::istream &in, ListaDubluInlantuita &ldi);

  /* supraincarcarea metodei de afisare a listei (ambele sensuri) in consola */
  friend std::ostream &operator<<(std::ostream &out,
                                  const ListaDubluInlantuita &ldi);

  /* supraincarcarea operatorului +, care sa efectueze concatenarea a doua
   * liste dublu inlantuite, rezultand într-o noua lista dublu inlantuita */
  friend ListaDubluInlantuita &operator+(const ListaDubluInlantuita &l1,
                                         const ListaDubluInlantuita &l2);
  /* supraincare operator +=, rezultatul adunarii dintre lista curenta si o alta
   * lista l1 este salvat in lista curenta, this */
  ListaDubluInlantuita &operator+=(const ListaDubluInlantuita &l1);

  /* operatorul de egalitate, verificam element cu element egalitatea */
  friend bool operator==(const ListaDubluInlantuita &l1,
                         const ListaDubluInlantuita &l2);
  friend bool operator!=(const ListaDubluInlantuita &l1,
                         const ListaDubluInlantuita &l2);

  /* operatori de comparare, comparam element cu element conditia pana cand
   * gasim la o pozitie contradictie, daca ajungem cu cel putin una din liste la
   * final si nu am gasit o contradictie vom considera mai mica lista cu
   * lungimea mai mica */
  friend bool operator<(const ListaDubluInlantuita &l1,
                        const ListaDubluInlantuita &l2);
  friend bool operator<=(const ListaDubluInlantuita &l1,
                         const ListaDubluInlantuita &l2);
  friend bool operator>(const ListaDubluInlantuita &l1,
                        const ListaDubluInlantuita &l2);
  friend bool operator>=(const ListaDubluInlantuita &l1,
                         const ListaDubluInlantuita &l2);

  /* operator de concatenare a listei de n ori, i.e. pentru o lista l si un nr
   * natural x, x ^ n = x + x + ... +x */
  friend ListaDubluInlantuita &operator^(const ListaDubluInlantuita &ldi,
                                         int n);
};

#endif

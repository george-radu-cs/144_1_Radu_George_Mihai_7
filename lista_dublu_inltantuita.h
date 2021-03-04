#ifndef LISTA_DUBLU_INLANTUITA_H
#define LISTA_DUBLU_INLANTUITA_H

#include "nod.cpp"
#include <iostream>

class ListaDubluInlantuita {
private:
  Nod *m_head, *m_tail; /* primul si ultimul element din lista */

public:
  ListaDubluInlantuita();
  ListaDubluInlantuita(Nod *head, Nod *tail);
  ~ListaDubluInlantuita();

  Nod *getHead() { return m_head; }
  Nod *getTail() { return m_tail; }

  void adaugareElement(int el, int poz);

  /* metoda publica de stergere a unui element de pe o poziție */
  void stergeElement(int poz);

  /* sterge toate elementele din lista */
  void stergeLista();

  int lungime();

  friend std::istream &operator>>(std::istream &in, ListaDubluInlantuita &ldi);

  friend std::ostream &operator<<(std::ostream &out, ListaDubluInlantuita &ldi);

  /* supraincarcarea operatorului +, care sa efectueze concatenarea a doua
   * liste dublu inlantuite, rezultand într-o noua lista dublu inlantuita */
  friend ListaDubluInlantuita &operator+(ListaDubluInlantuita &l1,
                                         ListaDubluInlantuita &l2);
};

#endif

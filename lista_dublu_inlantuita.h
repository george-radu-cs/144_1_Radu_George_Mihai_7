#ifndef LISTA_DUBLU_INLANTUITA_H
#define LISTA_DUBLU_INLANTUITA_H

#include "nod.cpp"
#include <iostream>

class ListaDubluInlantuita {
private:
  Nod *m_head, *m_tail; /* primul si ultimul element din lista */
  /* TODO membru sens parcurge + vezi celelalte metode */

public:
  ListaDubluInlantuita();
  ListaDubluInlantuita(Nod *head, Nod *tail);
  ~ListaDubluInlantuita();

  Nod *getHead() { return m_head; }
  Nod *getTail() { return m_tail; }

  void setHead(const Nod *n = nullptr) { m_head = new Nod(n->getInfo()); }
  void setTail(const Nod *n = nullptr) { m_tail = new Nod(n->getInfo()); }

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
  ListaDubluInlantuita &operator+=(ListaDubluInlantuita &l1);

  ListaDubluInlantuita &operator=(ListaDubluInlantuita &ldi);

  friend bool operator==(ListaDubluInlantuita &l1, ListaDubluInlantuita &l2);
  friend bool operator!=(ListaDubluInlantuita &l1, ListaDubluInlantuita &l2);

  int &operator[](int index);

  bool operator!() const;

  /* aici poti face 2 si dupa se le chemi pe restul dar mai bine fa le explicit
   */
  friend bool operator<(ListaDubluInlantuita &l1, ListaDubluInlantuita &l2);
  friend bool operator<=(ListaDubluInlantuita &l1, ListaDubluInlantuita &l2);
  friend bool operator>(ListaDubluInlantuita &l1, ListaDubluInlantuita &l2);
  friend bool operator>=(ListaDubluInlantuita &l1, ListaDubluInlantuita &l2);

  friend ListaDubluInlantuita &operator^(ListaDubluInlantuita &l1,
                                         ListaDubluInlantuita &l2);

  /* TODO membru iterator resetam iteratorul la inceput membru pentru sens
   * parcurgere - metoda next metoda back */

  void schimbareParcurgere();
};

#endif

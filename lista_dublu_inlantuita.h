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

  Nod *getHead() const { return m_head; }
  Nod *getTail() const { return m_tail; }

  Nod *begin() { return m_head; }
  Nod *end() { return m_tail; }

  void setHead(const Nod *n = nullptr) { m_head = new Nod(n->getInfo()); }
  void setTail(const Nod *n = nullptr) { m_tail = new Nod(n->getInfo()); }

  void adaugareElement(int el, int poz);

  /* metoda publica de stergere a unui element de pe o poziție */
  void stergeElement(int poz);

  /* sterge toate elementele din lista */
  void stergeLista();

  /* obtine lungimea listei */
  int lungime() const;

  friend std::istream &operator>>(std::istream &in, ListaDubluInlantuita &ldi);

  friend std::ostream &operator<<(std::ostream &out,
                                  const ListaDubluInlantuita &ldi);

  /* supraincarcarea operatorului +, care sa efectueze concatenarea a doua
   * liste dublu inlantuite, rezultand într-o noua lista dublu inlantuita */
  friend ListaDubluInlantuita &operator+(const ListaDubluInlantuita &l1,
                                         const ListaDubluInlantuita &l2);
  ListaDubluInlantuita &operator+=(ListaDubluInlantuita &l1);

  ListaDubluInlantuita &operator=(const ListaDubluInlantuita &ldi);

  friend bool operator==(const ListaDubluInlantuita &l1,
                         const ListaDubluInlantuita &l2);
  friend bool operator!=(const ListaDubluInlantuita &l1,
                         const ListaDubluInlantuita &l2);

  int &operator[](int index);

  bool operator!() const;

  /* aici poti face 2 si dupa se le chemi pe restul dar mai bine fa le explicit
   */
  friend bool operator<(const ListaDubluInlantuita &l1,
                        const ListaDubluInlantuita &l2);
  friend bool operator<=(const ListaDubluInlantuita &l1,
                         const ListaDubluInlantuita &l2);
  friend bool operator>(const ListaDubluInlantuita &l1,
                        const ListaDubluInlantuita &l2);
  friend bool operator>=(const ListaDubluInlantuita &l1,
                         const ListaDubluInlantuita &l2);

  friend ListaDubluInlantuita &operator^(const ListaDubluInlantuita &l1,
                                         const ListaDubluInlantuita &l2);

  /* TODO membru iterator resetam iteratorul la inceput membru pentru sens
   * parcurgere - metoda next metoda back */

  void schimbareParcurgere();
};

#endif

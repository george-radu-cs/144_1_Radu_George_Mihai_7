#ifndef LISTA_DUBLU_INLANTUITA_H
#define LISTA_DUBLU_INLANTUITA_H

#include "nod.cpp"
#include <iostream>

class ListaDubluInlantuita {
private:
  Nod *m_head, *m_tail; /* primul si ultimul element din lista */

public:
  ListaDubluInlantuita() { /* constructor de initializare */
    m_head = nullptr;
    m_tail = nullptr;
  }
  ListaDubluInlantuita(Nod *head, Nod *tail) {
    m_head = head;
    m_tail = tail;
    m_head->setNext(m_tail);
    m_tail->setPrev(m_head);
  }

  ~ListaDubluInlantuita() {
    Nod *indirect = m_head;
    if (indirect != nullptr) {
      while (indirect != m_tail) {
        indirect = indirect->getNext();
        delete indirect->getPrev();
      }
      delete m_tail;
    }
  }

  Nod *getHead() { return m_head; }
  Nod *getTail() { return m_tail; }

  void adaugareElement(int el, int poz);

  /* metoda publica de stergere a unui element de pe o poziție */
  void stergeElement(int poz);

  friend std::istream &operator>>(std::istream &in, ListaDubluInlantuita &ldi);

  friend std::ostream &operator<<(std::ostream &out, ListaDubluInlantuita &ldi);

  /* supraincarcarea operatorului +, care sa efectueze concatenarea a doua
   * liste dublu inlantuite, rezultand într-o noua lista dublu inlantuita */
  friend ListaDubluInlantuita operator+(ListaDubluInlantuita &l1,
                                        ListaDubluInlantuita &l2);
};

#endif

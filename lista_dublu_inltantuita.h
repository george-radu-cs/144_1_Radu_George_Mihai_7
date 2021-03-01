#ifndef LISTA_DUBLU_INLANTUITA_H
#define LISTA_DUBLU_INLANTUITA_H

#include "nod.cpp"
#include <iostream>

class ListaDubluInlantuita {
private:
  Nod *m_head, *m_tail; /* the first and the last element of the list */

public:
  ListaDubluInlantuita() { /* constructor de initializare */
    m_head = nullptr;
    m_tail = nullptr;
  }
  ListaDubluInlantuita(Nod *head, Nod *tail) {
    m_head = head;
    m_tail = tail;
  }

  /* TODO aici avem o problema intrucat daca facem adunare pastram aceleasi
   * noduri si cand face free la memorie stergem aceleasi noduri de doua ori */
  /* TODO actual problema e ca deja stergem nodurile de la clasa nod si dupa le
   * am sterge si aici? */
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
  /* { */
  /* Nod *newNode = new Nod(el); */
  /* Nod *indirect = m_head; */
  /* if (indirect == nullptr || poz == 0) { */
  /*   newNode->setNext(m_head); */
  /*   if (m_head != nullptr) */
  /*     m_head->setPrev(newNode); */
  /*   m_head = newNode; */
  /*   return; */
  /* } */
  /* while (indirect->getNext() != nullptr && poz != 0) { */
  /*   indirect = indirect->getNext(); */
  /* --poz; */
  /* } */
  /* if (m_tail == nullptr) { */
  /* m_tail = newNode; */
  /* m_head->setNext(m_tail); */
  /* m_tail->setPrev(m_head); */
  /* return; */
  /* } */
  /* /1* if (indirect->getPrev() != nullptr) { *1/ */
  /* if (poz == 0) { /1* punem nr la poz corecta *1/ */
  /* indirect->getPrev()->setNext(newNode); */
  /* newNode->setPrev(indirect->getPrev()); */
  /* /1* } *1/ */
  /* newNode->setNext(indirect); */
  /* indirect->setPrev(newNode); */
  /* } else { /1* s a introdus o pozitie mai mare decat lungimea listei, deci */
  /*           automat vom pune elementul la final *1/ */
  /* m_tail->setNext(newNode); */
  /* newNode->setPrev(m_tail); */
  /* m_tail = newNode; */
  /* } */
  /* } */

  /* metoda publica de stergere a unui element de pe o poziție */
  void stergeElement(int poz);
  /* { */
  /*   if (poz == 0) { /1* e chiar headul *1/ */
  /*     m_head->getNext()->setPrev(nullptr); */
  /*     m_head = m_head->getNext(); */
  /*     return; /1* vrem sa nu mergem mai departe poate muti acest if? TODO?
   * *1/ */
  /*   } */
  /*   Nod *indirect = m_head; */
  /*   while (indirect != nullptr && poz != 0) { */
  /*     indirect = indirect->getNext(); */
  /*     --poz; */
  /*   } */
  /*   if (indirect == m_tail) { */
  /*     m_tail->getPrev()->setNext(nullptr); */
  /*     m_tail = m_tail->getPrev(); */
  /*   } else { */
  /*     indirect->getNext()->setPrev(indirect->getPrev()); */
  /*     indirect->getPrev()->setNext(indirect->getNext()); */
  /*   } */
  /* } */

  friend std::istream &operator>>(std::istream &in, ListaDubluInlantuita &ldi);
  /* { */
  /*   /1* am putea introduce nr de noduri pe care sa le afisam mai intai? *1/
   */
  /*   std::cout << "Nr de noduri: "; */
  /*   int nr_noduri; */
  /*   in >> nr_noduri; */
  /*   int i{0}; */
  /*   int tempInt; */
  /*   while (i < nr_noduri) { */
  /*     /1* Nod *temp = new Nod(); *1/ */
  /*     std::cout << "Nodul " << i << ": "; */
  /*     in >> tempInt; */
  /*     /1* temp->setInfo(tempInt); *1/ */
  /*     ldi.adaugareElement(tempInt, i + 1); */
  /*     ++i; */
  /*   } */

  /*   return in; */
  /* } */

  friend std::ostream &operator<<(std::ostream &out, ListaDubluInlantuita &ldi);
  /* { */
  /*   Nod *indirect = ldi.getHead(); */
  /*   out << "Lista de la cap la coada: "; */
  /*   while (indirect != nullptr) { */
  /*     out << indirect->getInfo() << " "; */
  /*     indirect = indirect->getNext(); */
  /*   } */
  /*   out << "\nLista de la coada la cap: "; */
  /*   indirect = ldi.getTail(); */
  /*   while (indirect != nullptr) { */
  /*     out << indirect->getInfo() << " "; */
  /*     indirect = indirect->getPrev(); */
  /*   } */
  /*   out << '\n'; */

  /*   return out; */
  /* } */

  /* TODO supraincarcarea operatorului +, care sa efectueze concatenarea a doua
   * liste dublu inlantuite, rezultand într-o noua lista dublu inlantuita */
  friend ListaDubluInlantuita operator+(ListaDubluInlantuita &l1,
                                        ListaDubluInlantuita &l2);
  /* { */
  /*   l1.m_tail->setNext(l2.m_head); */
  /*   l2.m_head->setPrev(l1.m_tail); */
  /*   return ListaDubluInlantuita(l1.m_head, l2.m_tail); */
  /* } */
};

#endif

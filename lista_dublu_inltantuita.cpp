#include "lista_dublu_inltantuita.h"

void ListaDubluInlantuita::adaugareElement(int el, int poz) {
  Nod *newNode = new Nod(el);
  Nod *indirect = m_head;
  if (indirect == nullptr || poz == 0) {
    newNode->setNext(m_head);
    if (m_head != nullptr)
      m_head->setPrev(newNode);
    m_head = newNode;
    return;
  }
  while (indirect->getNext() != nullptr && poz != 0) {
    indirect = indirect->getNext();
    --poz;
  }
  if (m_tail == nullptr) {
    m_tail = newNode;
    m_head->setNext(m_tail);
    m_tail->setPrev(m_head);
    return;
  }
  /* if (indirect->getPrev() != nullptr) { */
  if (poz == 0) { /* punem nr la poz corecta */
    indirect->getPrev()->setNext(newNode);
    newNode->setPrev(indirect->getPrev());
    /* } */
    newNode->setNext(indirect);
    indirect->setPrev(newNode);
  } else { /* s a introdus o pozitie mai mare decat lungimea listei, deci
              automat vom pune elementul la final */
    m_tail->setNext(newNode);
    newNode->setPrev(m_tail);
    m_tail = newNode;
  }
}

/* metoda publica de stergere a unui element de pe o poziție */
void ListaDubluInlantuita::stergeElement(int poz) {
  if (poz == 0) { /* e chiar headul */
    m_head->getNext()->setPrev(nullptr);
    m_head = m_head->getNext();
    return; /* vrem sa nu mergem mai departe poate muti acest if? TODO? */
  }
  Nod *indirect = m_head;
  while (indirect != nullptr && poz != 0) {
    indirect = indirect->getNext();
    --poz;
  }
  if (indirect == m_tail) {
    m_tail->getPrev()->setNext(nullptr);
    m_tail = m_tail->getPrev();
  } else {
    indirect->getNext()->setPrev(indirect->getPrev());
    indirect->getPrev()->setNext(indirect->getNext());
  }
}

std::istream &operator>>(std::istream &in, ListaDubluInlantuita &ldi) {
  /* am putea introduce nr de noduri pe care sa le afisam mai intai? */
  std::cout << "Nr de noduri: ";
  int nr_noduri;
  in >> nr_noduri;
  int i{0};
  int tempInt;
  while (i < nr_noduri) {
    /* Nod *temp = new Nod(); */
    std::cout << "Nodul " << i << ": ";
    in >> tempInt;
    /* temp->setInfo(tempInt); */
    ldi.adaugareElement(tempInt, i + 1);
    ++i;
  }

  return in;
}

std::ostream &operator<<(std::ostream &out, ListaDubluInlantuita &ldi) {
  Nod *indirect = ldi.getHead();
  out << "Lista de la cap la coada: ";
  while (indirect != nullptr) {
    out << indirect->getInfo() << " ";
    indirect = indirect->getNext();
  }
  out << "\nLista de la coada la cap: ";
  indirect = ldi.getTail();
  while (indirect != nullptr) {
    out << indirect->getInfo() << " ";
    indirect = indirect->getPrev();
  }
  out << '\n';

  return out;
}

ListaDubluInlantuita operator+(ListaDubluInlantuita &l1,
                               ListaDubluInlantuita &l2) {
  l1.m_tail->setNext(l2.m_head);
  l2.m_head->setPrev(l1.m_tail);
  return ListaDubluInlantuita(l1.m_head, l2.m_tail);
}

#include "lista_dublu_inltantuita.h"

/* metoda publica de adaugare a unui element pe o poziție */
void ListaDubluInlantuita::adaugareElement(int el, int poz) {
  if (poz < 0) /* vom considera poz negative drept primul element */
    poz = 0;

  Nod *newNode = new Nod(el); /* nodul care trebuie adaugat in lista */
  /* vom cauta nodul de la pozitia poz folosind pointerul indirect */
  Nod *indirect = m_head;
  if (indirect == nullptr || poz == 0) { /* adauga nod la inceputul listei */
    newNode->setNext(m_head);
    if (m_head != nullptr)
      m_head->setPrev(newNode);
    m_head = newNode;
    return;
  }
  /* in cazul in care avem un singur nod in lista(adica headul) atunci noul nod
   * va reprezenta tailul */
  if (m_tail == nullptr) {
    m_tail = newNode;
    m_head->setNext(m_tail);
    m_tail->setPrev(m_head);
    return;
  }

  while (indirect->getNext() != nullptr && poz != 0) {
    indirect = indirect->getNext();
    --poz;
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
  if (poz < 0) {
    poz = 0;
  }
  /* vom cauta nodul de la pozitia poz folosind pointerul indirect */
  Nod *indirect = m_head;
  /* ajungem la nodul de la poz, sau in cazul in care pozitia data ca input este
   * mai mare decat lungimea listei vom sterge ultimul element */
  int nr_noduri{0};
  while (indirect != nullptr && poz != nr_noduri) {
    indirect = indirect->getNext();
    nr_noduri++;
  }
  if (indirect == m_head) { /* e chiar headul */
    m_head = m_head->getNext();
    m_head->setPrev(nullptr);
  } else if (indirect == m_tail) { /* trebuie sa stergem coada */
    m_tail = m_tail->getPrev();
    m_tail->setNext(nullptr);
  } else { /* stergem un nod din mijloc */
    indirect->getNext()->setPrev(indirect->getPrev());
    indirect->getPrev()->setNext(indirect->getNext());
  }
  delete indirect;
}

std::istream &operator>>(std::istream &in, ListaDubluInlantuita &ldi) {
  /* rugam utilizatorul sa introduca nr de noduri ale listei */
  int nr_noduri{0};
  while (nr_noduri < 2) {
    std::cout << "Nr de noduri(minim 2): ";
    in >> nr_noduri;
  }

  int i{0};
  int tempInt; /* vom citi valorile nodurilor in aceasta variabila */

  while (i < nr_noduri) {
    /* anuntam utilizatorul ce nod introduce */
    std::cout << "Nodul " << i << ": ";
    in >> tempInt;
    ldi.adaugareElement(tempInt, i + 1);
    ++i;
  }

  return in;
}

/* afisam lista in ambele sensuri */
std::ostream &operator<<(std::ostream &out, ListaDubluInlantuita &ldi) {
  Nod *indirect = ldi.getHead();
  out << "Lista de la cap la coada: ";
  while (indirect != nullptr) {
    out << indirect->getInfo() << "->";
    indirect = indirect->getNext();
  }
  /* folosim \b\b urmat de doua spatii pentru a inlocui sageata -> cu spatiu
   * pentru ultimul nod care nu mai duce catre alt nod */
  out << "\b\b  \nLista de la coada la cap: ";
  indirect = ldi.getTail();
  while (indirect != nullptr) {
    out << indirect->getInfo() << "->";
    indirect = indirect->getPrev();
  }
  out << "\b\b  \n";

  return out;
}

ListaDubluInlantuita &operator+(ListaDubluInlantuita &l1,
                                ListaDubluInlantuita &l2) {
  /* construim o noua lista, headul va fi headul de la l1, si tailul va fi
   * tailul de la l2, de asemenea va trebui sa aduagam legatura dintre
   * tailul lui l1 si headul lui l2*/
  Nod *newHead, *newTail;
  newHead = new Nod(l1.getHead()->getInfo());
  newTail = new Nod(l2.getTail()->getInfo());
  ListaDubluInlantuita *rez = new ListaDubluInlantuita(newHead, newTail);

  /* adaugam elementele lui l2 */
  Nod *indirect = l2.getTail()->getPrev();
  while (indirect != nullptr) {
    rez->adaugareElement(indirect->getInfo(), 1);
    indirect = indirect->getPrev();
  }

  /* adaugam elementele lui l1 */
  indirect = l1.getTail();
  /* avem deja adaugat headul in lista motiv pentru care nu comparam cu null */
  while (indirect != l1.getHead()) {
    rez->adaugareElement(indirect->getInfo(), 1);
    indirect = indirect->getPrev();
  }

  return *rez; /* returnam lista */
}

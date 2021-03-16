#include "lista_dublu_inlantuita.h"

ListaDubluInlantuita::ListaDubluInlantuita() { /* constructor de initializare */
  m_head = nullptr;
  m_tail = nullptr;
  m_iterator = m_head;
}

ListaDubluInlantuita::ListaDubluInlantuita(Nod *head, Nod *tail) {
  if (head != nullptr) {
    m_head = new Nod(head->getInfo());
  } else {
    m_head = nullptr;
  }
  if (head != nullptr) {
    m_tail = new Nod(tail->getInfo());
  } else {
    m_tail = nullptr;
  }

  if (head != nullptr)
    m_head->setNext(m_tail);
  if (tail != nullptr)
    m_tail->setPrev(m_head);
  m_iterator = m_head;
}

ListaDubluInlantuita::ListaDubluInlantuita(const ListaDubluInlantuita &ldi) {
  /* construim o copie dupa lista ldi */
  if (ldi.getHead() != nullptr) { /* daca ldi nu este o lista goala */
    /* adaugam capul si coada listei pentru a se face legatura dubla */
    this->setHead(ldi.getHead());
    this->setTail(ldi.getTail());
    m_head->setNext(m_tail);
    m_tail->setPrev(m_head);

    /* adaugam celelalte elemente din lista de la coada la cap pentru a le
     * adauga mereu pe pozitia 1 */
    Nod *indirect = ldi.getTail()->getPrev();
    while (indirect != ldi.getHead()) { /* nu vrem sa adaugam capul de 2 ori */
      this->adaugaElement(indirect->getInfo(), 1);
      indirect = indirect->getPrev();
    }
  }
}

ListaDubluInlantuita::~ListaDubluInlantuita() {
  Nod *indirect = m_head;
  if (indirect != nullptr) {
    while (indirect != m_tail) {
      indirect = indirect->getNext();
      delete indirect->getPrev();
    }
    delete m_tail;
  }
  m_iterator = nullptr;
}

/* metoda publica de adaugare a unui element pe o poziție */
void ListaDubluInlantuita::adaugaElement(int el, int poz) {
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
    if (m_tail == nullptr)
      m_tail = newNode;
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

  /* daca a ramas un singur element in lista */
  if (m_head == m_tail) {
    delete m_head;
    m_head = nullptr;
    m_tail = nullptr;
    return;
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

void ListaDubluInlantuita::stergeLista() {
  Nod *indirect = m_head;
  if (indirect != nullptr) {
    while (indirect != m_tail) {
      indirect = indirect->getNext();
      delete indirect->getPrev();
    }
  }
  delete indirect;
  m_head = nullptr;
  m_tail = nullptr;
  m_iterator = m_head;
}

int ListaDubluInlantuita::lungime() const {
  int l{0};

  Nod *indirect = m_head;
  while (indirect != nullptr) {
    indirect = indirect->getNext();
    l++;
  }

  delete indirect;
  return l;
}

void ListaDubluInlantuita::resetareIterator() { m_iterator = m_head; }
void ListaDubluInlantuita::next() {
  if (m_iterator != nullptr) {
    m_iterator = m_iterator->getNext();
  }
}
void ListaDubluInlantuita::back() {
  if (m_iterator != nullptr) {
    m_iterator = m_iterator->getPrev();
  }
}

void ListaDubluInlantuita::inversareLista() {
  int lungime = this->lungime();
  if (lungime <= 1) { /* daca lista este goala sau are doar un element nu avem
                         ce modificari sa aducem */
    return;
  }

  /* vom folosi 2 pointeri care vor pleca din capete si vor inversa informatia
   * * pe care o contin nodurile, nu interschimbam nodurile intrucat ar trebui
   * sa schimbam legaturile dintre nodurile alaturate si ar fi un proces
   * costisitor si inutil */
  Nod *left = m_head;
  Nod *right = m_tail;
  int tmp; /* val temporara pentru interschimbarea valorilor */
  while ((left < right) && (left != right)) {
    tmp = left->getInfo();
    left->setInfo(right->getInfo());
    right->setInfo(tmp);
    left = left->getNext();
    right = right->getPrev();
  }
  left = nullptr;
  delete left;
  right = nullptr;
  delete right;
}

/* operatorul [] va returna o referinta catre int-ul de la pozitia index
 * verificam daca avem index out of range  */
Nod &ListaDubluInlantuita::operator[](int index) {
  assert(index >= 0 && index < this->lungime() && "Index out of range.");

  Nod *indirect = nullptr;
  /* indexul trebuie sa fie valid */
  if (index < 0 || index >= this->lungime()) {
    std::cout << "Index out of range\n";

    return *indirect;
  }

  indirect = m_head;
  while (index > 0) {
    indirect = indirect->getNext();
    --index;
  }

  return *indirect;
}

/* verificam daca lista este goala, returnam true daca lista este goala */
bool ListaDubluInlantuita::operator!() const {
  /* daca headul este nul atunci si lista va fi goala */
  if (m_head == nullptr)
    return true;
  else
    return false;
}

ListaDubluInlantuita &
ListaDubluInlantuita::operator=(const ListaDubluInlantuita &ldi) {
  /* stergem lista anterioara din memorie */
  this->stergeLista();

  /* construim o copie dupa lista ldi */
  if (ldi.getHead() != nullptr) { /* daca ldi nu este o lista goala */
    /* adaugam capul si coada listei pentru a se face legatura dubla */
    this->adaugaElement(ldi.getHead()->getInfo(), 0);
    this->adaugaElement(ldi.getTail()->getInfo(), 1);

    /* adaugam celelalte elemente din lista de la coada la cap pentru a le
     * adauga mereu pe pozitia 1 */
    Nod *indirect = ldi.getTail()->getPrev();
    while (indirect != ldi.getHead()) { /* nu vrem sa adaugam capul de 2 ori */
      this->adaugaElement(indirect->getInfo(), 1);
      indirect = indirect->getPrev();
    }

    /* aici avem un pointer pentru headul listei, nu vrem sa il stergem pe
     * acesta motiv pentru care il setam pe nullptr si dupa il stergem */
    indirect = nullptr;
    delete indirect;
  }

  return *this;
}

std::istream &operator>>(std::istream &in, ListaDubluInlantuita &ldi) {
  /* daca lista contine deja elemente, le vom sterge si vom citi alta lista de
   * la user, facem asta pentru a ramane consistenti cu celelalte tipuri de
   * date deja existente */
  ldi.stergeLista();
  /* ldi = ListaDubluInlantuita(); */

  /* rugam utilizatorul sa introduca nr de noduri ale listei */
  int nr_noduri{0};
  while (nr_noduri < 2) {
    std::cout << "Nr de noduri(minim 2): ";
    in >> nr_noduri;
  }

  int index_nod{0};
  int valoare_nod; /* vom citi valorile nodurilor in aceasta variabila */

  while (index_nod < nr_noduri) {
    /* anuntam utilizatorul ce nod introduce */
    std::cout << "Nodul " << index_nod << ": ";
    in >> valoare_nod;
    ldi.adaugaElement(valoare_nod, index_nod + 1);
    ++index_nod;
  }

  return in;
}

/* afisam lista in ambele sensuri */
std::ostream &operator<<(std::ostream &out, const ListaDubluInlantuita &ldi) {
  if (ldi.getHead() == nullptr) {
    std::cout << "Lista este goala.\n";
  } else {
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

    delete indirect;
  }

  return out;
}

ListaDubluInlantuita &operator+(const ListaDubluInlantuita &l1,
                                const ListaDubluInlantuita &l2) {
  /* construim o noua lista, headul va fi headul de la l1, si tailul va fi
   * tailul de la l2, de asemenea va trebui sa aduagam legatura dintre
   * tailul lui l1 si headul lui l2*/
  Nod *newHead = nullptr, *newTail = nullptr;
  ListaDubluInlantuita *rez = new ListaDubluInlantuita();

  /* daca ambele liste au elemente */
  if (l1.getHead() != nullptr && l2.getHead() != nullptr) {
    newHead = new Nod(l1.getHead()->getInfo());
    newTail = new Nod(l2.getTail()->getInfo());

    rez = new ListaDubluInlantuita(newHead, newTail);

    /* adaugam elementele lui l2 */
    Nod *indirect = nullptr;

    indirect = l2.getTail()->getPrev();
    while (indirect != nullptr) {
      rez->adaugaElement(indirect->getInfo(), 1);
      indirect = indirect->getPrev();
    }

    /* adaugam elementele lui l1 */
    indirect = l1.getTail();
    /* avem deja adaugat headul in lista motiv pentru care nu comparam cu null
     */
    while (indirect != l1.getHead()) {
      rez->adaugaElement(indirect->getInfo(), 1);
      indirect = indirect->getPrev();
    }
  } else if (l1.getHead() == nullptr && l2.getHead() != nullptr) {
    /* daca l1 este goala dar l2 nu */
    newHead = new Nod(l2.getHead()->getInfo());
    newTail = new Nod(l2.getTail()->getInfo());
    rez = new ListaDubluInlantuita(newHead, newTail);
    /* } */
    Nod *indirect = l2.getTail()->getPrev();
    while (indirect != l2.getHead()) {
      rez->adaugaElement(indirect->getInfo(), 1);
      indirect = indirect->getPrev();
    }
  } else if (l1.getHead() != nullptr && l2.getHead() == nullptr) {
    /* daca l2 este goala dar l1 nu */
    newHead = new Nod(l1.getHead()->getInfo());
    newTail = new Nod(l1.getTail()->getInfo());
    rez = new ListaDubluInlantuita(newHead, newTail);

    Nod *indirect = l1.getTail()->getPrev();
    while (indirect != l1.getHead()) {
      rez->adaugaElement(indirect->getInfo(), 1);
      indirect = indirect->getPrev();
    }
  }

  return *rez; /* returnam lista */
}

ListaDubluInlantuita &
ListaDubluInlantuita::operator+=(const ListaDubluInlantuita &l1) {
  *this = *this + l1;
  return *this;
}

bool operator==(const ListaDubluInlantuita &l1,
                const ListaDubluInlantuita &l2) {
  /* daca ambele liste sunt goale atunci evident listele sunt egale si nu mai
   * avem ce verifica */
  if (l1.getHead() == nullptr && l2.getHead() == nullptr) {
    return true;
  }

  /* 2 pointeri pentru parcurgerea celor 2 liste */
  Nod *pointer_lista_1 = l1.getHead();
  Nod *pointer_lista_2 = l2.getHead();
  /* vrem sa facem si clean up la final motiv pentru care vom retine intr-o
   * variabila ce va trebui sa returnam si la final vom face clean up si dupa
   * vom returna ce se afla in aceasta variabila */
  bool rezultat_egalitate{true};

  /* cat timp mai avem noduri in lista */
  while (pointer_lista_1 != nullptr && pointer_lista_2 != nullptr) {
    /* daca nodurile curente nu sunt egale nu mai are rost sa verificam restul
     * listelor, stim deja ca listele nu sunt egale */
    if (pointer_lista_1->getInfo() != pointer_lista_2->getInfo()) {
      rezultat_egalitate = false;
      break;
    }

    /* inaintam in ambele liste */
    pointer_lista_1 = pointer_lista_1->getNext();
    pointer_lista_2 = pointer_lista_2->getNext();
  }

  /* daca una dintre liste este goala iar cealalta nu atunci listele nu au cum
   * sa fie egale, sau daca una dintre liste are mai multe elemente decat
   * cealalta */
  if ((pointer_lista_1 == nullptr && pointer_lista_2 != nullptr) ||
      (pointer_lista_1 != nullptr && pointer_lista_2 == nullptr)) {
    rezultat_egalitate = false;
  }

  /* clean up */
  /* verificam sa nu stergem un nod din lista */
  pointer_lista_1 = nullptr;
  delete pointer_lista_1;
  pointer_lista_2 = nullptr;
  delete pointer_lista_2;
  return rezultat_egalitate;
}

bool operator!=(const ListaDubluInlantuita &l1,
                const ListaDubluInlantuita &l2) {
  /* negam rezultatul egalitatii, operator pe care l-am creat deja */
  /* am ales aceasta metoda pentru usurinta in scris + nu mai trebuie facute
   * verificari in plus fata de cele de la == */
  return !(l1 == l2);
}

bool operator<(const ListaDubluInlantuita &l1, const ListaDubluInlantuita &l2) {
  /* daca ambele liste sunt goale atunci evident listele sunt egale si nu mai
   * avem ce verifica */
  if (l1.getHead() == nullptr && l2.getHead() == nullptr) {
    return false;
  }

  /* 2 pointeri pentru parcurgerea celor 2 liste */
  Nod *pointer_lista_1 = l1.getHead();
  Nod *pointer_lista_2 = l2.getHead();
  /* vrem sa facem si clean up la final motiv pentru care vom retine intr-o
   * variabila ce va trebui sa returnam si la final vom face clean up si dupa
   * vom returna ce se afla in aceasta variabila */
  bool rezultat_inegalitate{true};

  /* cat timp mai avem noduri in lista */
  while (pointer_lista_1 != nullptr && pointer_lista_2 != nullptr) {
    /* lista l1 trebuie sa fie mai mica decat l2 element cu element, vom
     * verifica element cu element conditia pana cand gasim un index la care
     * nu se mai respecta conditia, indiferent de ce urmeaza in liste */
    if (pointer_lista_1->getInfo() >= pointer_lista_2->getInfo()) {
      rezultat_inegalitate = false;
      break;
    }

    /* inaintam in ambele liste */
    pointer_lista_1 = pointer_lista_1->getNext();
    pointer_lista_2 = pointer_lista_2->getNext();
  }

  /* daca listele nu au aceeasi lungime dupa verificarea element cu element
   * vom considera lista mai mica cea cu lungimea mai mica */
  if (pointer_lista_1 != nullptr && pointer_lista_2 == nullptr) {
    rezultat_inegalitate = false;
  }

  /* clean up */
  pointer_lista_1 = nullptr;
  delete pointer_lista_1;
  pointer_lista_2 = nullptr;
  delete pointer_lista_2;
  return rezultat_inegalitate;
}

bool operator<=(const ListaDubluInlantuita &l1,
                const ListaDubluInlantuita &l2) {
  /* daca ambele liste sunt goale atunci evident listele sunt egale si nu mai
   * avem ce verifica */
  if (l1.getHead() == nullptr && l2.getHead() == nullptr) {
    return true;
  }

  /* 2 pointeri pentru parcurgerea celor 2 liste */
  Nod *pointer_lista_1 = l1.getHead();
  Nod *pointer_lista_2 = l2.getHead();
  /* vrem sa facem si clean up la final motiv pentru care vom retine intr-o
   * variabila ce va trebui sa returnam si la final vom face clean up si dupa
   * vom returna ce se afla in aceasta variabila */
  bool rezultat_inegalitate{true};

  /* cat timp mai avem noduri in lista */
  while (pointer_lista_1 != nullptr && pointer_lista_2 != nullptr) {
    /* lista l1 trebuie sa fie mai mica decat l2 element cu element, vom
     * verifica element cu element conditia pana cand gasim un index la care
     * nu se mai respecta conditia, indiferent de ce urmeaza in liste */
    if (pointer_lista_1->getInfo() > pointer_lista_2->getInfo()) {
      rezultat_inegalitate = false;
      break;
    }

    /* inaintam in ambele liste */
    pointer_lista_1 = pointer_lista_1->getNext();
    pointer_lista_2 = pointer_lista_2->getNext();
  }

  /* daca listele nu au aceeasi lungime dupa verificarea element cu element
   * vom considera lista mai mica cea cu lungimea mai mica */
  if (pointer_lista_1 != nullptr && pointer_lista_2 == nullptr) {
    rezultat_inegalitate = false;
  }

  /* clean up */
  pointer_lista_1 = nullptr;
  delete pointer_lista_1;
  pointer_lista_2 = nullptr;
  delete pointer_lista_2;
  return rezultat_inegalitate;
}

bool operator>(const ListaDubluInlantuita &l1, const ListaDubluInlantuita &l2) {
  return !(l1 <= l2);
}

bool operator>=(const ListaDubluInlantuita &l1,
                const ListaDubluInlantuita &l2) {
  return !(l1 < l2);
}

ListaDubluInlantuita &operator^(const ListaDubluInlantuita &ldi, int n) {
  ListaDubluInlantuita *rez = new ListaDubluInlantuita;
  while (n > 0) {
    *rez += ldi;
    --n;
  }
  return *rez;
}

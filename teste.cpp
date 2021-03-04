#include "lista_dublu_inltantuita.h"

int main() {
  /* teste clasa nod */
  Nod *n1 = new Nod(0);
  Nod *n2 = new Nod(1);
  std::cout << n1 << " " << n2 << " ";
  Nod *n = new Nod(0);
  std::cout << n << '\n';

  /* testam constructorul de copiere pentru clasa nod */
  Nod *a = new Nod(0), *b = new Nod(1), *c = new Nod(2), *d;
  b->setPrev(a);
  b->setNext(c);
  d = new Nod(*b);
  std::cout << "teste constructor de copiere pentru clasa nod:\n";
  std::cout << "nodul origine: " << b->getPrev()->getInfo() << " "
            << b->getInfo() << " " << b->getNext()->getInfo() << '\n';
  std::cout << "nodul copiat: " << d->getPrev()->getInfo() << " "
            << d->getInfo() << " " << d->getNext()->getInfo() << '\n';
  delete b;
  std::cout << "nodul origine: " << b->getPrev()->getInfo() << " "
            << b->getInfo() << " " << b->getNext()->getInfo() << '\n';
  std::cout << "nodul copiat: " << d->getPrev()->getInfo() << " "
            << d->getInfo() << " " << d->getNext()->getInfo() << '\n';

  /* teste citire nod operator>> si << */
  Nod *nod = new Nod();
  std::cout << "Introduceti valoarea nodului: ";
  std::cin >> nod;
  std::cout << nod << "\n\n";

  /* teste lista_dublu_inltantuita adaugare element sterge element si << */
  ListaDubluInlantuita *ldi = new ListaDubluInlantuita(n1, n2);
  ldi->adaugareElement(3, 0);
  ldi->adaugareElement(4, 2);
  ldi->adaugareElement(5, 2);
  std::cout << *ldi << "\n";

  ldi->stergeElement(0); /* sterge primul element */
  std::cout << *ldi << "\n";

  ldi->stergeElement(3); /* sterge ultimul element */
  std::cout << *ldi << "\n";

  ldi->stergeElement(1); /* sterge un element din mijloc */
  std::cout << *ldi << "\n";
  ldi->stergeElement(1); /* sterge un element din mijloc */
  std::cout << *ldi << "\n";

  ldi->adaugareElement(3, 1);
  std::cout << *ldi << "\n";

  ldi->stergeElement(0);
  std::cout << *ldi << "\n";

  ldi->stergeElement(0);
  /* aici lista va fi goala */
  std::cout << *ldi << "\n";

  ldi->adaugareElement(1, -2);
  std::cout << *ldi << "\n";

  /* teste lista_dublu_inltantuita testare operator<< si >> dar si operator>>
   * de la nod*/
  Nod *nod1 = new Nod(1);
  Nod *nod2 = new Nod(2);
  Nod *nod3 = new Nod(3);
  Nod *nod4 = new Nod(4);
  ListaDubluInlantuita *l1 = new ListaDubluInlantuita(nod1, nod2);
  ListaDubluInlantuita *l2 = new ListaDubluInlantuita(nod3, nod4);
  std::cout << "inainte de adunare:\n" << *l1 << *l2 << '\n';
  ListaDubluInlantuita l3 = *l1 + *l2;
  std::cout << "dupa adunare:\n" << *l1 << *l2 << '\n';
  std::cout << "lista rez:\n" << l3 << "\n";

  ListaDubluInlantuita *l4 = new ListaDubluInlantuita();
  std::cout << "Citim o lista de la user:\n";
  std::cin >> *l4;
  std::cout << *l4;

  /* incercam si fara pointeri */
  ListaDubluInlantuita lista1 = ListaDubluInlantuita();
  ListaDubluInlantuita lista2 = ListaDubluInlantuita();
  std::cin >> lista1 >> lista2;
  std::cout << lista1 << lista2;

  /* teste adunare liste di */
  ListaDubluInlantuita lp1 = ListaDubluInlantuita(nod1, nod2);
  ListaDubluInlantuita lp2 = ListaDubluInlantuita();
  ListaDubluInlantuita lp3;
  lp3 = lp1 + lp2;
  std::cout << "lp1\n" << lp1;
  std::cout << "lp2\n" << lp2;
  std::cout << "lp3\n" << lp3;

  /* testam functia de lungime */
  l1->stergeLista();
  std::cout << *l1;
  std::cout << "Lungimea listei l1 este: " << l1->lungime() << "\n";
  l1->adaugareElement(1, 0);
  std::cout << "Lungimea listei l1 este: " << l1->lungime() << "\n";
  l1->adaugareElement(1, 0);
  std::cout << "Lungimea listei l1 este: " << l1->lungime() << "\n";

  return 0;
}

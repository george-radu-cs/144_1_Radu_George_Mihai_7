#include "lista_dublu_inltantuita.h"

int main() {
  /* teste clasa nod */
  Nod *n1 = new Nod(0);
  Nod *n2 = new Nod(1);
  /* Nod *n3 = new Nod(2); */
  /* Nod *n4 = new Nod(3); */
  /* Nod *n5 = new Nod(4); */
  /* Nod *n6 = new Nod(5); */
  std::cout << n1 << " " << n2 << " ";
  Nod *n = new Nod(0);
  std::cout << n << '\n';

  /* teste citire nod operator>> si << */
  Nod *nod = new Nod();
  std::cin >> nod;
  std::cout << nod;

  /* teste lista_dublu_inltantuita adaugare element sterge element si << */
  n1->setNext(n2);
  n2->setPrev(n1);
  ListaDubluInlantuita *ldi = new ListaDubluInlantuita(n1, n2);
  ldi->adaugareElement(3, 0);
  ldi->adaugareElement(4, 2);
  ldi->adaugareElement(5, 2);
  std::cout << *ldi << "\n";
  ldi->stergeElement(0); /* sterge primul element */

  /*test*/
  /* Nod *indirect = ldi->getTail(); */
  /* std::cout << "Lista de la coada la cap: "; */
  /* indirect = ldi->getTail(); */
  /* while (indirect != ldi->getHead()) { */
  /* std::cout << indirect->getInfo() << " "; */
  /* indirect = indirect->getPrev(); */
  /* } */
  /* std::cout << indirect->getInfo() << " "; */
  /*test*/

  std::cout << *ldi << "\n";

  ldi->stergeElement(3); /* sterge ultimul element */
  std::cout << *ldi << "\n";

  ldi->stergeElement(1); /* sterge un element din mijloc */
  ldi->stergeElement(1); /* sterge un element din mijloc */
  /* ldi->stergeElement(0); */
  std::cout << *ldi << "\n";
  /* mai avem un element */
  /* std::cout << ldi->getHead()->getPrev() << " " << ldi->getHead()->getNext()
   */
  /* << " " << ldi->getTail()->getPrev() << " " */
  /* << ldi->getTail()->getNext() << '\n'; */

  Nod *nod1 = new Nod(1);
  Nod *nod2 = new Nod(2);
  Nod *nod3 = new Nod(3);
  Nod *nod4 = new Nod(4);
  nod1->setNext(nod2);
  nod2->setPrev(nod1);
  nod3->setNext(nod4);
  nod4->setPrev(nod3);
  ListaDubluInlantuita *l1 = new ListaDubluInlantuita(nod1, nod2);
  ListaDubluInlantuita *l2 = new ListaDubluInlantuita(nod3, nod4);
  std::cout << "inainte de adunare:\n" << *l1 << *l2 << '\n';
  ListaDubluInlantuita l3 = *l1 + *l2;
  std::cout << "dupa adunare:\n" << *l1 << *l2 << '\n';
  std::cout << l3 << "\n";

  ListaDubluInlantuita *l4 = new ListaDubluInlantuita();
  /* ce ne facem daca primim input doar de un nod? */
  std::cin >> *l4;
  /* std::cout << l4->getHead()->getInfo(); */
  /* std::cout << l4->getTail()->getInfo(); */
  std::cout << *l4;

  /* incercam si fara pointeri */
  ListaDubluInlantuita lista1 = ListaDubluInlantuita();
  std::cin >> lista1;
  std::cout << lista1;

  return 0;
}

#include "enums.h"
#include "lista_dublu_inlantuita.h"
#include <map>
#include <string>

int main() {
  /* folosim o mapa de la string la un enum class intrucat nu putem folosi la
   * switch case uri bazate pe stringuri, si dorim ca userul sa introduca
   * comenzi de tip string */
  std::map<std::string, Comenzi> mapComenzi{
      {"creare_lista", Comenzi::COMANDA_CREARE_LISTA},
      {"adaugare_nod", Comenzi::COMANDA_ADAUGARE_NOD},
      {"sterge_nod", Comenzi::COMANDA_STERGE_NOD},
      {"aduna_2_liste", Comenzi::COMANDA_ADUNARE_LDI},
      {"lungime_lista", Comenzi::COMANDA_LUNGIME_LISTA},
      {"afiseaza_lista", Comenzi::COMANDA_AFISARE_LISTA},
      {"STOP", Comenzi::COMANDA_STOP_PROGRAM}};

  /* in programul interactiv este greu sa construim variabile dinamic, drept
   * workaround vom folosi un array de liste, si vom ruga userul sa spuna de la
   * inceput cate liste va dori sa foloseasca, listele vor fi indexate pentru
   * user de la 1 pentru usurinta sa */
  int nr_ldi; /* nr de liste */
  std::cout
      << "Introduceti nr. max de liste dublu inltantuite pe care doriti sa le "
         "folositi\n(este ok daca nu le veti folosi pe toate pana la final): ";
  std::cin >> nr_ldi;
  /* array cu listele */
  ListaDubluInlantuita *ldi = new ListaDubluInlantuita[nr_ldi];
  /* retinem ce liste am creat */
  bool *ldi_created = new bool[nr_ldi];
  for (int i = 0; i < nr_ldi; ++i)
    ldi_created[i] = 0;

  std::string comanda{""};

  /* implementare meniu interactiv */
  /* cat timp nu s a primit comanda de stop */
  while (mapComenzi[comanda] != Comenzi::COMANDA_STOP_PROGRAM) {
    /* var folosite pentru a ne asigura ca utilizatorul introduce date valide */
    bool inputComandaFormatCorect{false};

    /* cerem o comanda utilizatorului dintr-o lista fixata + error checking */
    while (!inputComandaFormatCorect) {
      std::cout << "\nComenzi "
                   "posibile:\n->creare_lista\n->adaugare_nod\n->sterge_nod\n->"
                   "aduna_2_liste\n->lungime_lista\n->afiseaza_lista\n->STOP\n"
                   "Introduceti comanda dorita: ";
      std::cin >> comanda;
      inputComandaFormatCorect = (mapComenzi.find(comanda) != mapComenzi.end());
    }

    int index_ldi{-1};
    /* ce liste vom folosi pentru adunarea listelor */
    int index_ldi_1{-1};
    int index_ldi_2{-1};
    int index_ldi_rez{-1};

    switch (mapComenzi[comanda]) {
    case Comenzi::COMANDA_CREARE_LISTA:
      /* citim indexul listei din array pe care vom lucra */
      while (index_ldi < 1 || index_ldi > nr_ldi) {
        std::cout << "Ce lista doriti sa creati? ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi;
      }

      std::cin >> ldi[index_ldi - 1];
      ldi_created[index_ldi - 1] = true;
      break;

    case Comenzi::COMANDA_ADAUGARE_NOD:
      /* citim indexul listei din array pe care vom lucra */
      while (index_ldi < 1 || index_ldi > nr_ldi) {
        std::cout << "In ce lista doriti sa adaugati un nod? ([1," << nr_ldi
                  << "]) ";
        std::cin >> index_ldi;
      }

      if (ldi_created[index_ldi - 1]) { /* daca lista exista */
        int el, poz;
        std::cout << "Valoare nodului pe care doriti sa il inserati: ";
        std::cin >> el;
        std::cout << "Pozitia la care doriti sa inserati nodul: ";
        std::cin >> poz;
        ldi[index_ldi - 1].adaugaElement(el, poz);
      } else
        std::cout
            << "Nu ati creat lista cu indexul " << index_ldi
            << ". Nu avem cum sa adaugam noduri intr-o lista inexistenta.\n";
      break;

    case Comenzi::COMANDA_STERGE_NOD:
      /* citim indexul listei din array pe care vom lucra */
      while (index_ldi < 1 || index_ldi > nr_ldi) {
        std::cout << "In ce lista doriti sa stergeti un nod? ([1," << nr_ldi
                  << "]) ";
        std::cin >> index_ldi;
      }

      if (ldi_created[index_ldi - 1]) { /* daca lista exista */
        int poz;
        std::cout << "Pozitia nodului pe care doriti sa il stergeti: ";
        std::cin >> poz;
        ldi[index_ldi - 1].stergeElement(poz);
      } else
        std::cout
            << "Nu ati creat lista cu indexul " << index_ldi
            << ". Nu avem cum sa stergem noduri dintr-o lista inexistenta.\n";
      break;

    case Comenzi::COMANDA_ADUNARE_LDI:
      /* citim indexul listei din array pe care vom lucra */
      while (index_ldi_1 < 1 || index_ldi_1 > nr_ldi || index_ldi_2 < 1 ||
             index_ldi_2 > nr_ldi) {
        std::cout << "Ce liste doriti sa adaugati? ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi_1 >> index_ldi_2;
      }
      while (index_ldi_rez < 1 || index_ldi_rez > nr_ldi) {
        std::cout << "In ce lista doriti sa salvati rezultatul? ([1," << nr_ldi
                  << "]) ";
        std::cin >> index_ldi_rez;
      }

      ldi[index_ldi_rez - 1] = ldi[index_ldi_1 - 1] + ldi[index_ldi_2 - 1];
      ldi_created[index_ldi_rez - 1] = true;
      break;

    case Comenzi::COMANDA_LUNGIME_LISTA:
      /* citim indexul listei din array pe care vom lucra */
      while (index_ldi < 1 || index_ldi > nr_ldi) {
        std::cout << "Pentru ce lista doriti sa afisati lungimea? ([1,"
                  << nr_ldi << "]) ";
        std::cin >> index_ldi;
      }

      std::cout << "Lungimea listei " << index_ldi << " este "
                << ldi[index_ldi - 1].lungime() << ".\n";

      break;

    case Comenzi::COMANDA_AFISARE_LISTA:
      /* citim indexul listei din array pe care vom lucra */
      while (index_ldi < 1 || index_ldi > nr_ldi) {
        std::cout << "Ce lista doriti sa afisati? ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi;
      }

      std::cout << ldi[index_ldi - 1] << "\n";
      break;

    default:
      break;
    }
  }

  /* clean up */
  delete[] ldi;

  return 0;
}

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
      {"adauga_nod", Comenzi::COMANDA_ADAUGA_NOD},
      {"sterge_nod", Comenzi::COMANDA_STERGE_NOD},
      {"sterge_lista", Comenzi::COMANDA_STERGE_LISTA},
      {"lungime_lista", Comenzi::COMANDA_LUNGIME_LISTA},
      {"inversare_lista", Comenzi::COMANDA_INVERSARE_LISTA},
      {"v_operator_indice", Comenzi::COMANDA_VERIFICARE_OPERATOR_INDICE},
      {"v_lista_goala", Comenzi::COMANDA_VERIFICA_LISTA_GOALA},
      {"v_2_liste_egale", Comenzi::COMANDA_VERIFICA_2_LISTE_EGALE},
      {"v_2_liste_non_egale", Comenzi::COMANDA_VERIFICA_2_LISTE_NON_EGALE},
      {"v_operator_mai_mic", Comenzi::COMANDA_VERIFICA_OP_MAI_MIC},
      {"v_operator_mai_mic_egal", Comenzi::COMANDA_VERIFICA_OP_MAI_MIC_EGAL},
      {"v_operator_mai_mare", Comenzi::COMANDA_VERIFICA_OP_MAI_MARE},
      {"v_operator_mai_mare_egal", Comenzi::COMANDA_VERIFICA_OP_MAI_MARE_EGAL},
      {"afiseaza_lista", Comenzi::COMANDA_AFISARE_LISTA},
      {"afiseaza_lista_iterator",
       Comenzi::COMANDA_AFISARE_LISTA_FOLOSIND_ITERATOR},
      {"aduna_2_liste", Comenzi::COMANDA_ADUNARE_LDI},
      {"concatenare", Comenzi::COMANDA_CONCATENARE},
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
                   "posibile:\n->creare_lista\n->adauga_nod\n->sterge_nod\n->"
                   "sterge_lista\n->lungime_lista\n->inversare_lista\n"
                   "->v_operator_indice\n->v_lista_goala\n->v_2_liste_egale\n"
                   "->v_2_liste_non_egale\n->v_operator_mai_mic\n->v_operator_"
                   "mai_mic_egal\n->v_operator_mai_mare\n->v_operator_mai_mare_"
                   "egal\n->afiseaza_lista\n->afiseaza_lista_iterator\n->aduna_"
                   "2_liste\n->concatenare\n->STOP\n"
                   "Introduceti comanda dorita: ";
      std::cin >> comanda;
      inputComandaFormatCorect = (mapComenzi.find(comanda) != mapComenzi.end());
    }

    int index_ldi{-1};
    /* ce liste vom folosi pentru adunarea listelor */
    int index_ldi_1{-1};
    int index_ldi_2{-1};
    int index_ldi_rez{-1};
    int index_nod{-1};
    int lungime_lista{-1};
    int n{-1};

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

    case Comenzi::COMANDA_ADAUGA_NOD:
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

    case Comenzi::COMANDA_STERGE_LISTA:
      /* citim indexul listei din array pe care vom lucra */
      while (index_ldi < 1 || index_ldi > nr_ldi) {
        std::cout << "Ce lista doriti sa stergeti? ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi;
      }

      ldi[index_ldi - 1].stergeLista();

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

    case Comenzi::COMANDA_INVERSARE_LISTA:
      /* citim indexul listei din array pe care vom lucra */
      while (index_ldi < 1 || index_ldi > nr_ldi) {
        std::cout << "Ce lista doriti sa inversati? ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi;
      }

      ldi[index_ldi - 1].inversareLista();

      break;

    case Comenzi::COMANDA_VERIFICARE_OPERATOR_INDICE:
      /* citim indexul listei din array pe care vom lucra */
      while (index_ldi < 1 || index_ldi > nr_ldi) {
        std::cout
            << "Pentru ce lista doriti sa verificati operatorul indice? ([1,"
            << nr_ldi << "]) ";
        std::cin >> index_ldi;
      }
      lungime_lista = ldi[index_ldi - 1].lungime() - 1;
      while (index_nod < 0 || index_nod > lungime_lista) {
        std::cout << "Indexul nodului: ([0," << lungime_lista << "])";
        std::cin >> index_nod;
      }

      std::cout << "Nodul cerut are valoarea: " << ldi[index_ldi - 1][index_nod]
                << '\n';

      break;

    case Comenzi::COMANDA_VERIFICA_LISTA_GOALA:
      /* citim indexul listei din array pe care vom lucra */
      while (index_ldi < 1 || index_ldi > nr_ldi) {
        std::cout << "Ce lista doriti sa verificati daca este goala? ([1,"
                  << nr_ldi << "]) ";
        std::cin >> index_ldi;
      }

      if (!ldi[index_ldi - 1]) {
        std::cout << "Lista este goala.\n";
      } else {
        std::cout << "Lista nu este goala.\n";
      }

      break;

    case Comenzi::COMANDA_VERIFICA_2_LISTE_EGALE:
      while (index_ldi_1 < 1 || index_ldi_1 > nr_ldi) {
        std::cout << "Introduceti nr listei 1 ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi_1;
      }
      while (index_ldi_2 < 1 || index_ldi_2 > nr_ldi) {
        std::cout << "Introduceti nr listei 2 ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi_2;
      }

      if (ldi[index_ldi_1 - 1] == ldi[index_ldi_2 - 1]) {
        std::cout << "Cele doua liste sunt egale.\n";
      } else {
        std::cout << "Cele doua liste nu sunt egale.\n";
      }

      break;

    case Comenzi::COMANDA_VERIFICA_2_LISTE_NON_EGALE:
      while (index_ldi_1 < 1 || index_ldi_1 > nr_ldi) {
        std::cout << "Introduceti nr listei 1 ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi_1;
      }
      while (index_ldi_2 < 1 || index_ldi_2 > nr_ldi) {
        std::cout << "Introduceti nr listei 2 ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi_2;
      }

      if (ldi[index_ldi_1 - 1] != ldi[index_ldi_2 - 1]) {
        std::cout << "Cele doua liste nu sunt egale.\n";
      } else {
        std::cout << "Cele doua liste sunt egale.\n";
      }

      break;

    case Comenzi::COMANDA_VERIFICA_OP_MAI_MIC:
      while (index_ldi_1 < 1 || index_ldi_1 > nr_ldi) {
        std::cout << "Introduceti nr listei 1 ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi_1;
      }
      while (index_ldi_2 < 1 || index_ldi_2 > nr_ldi) {
        std::cout << "Introduceti nr listei 2 ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi_2;
      }

      if (ldi[index_ldi_1 - 1] < ldi[index_ldi_2 - 1]) {
        std::cout << "Lista " << index_ldi_1 << " este mai mica decat lista "
                  << index_ldi_2 << ".\n";
      } else {
        std::cout << "Lista " << index_ldi_1 << " nu este mai mica decat lista "
                  << index_ldi_2 << ".\n";
      }

      break;

    case Comenzi::COMANDA_VERIFICA_OP_MAI_MIC_EGAL:
      while (index_ldi_1 < 1 || index_ldi_1 > nr_ldi) {
        std::cout << "Introduceti nr listei 1 ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi_1;
      }
      while (index_ldi_2 < 1 || index_ldi_2 > nr_ldi) {
        std::cout << "Introduceti nr listei 2 ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi_2;
      }

      if (ldi[index_ldi_1 - 1] <= ldi[index_ldi_2 - 1]) {
        std::cout << "Lista " << index_ldi_1
                  << " este mai mica sau egala decat lista " << index_ldi_2
                  << ".\n";
      } else {
        std::cout << "Lista " << index_ldi_1
                  << " nu este mai mica sau egala decat lista " << index_ldi_2
                  << ".\n";
      }

      break;

    case Comenzi::COMANDA_VERIFICA_OP_MAI_MARE:
      while (index_ldi_1 < 1 || index_ldi_1 > nr_ldi) {
        std::cout << "Introduceti nr listei 1 ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi_1;
      }
      while (index_ldi_2 < 1 || index_ldi_2 > nr_ldi) {
        std::cout << "Introduceti nr listei 2 ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi_2;
      }

      if (ldi[index_ldi_1 - 1] > ldi[index_ldi_2 - 1]) {
        std::cout << "Lista " << index_ldi_1 << " este mai mare decat lista "
                  << index_ldi_2 << ".\n";
      } else {
        std::cout << "Lista " << index_ldi_1 << " nu este mai mare decat lista "
                  << index_ldi_2 << ".\n";
      }

      break;

    case Comenzi::COMANDA_VERIFICA_OP_MAI_MARE_EGAL:
      while (index_ldi_1 < 1 || index_ldi_1 > nr_ldi) {
        std::cout << "Introduceti nr listei 1 ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi_1;
      }
      while (index_ldi_2 < 1 || index_ldi_2 > nr_ldi) {
        std::cout << "Introduceti nr listei 2 ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi_2;
      }

      if (ldi[index_ldi_1 - 1] >= ldi[index_ldi_2 - 1]) {
        std::cout << "Lista " << index_ldi_1
                  << " este mai mare sau egala decat lista " << index_ldi_2
                  << ".\n";
      } else {
        std::cout << "Lista " << index_ldi_1
                  << " nu este mai mare sau egala decat lista " << index_ldi_2
                  << ".\n";
      }

      break;

    case Comenzi::COMANDA_AFISARE_LISTA:
      /* citim indexul listei din array pe care vom lucra */
      while (index_ldi < 1 || index_ldi > nr_ldi) {
        std::cout << "Ce lista doriti sa afisati? ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi;
      }

      std::cout << ldi[index_ldi - 1] << "\n";

      break;

    case Comenzi::COMANDA_AFISARE_LISTA_FOLOSIND_ITERATOR:
      /* citim indexul listei din array pe care vom lucra */
      while (index_ldi < 1 || index_ldi > nr_ldi) {
        std::cout << "Ce lista doriti sa afisati? ([1," << nr_ldi << "]) ";
        std::cin >> index_ldi;
      }

      ldi[index_ldi - 1].resetareIterator();
      Nod *it;
      if (it != nullptr) {
        for (it = ldi[index_ldi - 1].getIterator(); it != nullptr;
             ldi[index_ldi - 1].next(), it = ldi[index_ldi - 1].getIterator()) {
          std::cout << *it << " ";
        }
        std::cout << '\n';
      } else {
        std::cout << "Lista este goala.\n";
      }

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

    case Comenzi::COMANDA_CONCATENARE:
      while (index_ldi_1 < 1 || index_ldi_1 > nr_ldi) {
        std::cout
            << "Introduceti nr listei pe care doriti sa o concatenati ([1,"
            << nr_ldi << "]) ";
        std::cin >> index_ldi_1;
      }
      while (n < 0) {
        std::cout
            << "Introduceti de cate ori doriti sa concatenati lista \n(ATENTIE "
               "daca introduceti 0 atunci rezultatul va fi o lista goala) :";
        std::cin >> n;
      }
      while (index_ldi_2 < 1 || index_ldi_2 > nr_ldi) {
        std::cout
            << "Introduceti nr listei unde doriti sa salvati rezultatul ([1,"
            << nr_ldi << "]) ";
        std::cin >> index_ldi_2;
      }

      ldi[index_ldi_2 - 1] = ldi[index_ldi_1 - 1] ^ n;

      break;

    default:
      /* putem ajunge aici decat daca a fost introdusa comanda STOP, care va
       * opri loop ul */
      break;
    }
  }

  /* clean up */
  delete[] ldi;

  return 0;
}

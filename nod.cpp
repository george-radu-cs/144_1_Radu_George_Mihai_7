#ifndef NOD_H
#define NOD_H

#include <iostream>

class Nod {
private:
  int m_info;
  Nod *m_prev;
  Nod *m_next;

public:
  Nod() { /* constuctor de initializare */
    m_prev = nullptr;
    m_next = nullptr;
  }

  Nod(int info)
      : m_info{info} { /* constructor de initializare cu un parametru */
    m_prev = nullptr;
    m_next = nullptr;
  }

  Nod(int info, Nod *prev, Nod *next)
      : m_info{info} { /* constructor de initializare cu 3 parametrii */
    m_prev = prev;
    m_next = next;
  }

  /* constructor de copiere */
  Nod(const Nod &n) : m_info{n.m_info}, m_prev{n.m_prev}, m_next{n.m_next} {}

  ~Nod() {
    /* int este o primitva, iar celelalte var sunt pointeri catre alte noduri
     * nu am vrea sa le stergem atunci cand stergem acest nod, intrucat nu asta
     * ar fi intentia noastra, poate mai avem nevoie de ele sau sunt folosite in
     * alta parte, in alt context etc. */
  }

  /* getters si setters pentru a accesa datele clasei */
  int getInfo() const { return m_info; }
  Nod *getPrev() { return m_prev; }
  Nod *getNext() { return m_next; }

  void setInfo(int info) { m_info = info; }
  void setPrev(Nod *prev) { m_prev = prev; }
  void setNext(Nod *next) { m_next = next; }

  /* supraincarea metodei de afisare a unui nod in consola */
  friend std::ostream &operator<<(std::ostream &out, const Nod &nod) {
    out << nod.m_info;
    return out;
  }

  /* supraincarea metodei de citire a unui nod din consola */
  friend std::istream &operator>>(std::istream &in, Nod &nod) {
    in >> nod.m_info;
    return in;
  }
};

#endif

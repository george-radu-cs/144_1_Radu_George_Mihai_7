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
  Nod(int info) : m_info{info} {
    m_prev = nullptr;
    m_next = nullptr;
  }
  Nod(int info, Nod *prev, Nod *next) : m_info{info} {
    m_prev = prev;
    m_next = next;
  }
  ~Nod() { /* this nullptr; */
  }

  int getInfo() { return m_info; }
  Nod *getPrev() { return m_prev; }
  Nod *getNext() { return m_next; }

  void setInfo(int info) { m_info = info; }
  void setPrev(Nod *prev) { m_prev = prev; }
  void setNext(Nod *next) { m_next = next; }

  friend std::ostream &operator<<(std::ostream &out, Nod *nod) {
    out << nod->m_info;
    return out;
  }

  friend std::istream &operator>>(std::istream &in, Nod *nod) {
    in >> nod->m_info;
    return in;
  }
};

#endif

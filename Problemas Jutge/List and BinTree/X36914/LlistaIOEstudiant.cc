#include "LlistaIOEstudiant.hh"

void  LlegirLlistaEstudiant(list<Estudiant>& l) {
    list<Estudiant>::iterator it = l.end();
    Estudiant element;
    element.llegir();
    while (element.consultar_DNI() != 0 and element.consultar_nota() != 0) {
        l.insert(it, element);
        element.llegir();
    }
}

void EscriureLlistaEstudiant(list<Estudiant>& l) {
    if (not l.empty()) {
        list<Estudiant>::iterator it1 = l.begin();
        while (it1 != l.end()) {
            (*it1).escriure();
            ++it1;
        }
    }
}
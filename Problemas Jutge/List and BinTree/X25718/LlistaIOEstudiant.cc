#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l) {
    Estudiant e;
    e.llegir();
    while (e.consultar_DNI() != 0) {
        l.insert(l.end(), e);
        e.llegir();
    }
}

void EscriureLlistaEstudiant(const list<Estudiant>& l) {
    if (not l.empty()) {
        list<Estudiant>::const_iterator it = l.begin();
        while (it != l.end()) {
            it->escriure();
            ++it;
        }
    }
}
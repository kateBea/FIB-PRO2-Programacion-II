#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l) {
    list<ParInt>::iterator it = l.end();
    ParInt elem;
    while (elem.llegir()) {
        l.insert(it, elem);
    }
}

void EscriureLlistaParInt(const list<ParInt>& l) {
    if (not l.empty()) {
        list<ParInt>::const_iterator it1 = l.begin();
        while (it1 != l.end()) {
            it1->escriure();
            ++it1;
        }
    }
}
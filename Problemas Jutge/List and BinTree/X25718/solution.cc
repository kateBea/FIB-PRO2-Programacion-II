// X25718   CERCA EN UNA LLISTA D'ESTUDIANTS AMB ESBORRAT

#include "LlistaIOEstudiant.hh"
#include "solution.hh"

void esborra_tots(list<Estudiant> &t, int x) {
    if (not t.empty()) {
        list<Estudiant>::iterator it = t.begin();
        while (not t.empty() and it != t.end()) {
            if (it->consultar_DNI() == x) {
                it = t.erase(it);
            }
            else 
                ++it;
        }
    }
}
#ifndef LISTA_PARINT_HH
#define LISTA_PARINT_HH

#include <list>
#include "ParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l);
// Pre: l és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)

void EscriureLlistaParInt(const list<ParInt>& l);
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l

#endif

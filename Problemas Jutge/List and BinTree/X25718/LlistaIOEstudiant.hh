#ifndef LISTA_ESTUD_HH
#define LISTA_ESTUD_HH

#include <list>
#include "Estudiant.hh"
using namespace std;

void LlegirLlistaEstudiant(list<Estudiant>& l);
// Pre: l és buida; el canal estandar d’entrada conté parelles
// de valors <enter, double>, acabat per un parell 0 x (qualsevol double)
// Post: s’han afegit al final de l els estudiants llegits fins al 0 x (no inclòs)

void EscriureLlistaEstudiant(const list<Estudiant>& l);
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l

#endif
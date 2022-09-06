#include "CuaIOParInt.hh"

void llegirCuaParInt(queue<ParInt>& c)
// Pre: c és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han encuat a c els elements llegits fins al 0 0 (no inclos)
{
    ParInt a;
    while (a.llegir()) {
        c.push(a);
    }
}

void escriureCuaParInt(queue<ParInt> c)
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de c
{
    while (not c.empty()) {
        c.front().escriure();
        c.pop();
    }
}
// X74882   ACTUALITZAR UN CONJUNT D'ESTUDIANTS

#include <iostream>
#include <vector>
#include "Cjt_estudiants.hh"
using namespace std;

int main() {
    Cjt_estudiants a;
    Cjt_estudiants b;
    a.llegir();
    b.llegir();
    
    int mida_primer_conjunt = a.mida();

    for (int i = 1; i <= mida_primer_conjunt; ++i) {
        Estudiant sample = a.consultar_iessim(i);
        if (b.existeix_estudiant(sample.consultar_DNI())) {
            Estudiant c = b.consultar_estudiant(sample.consultar_DNI());
            if (c.te_nota() and sample.te_nota()) {
                bool est_b_mes_nota = c.consultar_nota() > sample.consultar_nota();
                if (est_b_mes_nota) {
                    a.modificar_iessim(i, c);
                }
            }
            else if (not sample.te_nota()) {
                if (c.te_nota()) a.modificar_iessim(i, c);
            }
        }
        
    }

    a.escriure();

    return 0;
}
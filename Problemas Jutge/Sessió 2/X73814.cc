// X73814   SIMPLIFICACIÓ D'UN VECTOR D'ESTUDIANTS AGRUPATS

#include <iostream>
#include "Estudiant.hh"
#include <vector>

typedef vector<Estudiant> Students;

int main() {
    int n;
    cin >> n; 
    Students entrada(n);
    for (int i = 0; i < n; ++i) {
        entrada[i].llegir();
    }

    Students sortida;
    Estudiant sample;
    sample = entrada[0];
    for (int i = 1; i < n; ++i) {
        bool have_same_dni = sample.consultar_DNI() == entrada[i].consultar_DNI();
        if (have_same_dni) {
            //si los dos estudiantes tienen el mismo dni
            //basta con ver si el siguiente tiene nota
            if (entrada[i].te_nota()) {
                if (sample.te_nota()) {
                    bool is_larger = sample.consultar_nota() < entrada[i].consultar_nota();
                    if (is_larger) {
                        sample.modificar_nota(entrada[i].consultar_nota());
                    }
                }
                else {
                    sample.afegir_nota(entrada[i].consultar_nota());
                }
            }
            //si el siguiente no tiene nota no hace falta )
            //hacer ninguna modificacion
        }
        else {
            sortida.push_back(sample);
            sample = entrada[i];
        }
    }
    sortida.push_back(sample);

    for (int j = 0; j < sortida.size(); ++j) {
        sortida[j].escriure();
    }

    return 0;
}

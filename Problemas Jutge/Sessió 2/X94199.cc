// SIMPLIFICACIÓ D'UN VECTOR D'ESTUDIANTS AGRUPATS, MODIFICACIÓ

#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

void simplificar_vector(vector<Estudiant>& v, int& pos) 
    /* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
    /* Post: pos+1 es el nombre d'estudiants diferents de V; cada estudiant de V
    nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
    ordre que a V */
{
    int n = v.size();
	pos = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i].consultar_DNI() != v[i - 1].consultar_DNI()) {
            ++pos;
            v[pos] = v[i];
        }
        else if (v[i].te_nota()) {
            if (not v[pos].te_nota()) {
                v[pos].afegir_nota(v[i].consultar_nota());
            }
            else if (v[i].consultar_nota() > v[pos].consultar_nota()) {
                v[pos].modificar_nota(v[i].consultar_nota());
            }
        }
    }
}

/*
int main(){
    int n;
    cin >> n;
    vector<Estudiant> Students(n);
    for (int i = 0; i < n; ++i) {
        Students[i].llegir();
    }
    int m = 0;
    simplificar_vector(Students, m);
    cout << "Estudiantes diferentes: ";
    cout << m << endl;
    for (int j = 0; j < n; ++j) {
        Students[j].escriure();
    }

    return 0;
}
*/

// X39577   MITJANES SELECTIVES

#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

// funcio que calcula la mitjana de les notes del vector nota_assig
// de les posicions indicades al vector selected_notas
double compute_mit(const vector<double>& nota_assig, const vector<int>& selected_notas) {
    int n = selected_notas.size();
    double suma = 0;
    for (int i = 0; i < n; ++i) {
        suma += nota_assig[selected_notas[i] - 1];
    }
    return suma / double(n);
} 

int main() {
    int nom_estudiants;
    int nom_assignatures;
    int nom_assignatures_select;
    
    cin >> nom_estudiants >> nom_assignatures;
    cin >> nom_assignatures_select;

    vector<int> selected(nom_assignatures_select);
    vector<Estudiant> sortida;

    for (int f = 0; f < selected.size(); ++f) 
        cin >> selected[f];

    vector<Estudiant> Students(nom_estudiants);

    for (int i = 0; i < nom_estudiants; ++i) {
        Students[i].llegir();
        vector<double> notes(nom_assignatures);
        notes[0] = Students[i].consultar_nota();
        for (int j = 1; j < notes.size(); ++j) {
            cin >> notes[j];
        }
        double mitjana = compute_mit(notes, selected);
        Students[i].modificar_nota(mitjana);
        sortida.push_back(Students[i]);
    }

    for (int i = 0; i < sortida.size(); ++i) {
        sortida[i].escriure();
    }

    return 0;
}
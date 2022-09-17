// X19134   CERCA EN UNA LLISTA DE PARELLS D'ENTERS

#include "LlistaIOParInt.hh"

int main() {
    int N;
    list<ParInt> conjunt;
    LlegirLlistaParInt(conjunt);

    cin >> N;

    list<ParInt>::const_iterator pointer = conjunt.begin();
    int sumComp = 0;
    int occs = 0;

    while (pointer != conjunt.end()) {
        if (pointer->primer() == N) {
            sumComp += pointer->segon();
            ++occs;
        }
        ++pointer;
    }
    cout << N << ' ' << occs << ' ' << sumComp << endl;

    return 0;
}
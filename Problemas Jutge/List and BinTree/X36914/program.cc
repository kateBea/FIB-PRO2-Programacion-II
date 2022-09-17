// X36914   CERCA EN UNA LLISTA D'ESTUDIANTS

#include "LlistaIOEstudiant.hh"

int main() {
    int dni_sample;
    list<Estudiant> Students;
    LlegirLlistaEstudiant(Students);
    list<Estudiant>::iterator punter;

    cin >> dni_sample;
    
    int contador = 0;
    for (punter = Students.begin(); punter != Students.end(); ++punter) {
        if ((*punter).consultar_DNI() == dni_sample) {
            contador+=1;
        }
    }
    cout << dni_sample << ' ' << contador << endl;

    return 0;
}
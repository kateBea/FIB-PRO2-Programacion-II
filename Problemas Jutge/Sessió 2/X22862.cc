// X22862   GESTIÓN INTEGRAL DE UN CONJUNTO DE ESTUDIANTES

#include <iostream>
#include "Cjt_estudiants.hh"
using namespace std;

const int MARCA_FINAL_PROGRAMA = -6;

// Pre: -
// Post: r redondeao respecto valor incial
double redondear(double r)
{
    return int(10. * (r + 0.05)) / 10.0;
}

int main()
{
    Cjt_estudiants InputStudents;
    InputStudents.llegir();
    int operation;
    
    cin >> operation;

    /*  Operaciones:

        1 -> anyadir nuevo estudiante
        2 -> consultar la nota de un estudiante a partir de su DNI
        3 -> modificar la nota de un estudiante
        4 -> redondear la nota, a la décima más cercana, a todos los estudiantes del conjunto
        5 -> escribir el conjunto de estudiantes
        6 -> Finaliza programa
    */

    while (operation != MARCA_FINAL_PROGRAMA)
    {
        ////////////////////////
        if (operation == -1)
        {
            Estudiant a_afegir;
            a_afegir.llegir();
            if (InputStudents.existeix_estudiant(a_afegir.consultar_DNI()))
            {
                cout << "el estudiante " << a_afegir.consultar_DNI() << " ya estaba" << endl
                     << endl;
            }
            else if (InputStudents.mida() == InputStudents.mida_maxima())
            {
                cout << "el conjunto esta lleno" << endl
                     << endl;
            }
            else
                InputStudents.afegir_estudiant(a_afegir);
        }
        ///////////////////////////
        else if (operation == -2)
        {
            int identifier;
            cin >> identifier;
            if (not InputStudents.existeix_estudiant(identifier))
            {
                cout << "el estudiante " << identifier 
                    << " no esta" << endl<< endl;
            }
            else
            {
                if (InputStudents.consultar_estudiant(identifier).te_nota())
                {
                    cout << "el estudiante " << identifier << " tiene nota ";
                    cout << InputStudents.consultar_estudiant(identifier).consultar_nota() << endl
                         << endl;
                }
                else
                    cout << "el estudiante " << identifier << " no tiene nota" << endl
                         << endl;
            }
        }
        else if (operation == -3)
        {
            Estudiant entrada;
            entrada.llegir();
            if (InputStudents.existeix_estudiant(entrada.consultar_DNI()))
            {
                InputStudents.modificar_estudiant(entrada);
            }
            else
                cout << "el estudiante " << entrada.consultar_DNI() 
                    << " no esta" << endl<< endl;
        }
        else if (operation == -4)
        {
            int num_est = InputStudents.mida();
            for (int i = 1; i <= num_est; ++i)
            {
                if (InputStudents.consultar_iessim(i).te_nota())
                {
                    Estudiant sample = InputStudents.consultar_iessim(i);
                    sample.modificar_nota(redondear(sample.consultar_nota()));
                    InputStudents.modificar_iessim(i, sample);
                }
            }
        }
        else if (operation == -5)
        {
            InputStudents.escriure();
            cout << endl;
        }
        cin >> operation;
    }

    return 0;
}
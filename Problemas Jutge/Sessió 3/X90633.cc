// X90633 CONTROL - TORN 1 (PRIMAVERA 2015)

#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &b)
{
    int i = cerca_dicot(vest, 0, nest - 1, est.consultar_DNI());
    b = vest[i].consultar_DNI() == est.consultar_DNI();
    if (not b)
    {
        int j = nest;
        while (j > i)
        {
            vest[j] = vest[j - 1];
            --j;
        }
        vest[i] = est;
        ++nest;
        if (est.te_nota())
        {
            suma_notes += est.consultar_nota();
            ++nest_amb_nota;
        }
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool &b)
{
    int posicioDni = cerca_dicot(vest, 0, nest - 1, dni);
    b = (posicioDni < nest) and (vest[posicioDni].consultar_DNI() == dni);
    if (b)
    {
        if (vest[posicioDni].te_nota())
        {
            suma_notes -= vest[posicioDni].consultar_nota();
            --nest_amb_nota;
        }
        while (posicioDni < (nest - 1))
        {
            vest[posicioDni] = vest[posicioDni + 1];
            ++posicioDni;
        }
        --nest;
    }
}

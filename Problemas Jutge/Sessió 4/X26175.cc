// X26175   CONTROL - TORN 1 (TARDOR 2015)

#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &b)
{
    int j = cerca_dicot(vest, 0, nest - 1, est.consultar_DNI());
    b = vest[j].consultar_DNI() == est.consultar_DNI();
    if (not b)
    {
        int i = nest;
        while (i > j)
        {
            vest[i] = vest[i - 1];
            --i;
        }
        vest[i] = est;
        ++nest;
        if (est.te_nota())
            incrementar_interval(est.consultar_nota());
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool &b)
{
    int i = cerca_dicot(vest, 0, nest - 1, dni);
    b = i < nest and vest[i].consultar_DNI() == dni;
    if (b)
    {
        if (vest[i].te_nota())
            decrementar_interval(vest[i].consultar_nota());
        while (i < nest - 1)
        {
            vest[i] = vest[i + 1];
            ++i;
        }
        --nest;
    }
}
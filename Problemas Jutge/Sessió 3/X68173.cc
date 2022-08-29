// X68173   CONJUNT D'ESTUDIANTS AMB IMAX

#include "Cjt_estudiants.hh"
#include <algorithm>

Cjt_estudiants::Cjt_estudiants()
{
    nest = 0;
    vest = vector<Estudiant>(MAX_NEST);
}

Cjt_estudiants::~Cjt_estudiants() {}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est)
{
    if (nest >= MAX_NEST)
        throw PRO2Excepcio("Conjunt ple");
    int i = nest - 1;
    bool b = false;
    int dni = est.consultar_DNI();
    while (i >= 0 and not b)
    {
        if (dni > vest[i].consultar_DNI())
            b = true;
        else
        {
            vest[i + 1] = vest[i];
            --i;
        }
    }
    // i es la posicio mes avancada amb el DNI mes petit que dni, si n'hi ha;
    // si no, i=-1
    vest[i + 1] = est;
    ++nest;
    bool algun_est_te_nota = imax != -1;
    if (algun_est_te_nota)
    {
        if (est.te_nota() and est.consultar_nota() > vest[imax].consultar_nota())
            imax = i + 1;
        else if (est.te_nota() and est.consultar_nota() == vest[imax].consultar_nota())
        {
            if (est.consultar_DNI() < vest[imax].consultar_DNI())
                imax = i + 1;
        }
    }
}

int Cjt_estudiants::cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x)
{
    /* Pre: vest esta ordenat */
    int i;
    bool found = false;
    while (left <= right and not found)
    {
        i = (left + right) / 2;
        if (x < vest[i].consultar_DNI())
            right = i - 1;
        else if (x > vest[i].consultar_DNI())
            left = i + 1;
        else
            found = true;
    }
    // i es la posicio, si l'element existeix
    if (found)
        return i;
    else
        return -1;
}

void Cjt_estudiants::recalcular_posicio_imax()
{
    Estudiant amb_max_nota = vest[0];
    for (int i = 1; i < nest; ++i)
    {
        if (vest[i].te_nota())
        {
            if (amb_max_nota.te_nota())
            {
                if (vest[i].consultar_nota() > amb_max_nota.consultar_nota())
                {
                    amb_max_nota = vest[i];
                    imax = i;
                }
            }
            else
                amb_max_nota = vest[i];
        }
    }
}

void Cjt_estudiants::modificar_estudiant(const Estudiant &est)
{
    /* Pre: existeix un estudiant al parametre implicit amb el dni d'est  */
    int x = est.consultar_DNI();
    int i = cerca_dicot(vest, 0, nest - 1, x);
    bool algun_est_te_nota = imax != -1;
    if (algun_est_te_nota)
    {
        if (est.te_nota() and est.consultar_nota() > vest[imax].consultar_nota())
            imax = i;
        else if (est.te_nota() and est.consultar_nota() == vest[imax].consultar_nota())
        {
            if (est.consultar_DNI() < vest[imax].consultar_DNI())
                imax = i;
        }
    }
    vest[i] = est;
}

void Cjt_estudiants::modificar_iessim(int i, const Estudiant &est)
{
    if (i < 1 or i > nest)
        throw PRO2Excepcio("Index no valid per a modificar_iessim");
    vest[i - 1] = est;
    bool algun_est_te_nota = imax != -1;
    bool est_es_imax = i - 1 == imax;
    if (algun_est_te_nota and not est_es_imax)
    {
        if (est.te_nota() and est.consultar_nota() > vest[imax].consultar_nota())
            imax = i - 1;
        else if (est.te_nota() and est.consultar_nota() == vest[imax].consultar_nota())
        {
            if (est.consultar_DNI() < vest[imax].consultar_DNI())
                imax = i - 1;
        }
    }
}

int Cjt_estudiants::mida() const
{
    return nest;
}

int Cjt_estudiants::mida_maxima()
{
    return MAX_NEST;
}

bool Cjt_estudiants::existeix_estudiant(int dni) const
{
    int i = cerca_dicot(vest, 0, nest - 1, dni);
    return (i != -1);
}

Estudiant Cjt_estudiants::consultar_estudiant(int dni) const
{
    int i = cerca_dicot(vest, 0, nest - 1, dni);
    return vest[i];
}

Estudiant Cjt_estudiants::consultar_iessim(int i) const
{
    if (i < 1 or i > nest)
        throw PRO2Excepcio("Index no valid per a consultar_iessim");
    return vest[i - 1];
}

bool comp(const Estudiant &e1, const Estudiant &e2)
{
    return (e1.consultar_DNI() < e2.consultar_DNI());
}

void Cjt_estudiants::ordenar_cjt_estudiants()
{
    sort(vest.begin(), vest.begin() + nest, comp);
}

void Cjt_estudiants::llegir()
{
    cin >> nest;
    bool ningu_te_nota = true;
    if (nest > MAX_NEST)
        throw PRO2Excepcio("El conjunt no pot ser mes gran que la mida maxima");
    for (int i = 0; i < nest; ++i)
    {
        vest[i].llegir();
        if (vest[i].te_nota())
        {
            ningu_te_nota = false;
        }
    }
    if (ningu_te_nota)
        imax = -1;
    else
        recalcular_posicio_imax();
    ordenar_cjt_estudiants();
}

void Cjt_estudiants::escriure() const
{
    for (int i = 0; i < nest; ++i)
        vest[i].escriure();
}

void Cjt_estudiants::esborrar_estudiant(int dni)
/* Pre: existeix un estudiant al parametre implıcit amb DNI = dni */
/* Post: el parametre implıcit conte els mateixos estudiants que
l’original menys l’estudiant amb DNI = dni */
{
    int j = cerca_dicot(vest, 0, nest - 1, dni);
    Estudiant est = consultar_iessim(j + 1);
    while (j < nest - 1)
    {
        vest[j] = vest[j + 1];
        ++j;
    }
    --nest;
    bool algun_est_te_nota = imax != -1;
    if (algun_est_te_nota)
    {
        if (est.te_nota() and est.consultar_nota() > vest[imax].consultar_nota())
            imax = j;
        else if (est.te_nota() and est.consultar_nota() == vest[imax].consultar_nota())
        {
            if (est.consultar_DNI() < vest[imax].consultar_DNI())
                imax = j;
        }
    }
}

Estudiant Cjt_estudiants::estudiant_nota_max() const
/* Pre: el parametre implıcit conte almenys un estudiant amb nota */
/* Post: el resultat es l’estudiant del parametre implıcit amb
nota maxima; si en te mes d’un, es el de DNI mes petit */

{
    Estudiant millor = vest[0];
    for (int i = 1; i < nest; ++i)
    {
        if (vest[i].te_nota())
        {
            if (not millor.te_nota())
            {
                millor = vest[i];
            }
            else
            {
                if (vest[i].consultar_nota() > millor.consultar_nota())
                    millor = vest[i];
            }
        }
    }
    return millor;
}

// X87142	CONTROL - TORN 2 (TARDOR 2015). MILLORAT AMB JOCS DE PROVES D'EFICIÈNCIA

#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &b)
{
	int p = cerca_dicot(vest, 0, nest - 1, est.consultar_DNI());
	if (p <= nest and vest[p].consultar_DNI() == est.consultar_DNI())
	{
		b = true;
	}
	else
	{
		b = false;
		for (int i = nest - 1; i >= p; --i)
		{
			vest[i + 1] = vest[i];
		}
		++nest;
		vest[p] = est;
		if (p <= imax)
			++imax;
		if (vest[p].te_nota())
		{
			if (imax == -1)
				imax = p;
			else if (vest[p].consultar_nota() > vest[imax].consultar_nota())
				imax = p;
			else if (vest[p].consultar_nota() == vest[imax].consultar_nota())
			{
				if (vest[p].consultar_DNI() < vest[imax].consultar_DNI())
					imax = p;
			}
		}
	}
}

void Cjt_estudiants::eliminar_estudiants_sense_nota()
{
	int n = 0;
	for (int i = 0; i < nest; ++i)
	{
		if (vest[i].te_nota())
		{
			vest[n] = vest[i];
			++n;
		}
	}
	nest = n;
	recalcular_posicio_imax();
}
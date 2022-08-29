// X23571	CONTROL - TORN ÚNIC (TARDOR 2016)

#include "Cjt_estudiants.hh"

int Cjt_estudiants::posicio_nota(double nota_b) const
{
	bool trobat = false;
	int i = primer_est_amb_nota;
	while (i < nest and not trobat)
	{
		if (vest[i].consultar_nota() >= nota_b)
		{
			trobat = true;
		}
		else
			++i;
	}

	if (not trobat)
		i = nest;
	return i;

}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &trobat)
{
	int p = cerca_lineal_per_dni(vest, 0, nest - 1, est.consultar_DNI());
	if (p == nest)
	{
		trobat = false;
		if (est.te_nota())
		{
			p = cerca_dicot_per_nota_dni(vest, primer_est_amb_nota, nest - 1, est);
		}
		else
		{
			p = cerca_dicot_per_dni(vest, 0, primer_est_amb_nota - 1, est.consultar_DNI());
			++primer_est_amb_nota;
		}
		for (int i = nest - 1; i >= p; --i)
		{
			vest[i + 1] = vest[i];
		}
		++nest;
		vest[p] = est;
	}
	else
		trobat = true;
}

void Cjt_estudiants::escriure_i(double nota_i, double nota_s) const
{
	int i = posicio_nota(nota_i);
	while (i < nest and vest[i].consultar_nota() <= nota_s)
	{
		vest[i].escriure();
		++i;
	}
}
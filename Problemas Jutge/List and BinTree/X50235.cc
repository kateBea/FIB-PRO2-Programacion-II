// X50235	PODA DE SUBARBRES D'UN BINTREE D'ENTERS

#include "BinTree.hh"
#include "BinTreeIOint.hh"

bool poda_subarbre(BinTree<int> &a, int x) 
{
	bool elem_was_found;
	if (a.empty()) {
		elem_was_found = false;
	}
	else if (a.value() == x) {
		a = BinTree<int> ();
		elem_was_found = true;
	}
	else {
		int val = a.value();
		BinTree<int> l = a.left();
		BinTree<int> r = a.right();
		
		elem_was_found = poda_subarbre(l, x);

		if (not elem_was_found) {
			elem_was_found = poda_subarbre(r, x);
		}
		if (elem_was_found) {
			a = BinTree<int>(val, l, r);
		}
	}
	return elem_was_found;
}

/*
int main() {
	int pt;
	BinTree<int> arbre;

	cout << "Introdueix valor de marca: "; cin >> pt;
	read_bintree_int(arbre, pt);
	cout << "Introdueix valor a esborrar: "; cin >> pt;

	if (poda_subarbre(arbre, pt))
		write_bintree_int(arbre);
	else 
		cout << "Value not found..." << endl;

	return 0;
}
*/
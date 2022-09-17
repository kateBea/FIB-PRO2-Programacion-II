#include "BinTreeIOEst.hh" 

void read_bintree_est(BinTree<Estudiant>& a) 
{
    int identifier;
    double mark;
    cin >> identifier >> mark;
    Estudiant e(identifier);
    if (mark >= 0 and mark <= e.nota_maxima()) e.afegir_nota(mark);
    if (not (identifier == 0 and mark == 0)) {
        BinTree<Estudiant> esq;
        read_bintree_est(esq);
        BinTree<Estudiant> dr;
        read_bintree_est(dr);
        a = BinTree<Estudiant> (e, esq, dr);
    }
}

void write_bintree_est(const BinTree<Estudiant>& a)
{
    if (not a.empty()) {
        write_bintree_est(a.left());
        a.value().escriure();
        write_bintree_est(a.right());
    }
}
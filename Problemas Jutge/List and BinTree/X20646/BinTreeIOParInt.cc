#include "BinTreeIOParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a) 
{
    ParInt parell;
    parell.llegir();
    if ((parell.primer() != 0) and (parell.segon() != 0)) {
        BinTree<ParInt> esq;
        read_bintree_parint(esq);
        BinTree<ParInt> dr;
        read_bintree_parint(dr);
        a = BinTree<ParInt>(parell, esq, dr);
    }
}

void write_bintree_parint(const BinTree<ParInt>& a) {
    if (not a.empty()) {
        ParInt out = a.value();
        write_bintree_parint(a.left());
        out.escriure();
        write_bintree_parint(a.right());
    }
}
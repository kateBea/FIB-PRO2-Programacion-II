// X20646   CERCA EN UN BINTREE DE PARELLS D'ENTERS

#include "BinTreeIOParInt.hh"

int findPar(const BinTree<ParInt>& tree, int value, int& seg) {
    if (not tree.empty()) {
        if (tree.value().primer() == value) {
            seg = tree.value().segon();
            return 0;
        }

        int l = findPar(tree.left(), value, seg);
        
        if (l != -1) 
            return 1 + l;

        int r = findPar(tree.right(), value, seg);

        if (r != -1) 
            return 1 + r;
    }
    return -1;
}

int main() {
    BinTree<ParInt> a;
    read_bintree_parint(a);
    int enter;

    while (cin >> enter) {
        int s;
        int prof = findPar(a, enter, s);
        if (prof != -1) {
            cout << enter << ' ' << s;
            cout << ' ' << prof << endl;
        }
        else cout << -1 << endl;
    }

    return 0;
}
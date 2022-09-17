// X65608   CERCA EN UN BINTREE D'ESTUDIANTS

#include "BinTreeIOEst.hh"

int findEstudent(const BinTree<Estudiant>& v, int idn, double& pts) {
    if (not v.empty()) {
        if (v.value().consultar_DNI() == idn) {
            if (v.value().te_nota()) {
                pts = v.value().consultar_nota();
            }
            else 
                pts = -1;

            return 0;
        }

        double aux;
        int l = findEstudent(v.left(), idn, pts);
        int d = findEstudent(v.right(), idn, aux);

        if (l != -1 and d != -1) {
            if (l <= d) {
                return 1 + l;
            }
            else {
                pts = aux;
                return 1 + d;
            }
        }

        if (l != -1) {
            return 1 + l;
        }
        else if (d != -1) {
            pts = aux;
            return 1 + d;
        }
        else {
            return -1;
        }
    }
    return -1;
}

int main() {
    BinTree<Estudiant> arbre_est;
    read_bintree_est(arbre_est);
    int estIdentifier;

    while (cin >> estIdentifier) {
        double estMark;
        int alcaria = findEstudent(arbre_est, estIdentifier, estMark);

        if (alcaria != -1) {
            if (estMark != -1) {
                cout << estIdentifier << ' ' << alcaria << ' ' << estMark << endl;
            }
            else 
                cout << estIdentifier << ' ' << alcaria << ' ' << -1 << endl;
        }
        else 
            cout << estIdentifier << ' ' << alcaria << endl;
    }

    return 0;
}
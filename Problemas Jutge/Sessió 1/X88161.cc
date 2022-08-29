// X88161   CLASSIFICACIÓ DE LA LLIGA

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int x;
    int y;
} Resultat;

struct InfoEquipo {
    int equip = 0;
    int pts = 0;
    int marcats = 0;
    int rebuts = 0;
};

typedef vector<Resultat> Partit;
typedef vector<Partit> Lliga;

Lliga read_matrix() {
    int n;
    cin >> n;
    Lliga partits(n, Partit(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> partits[i][j].x;
            cin >> partits[i][j].y;
        }
    }
    return partits;
}

bool compare(InfoEquipo& a, InfoEquipo& b) {
    if (a.pts != b.pts) return a.pts > b.pts;
    else {
        int dif_a = a.marcats-a.rebuts;
        int dif_b = b.marcats-b.rebuts;
        if (dif_a != dif_b) return dif_a > dif_b;
    }
    return a.equip < b.equip;
}

void resultats_de_lliga(const Lliga& partits, vector<InfoEquipo>& v) {
    int n = partits.size();
    for (int i = 0; i < n; ++i) {
        v[i].equip = i + 1;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                v[i].marcats += partits[i][j].x;
                v[i].rebuts += partits[i][j].y;
                v[j].marcats += partits[i][j].y;
                v[j].rebuts += partits[i][j].x;

                if (partits[i][j].x > partits[i][j].y) {
                    v[i].pts += 3;
                }
                else if (partits[i][j].x < partits[i][j].y) {
                    v[j].pts += 3;
                }
                else {
                    v[i].pts += 1;
                    v[j].pts += 1;
                } 
            }
        }
    }
}

int main() {
    Lliga mat = read_matrix();
    vector<InfoEquipo> liga(mat.size());
    resultats_de_lliga(mat, liga);
    sort(liga.begin(), liga.end(), compare);
    for (int i = 0; i < liga.size(); ++i) {
        cout << liga[i].equip << ' ' << liga[i].pts << ' ';
        cout << liga[i].marcats << ' ' << liga[i].rebuts << endl;
        
    }

    return 0;
}

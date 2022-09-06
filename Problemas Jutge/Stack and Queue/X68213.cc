// X68213   BIBLIOTECA

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef struct {
    string name;
    int categoria;
} Libro;

typedef stack<Libro> pilaLlibres;
typedef vector<pilaLlibres> Biblioteca;

void escriu_pila_llibres(pilaLlibres a, int categoria) {
    cout << "Pila de la categoria " << categoria << endl;
    while (not a.empty()) {
        cout << a.top().name << endl;
        a.pop();
    }
    cout << endl;
}

void treu_llibres(pilaLlibres& b, int quantitat) {
    int it = 0;
    while (not b.empty() and it != quantitat) {
        b.pop();
        ++it;
    }
}

void afegir_llibre(pilaLlibres& a, Libro b) {
    a.push(b);
}

int main() {
    int op;
    int numCateg;

    cin >> numCateg;

    Libro sample;
    Biblioteca biblio(numCateg);

    cin >> op;
    
    while (op != -4) {
        switch (op) {
            case -1:
            cin >> sample.name >> sample.categoria;
            afegir_llibre(biblio[sample.categoria-1], sample);
            break;

            case -2:
            int quants;
            int quina_categ;
            cin >> quants >> quina_categ;
            treu_llibres(biblio[quina_categ-1], quants);
            break;

            case -3:
            int b;
            cin >> b;
            escriu_pila_llibres(biblio[b-1], b);
            break;
            default:
            op = -4;
        }
        cin >> op;
    }
    
    return 0;
}
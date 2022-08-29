// X54177   SUMA DE SECUENCIAS DE ENTEROS

#include <iostream>
using namespace std;

int main() {
    int n;
    int x;

    cin >> n >> x;

    for (int i = 0; i < n; ++i) {
        int suma = 0;
        int container;
        string trash;

        cin >> container;

        while (container != x) {
            suma+= container;
            cin >> container;
        }
        getline(cin, trash);
        cout << "La suma de la secuencia " 
            << i + 1 << " es " << suma << endl;
    }

    return 0;
}

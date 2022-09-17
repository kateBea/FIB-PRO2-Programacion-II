#include <iostream>
#include <list>
using namespace std; 

void recalcular_pics(const list<int>& l, int& min, int& max) {
    if (not l.empty()) {
        list<int>::const_iterator it = l.begin();
        max = min = *it;
        ++it;
        while (it != l.end()) {
            if (*it > max) max = *it;
            if (*it < min) min = *it;
            ++it;
        }
    }
}

void esborra_nombre(list<int>& l, int sample, double& sum) {
    if (not l.empty()) {
        list<int>::iterator it = l.begin();
        while (it != l.end()) {
            if (*it == sample) {
                it = l.erase(it);
                sum -= sample;
                return;
            }
            else ++it;
        }
    }
}

int main() {
    int codi, nombre;
    int maxValue, minValue;
    double total = 0;
    list<int> valids;

    cin >> codi >> nombre;

    while (codi != 0 and nombre != 0) {
        if (codi == -1) {
            if (valids.empty()) {
                maxValue = minValue = nombre;
            }
            else {
                if (nombre > maxValue) maxValue = nombre;
                if (nombre < minValue) minValue = nombre;
            }
            valids.push_back(nombre);
            total += nombre;
        }
        else if (codi == -2) {
            esborra_nombre(valids, nombre, total);
            if ((nombre == maxValue) or (nombre == minValue)) {
                recalcular_pics(valids, minValue, maxValue);
            }
        }
        
        if (not valids.empty()) {
            cout << minValue << ' ' << maxValue << ' ' << total / valids.size() << endl;
        }
        else cout << 0 << endl;
        cin >> codi >> nombre;
    }
    
    return 0;
}
// X13425   DISTRIBUCIÓ JUSTA DE CUES

#include "CuaIOParInt.hh"

int main() {
    queue<ParInt> principal, c1, c2;
    int t1, t2;
    t1 = t2 = 0;
    llegirCuaParInt(principal);
    while (not principal.empty()) {
        if (t1 <= t2) {
            c1.push(principal.front());
            t1 += principal.front().segon();
        }
        else {
            c2.push(principal.front());
            t2 += principal.front().segon();
        }
        principal.pop();
    }
    escriureCuaParInt(c1);
    cout << endl;
    escriureCuaParInt(c2);

    return 0;
}

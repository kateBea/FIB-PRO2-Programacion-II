// X49116   MÀXIM I MÍNIM D'UN VECTOR (NO MAIN)

#include <vector>
#include "vectorIOint.hh"

 using namespace std;
 
 struct parint {
    int prim;
    int seg;
};

parint max_min1(const vector<int> &v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
{
    parint resultVar;
    resultVar.prim = resultVar.seg = v[0];
    int n = v.size();
    for (int i = 0; i < n; ++i)
    {
        if (v[i] >= resultVar.prim)
            resultVar.prim = v[i];
        if (v[i] < resultVar.seg)
            resultVar.seg = v[i];
    }

    return resultVar;
}

pair<int, int> max_min2(const vector<int> &v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
{
    pair<int, int> resultVar;
    resultVar.first = resultVar.second = v[0];
    int n = v.size();
    for (int i = 0; i < n; ++i)
    {
        if (v[i] >= resultVar.first)
            resultVar.first = v[i];
        if (v[i] < resultVar.second)
            resultVar.second = v[i];
    }

    return resultVar;
}

void max_min3(const vector<int> &v, int &x, int &y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
    x = y = v[0];
    int n = v.size();
    for (int i = 0; i < n; ++i)
    {
        if (v[i] >= x)
            x = v[i];
        if (v[i] < y)
            y = v[i];
    }
}

/*
int main() {
    vector<int> v;
    leer_vector_int(v);
    cout << "Tu vector es: ";
    escribir_vector_int(v);
    cout << endl;

    parint printRes = max_min1(v);
    cout << "Resultados funcion I" << endl;
    cout << printRes.prim << ' ' << printRes.seg << endl;

    pair<int, int> res = max_min2(v);
    cout << "Resultados funcion II" << endl;
    cout << res.first << ' ' << res.second << endl;

    int u, w;
    max_min3(v,u,w);
    cout << "Resultados funcion III" << endl;
    cout << u << ' ' << w << endl;

    return 0;
}
*/

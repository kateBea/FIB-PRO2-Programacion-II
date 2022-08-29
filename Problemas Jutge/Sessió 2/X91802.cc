#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

 pair<int,int>  max_min_vest(const vector<Estudiant>& v)
 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */
{
    int x, y;
    bool primer = true;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].te_nota()) {
            if (primer) { 
                primer = false;
                x = y = i;
            }
            else {
                if(v[i].consultar_nota() > v[x].consultar_nota()) x = i;
                else if(v[i].consultar_nota() == v[x].consultar_nota()) {
                    if (v[i].consultar_DNI() < v[x].consultar_DNI()) 
                        x = i;
                }
                else if(v[i].consultar_nota() < v[y].consultar_nota())  
                    y = i;  
                else if(v[i].consultar_nota() == v[y].consultar_nota()) {
                    if (v[i].consultar_DNI() < v[y].consultar_DNI()) 
                        y = i;
                }
            }
        }
    }
    if (primer) return make_pair(-1,-1);
    else return make_pair(x,y);
}

/*
int main() {
    int n;
    cin >> n;
    vector<Estudiant> v(n);
    for (int i = 0; i < n; ++i) v[i].llegir();
    pair<int,int> p = max_min_vest(v);
    cout << "Estudiant nota maxima: " << p.first << endl;
    cout << "Estudiant nota minima: " << p.second << endl;

    return 0;
}
*/

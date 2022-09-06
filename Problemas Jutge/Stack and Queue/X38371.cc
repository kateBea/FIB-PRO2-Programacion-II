// X38371   ESTADÍSTIQUES D'UNA SEQÜÈNCIA D'ENTERS AMB ESBORRAT DEL MÉS ANTIC

#include <iostream>
#include <queue>
using namespace std;

typedef struct{
    int max;
    int min;
    double media;
}Info;

void print_info(const Info& v) 
{
    cout << "min " << v.min << ';' << ' ';
    cout << "max " << v.max << ';' << ' ';
    cout << "media " << v.media << endl;
    
}

//acción que recalcula el mínimo, máximo y la media de una lista de 
//numeros guardados en una cola y guarda los resultados en Info (ver typedef para
//tipo de estructura)
//NOTA: se asume que v tiene al menos un elemento
void recalcular(queue<int> v, Info& b) 
{
    int i = v.size();
    b.min = b.max = b.media = v.front();
    v.pop();
    while (not v.empty()) {
        if (v.front() > b.max) b.max = v.front();
        else if (v.front() < b.min) b.min = v.front();
        b.media += v.front();
        v.pop();
        
    }
    b.media = b.media / i;
}
int main() {
    int num;
    Info a;
    queue<int> cua;
    
    int numero_de_elementos = 0;
    double suma_total = 0;
    
    cin >> num; 
    while (num >= -1001 and num <= 1000) {
        //caso eliminar un elemento de la secuencia

        if (num == -1001) {
            if (not cua.empty()) {
                //hago una copia del elemnto
                //a ser eliminado de la cola
                int save = cua.front();

                cua.pop();


                numero_de_elementos-=1;


                if (not cua.empty()) {
                    suma_total = suma_total - save;
                    if(save == a.min or save == a.max) recalcular(cua, a);
                    else {
                        
                        a.media = suma_total / numero_de_elementos;
                    }
                    print_info(a);
                }
                else {
                    suma_total = 0;
                    cout << 0 << endl;
                }
            }
            else cout << 0 << endl;
        }

        //caso insertar un elemtno a la secuencia
        else {
            numero_de_elementos += 1;
            suma_total += num;
            if (cua.empty()) {
                a.min = a.max = a.media = num; 
            }
            else {
                if (num > a.max) a.max = num;
                else if (num < a.min) a.min = num;
                a.media = suma_total / numero_de_elementos;
            }
            cua.push(num);
            
            print_info(a);
        }
        cin >> num;
    }

    return 0;
}

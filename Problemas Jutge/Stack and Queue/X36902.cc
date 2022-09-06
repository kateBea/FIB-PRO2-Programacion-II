// X36902   AVALUACIÓ D'UNA EXPRESSIÓ AMB PARANTESIS

#include <iostream>
#include <stack>
using namespace std;

char computeBracket(char c) {
    if (c == '(') 
        return ')';
    else 
        return ']';
}

bool es_obert(char c) {
    return (c == '(') or (c == '[');
}

void printStack(stack<char> v) {
    int n = v.size();
    cout << "[Top]" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "| " << v.top() << " |" << endl;
        v.pop();
    }
    cout << "[Bottom]" << endl;
}

int main() {
    char entrada;
    stack<char> tancat;

    cin >> entrada;

    bool correcte = es_obert(entrada);
    while (entrada != '.' and correcte) {
        if (es_obert(entrada)) {
            tancat.push(computeBracket(entrada));
        }
        else if (not es_obert(entrada) and tancat.size() == 0) 
            correcte = false;
        else {
            if (entrada != tancat.top()) 
                correcte = false;
            else 
                tancat.pop();
        }
        cin >> entrada;
    }
    if (correcte and tancat.size() == 0) 
        cout << "Correcte" << endl;
    else 
        cout << "Incorrecte" << endl;

    return 0;
}
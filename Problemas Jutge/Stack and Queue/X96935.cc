// X96935   PALÍNDROMS AMB PILES

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool parell(int num) {
    return (num % 2 == 0);
}

int main() {
    int n;
    int number;
    bool found;
    stack<int> st;

    cin >> n;

    for (int i = 1; i <= n / 2; ++i) {
        cin >> number;
        st.push(number);
    }

    found = false;

    if (n > 1) {
        int sample;

        if (not parell(n)) 
            cin >> sample;

        int i = 1;
        while (i <= n / 2 and not found) {
            cin >> sample;

            if (sample != st.top()) 
                found = true;
            else 
                st.pop();

            ++i;
        }
    }

    if (not found) 
        cout << "SI" << endl;
    else 
        cout << "NO" << endl;

    return 0;
}

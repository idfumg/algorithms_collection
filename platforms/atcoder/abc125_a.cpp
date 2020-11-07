//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

void TotalBiscuitsProduced(int A, int B, int T) {
    int iterations = T / A;
    cout << B * iterations << '\n';
}

int main() {
    int A;
    int B;
    int T;
    cin >> A;
    cin >> B;
    cin >> T;

    TotalBiscuitsProduced(A, B, T);
}

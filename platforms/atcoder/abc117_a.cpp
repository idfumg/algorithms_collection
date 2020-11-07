//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

void PrintHowMuchTimesPasses(int T, int X) {
    const double ans = static_cast<double>(T) / X;
    cout << ans << '\n';
}

int main() {
    int T;
    int X;

    cin >> T;
    cin >> X;

    PrintHowMuchTimesPasses(T, X);
}

//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

void PrintAreaOfTheRightTriangle(int a, int b, int c) {
    cout << (a * b) / 2 << '\n';
}

int main() {
    int a;
    int b;
    int c;

    cin >> a;
    cin >> b;
    cin >> c;

    PrintAreaOfTheRightTriangle(a, b, c);
}

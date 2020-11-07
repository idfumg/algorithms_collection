//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

int HowManyTimes(const int a, const int b, const int c) {
    return min(c, b / a);
}

void PrintHowManyTimes(const int a, const int b, const int c) {
    cout << HowManyTimes(a, b, c) << '\n';
}

int main() {
    int a;
    int b;
    int c;

    cin >> a;
    cin >> b;
    cin >> c;

    PrintHowManyTimes(a, b, c);
}

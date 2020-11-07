//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

void HowManyCons(int a, int b) {
    int ans =  max({a + a - 1, b + b - 1, a + b});
    cout << ans << '\n';
}

int main() {
    int a;
    int b;
    cin >> a;
    cin >> b;
    HowManyCons(a, b);
}

//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

bool TheyCanEat(int a, int b) {
    return a <= 8 and b <= 8;
}

int main() {
    int a;
    int b;
    cin >> a;
    cin >> b;
    if (TheyCanEat(a, b)) {
        cout << "Yay!" << '\n';
    }
    else {
        cout << ":("<< '\n';
    }
}

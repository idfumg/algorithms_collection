//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;



int main() {
    int a;
    int b;
    cin >> a;
    cin >> b;

    int total = 2 * a + 100;
    int allowed = total - b;
    cout << allowed << '\n';
}

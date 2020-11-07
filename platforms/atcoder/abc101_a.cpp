//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;



int main() {
    string s;
    cin >> s;

    int ans = 0;
    for (const char ch : s) {
        if (ch == '+') ++ans;
        else --ans;
    }
    cout << ans << '\n';
}

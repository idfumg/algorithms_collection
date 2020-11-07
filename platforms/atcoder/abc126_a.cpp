//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

void ChangeCharacter(string& s, int k) {
    s[k - 1] = tolower(s[k - 1]);
    cout << s << '\n';
}

int main() {
    int n;
    int k;
    string s;
    cin >> n;
    cin >> k;
    cin >> s;

    ChangeCharacter(s, k);
}

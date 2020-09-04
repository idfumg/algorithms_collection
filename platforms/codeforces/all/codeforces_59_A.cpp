#define IS_TEST 0

#if IS_TEST == 1
#include "../headers.hpp"
#else
#include <bits/stdc++.h>
#endif

// https://codeforces.com/contest/59/problem/A

using namespace std;

void solve(istream& ss) {
    string s;
    ss >> s;
    int uppers = 0;
    int lowers = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (::isupper(s[i])) {
            ++uppers;
        }
        else {
            ++lowers;
        }
    }
    if (uppers > lowers) {
        for (int i = 0; i < s.size(); ++i) {
            if (::islower(s[i])) {
                s[i] = ::toupper(s[i]);
            }
        }
    }
    else {
        for (int i = 0; i < s.size(); ++i) {
            if (::isupper(s[i])) {
                s[i] = ::tolower(s[i]);
            }
        }
    }
    cout << s << endl;
}

void test() {
    {
        istringstream ss("HoUse");
        solve(ss);
    }
    {
        istringstream ss("ViP");
        solve(ss);
    }
    {
        istringstream ss("maTRIx");
        solve(ss);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if IS_TEST == 1
    test();
#else
    solve(cin);
#endif

    return 0;
}

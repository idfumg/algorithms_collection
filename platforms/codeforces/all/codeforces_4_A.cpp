#define IS_TEST 0

#if IS_TEST == 1
#include "../headers.hpp"
#else
#include <bits/stdc++.h>
#endif

// https://codeforces.com/contest/4/problem/A

using namespace std;

void solve(istream& ss) {
    int n;
    ss >> n;

    if (n < 4) cout << "NO";
    else cout << (n % 2 != 0 ? "NO" : "YES");
}

void test() {
    {
        istringstream ss("8");
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

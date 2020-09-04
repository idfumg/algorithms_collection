#define IS_TEST 0

#if IS_TEST == 1
#include "../headers.hpp"
#else
#include <bits/stdc++.h>
#endif

// https://codeforces.com/problemset/problem/894/A

using namespace std;

using ll = int64_t;

int go(int n) {
    if (n == 1) return 1;
    if (n == 2) return 5;
    if (n == 3) return 13;

    int b = 13;
    for (int i = 4; i <= n; ++i) {
        b = b + 4 * (i - 1);
    }
    return b;
}

int solve(istream& ss) {
    int n;
    ss >> n;

    int res = go(n);
    cout << res << endl;
    return res;
}

void test() {
    {
        istringstream ss("5");
        assert(solve(ss) == 41);
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

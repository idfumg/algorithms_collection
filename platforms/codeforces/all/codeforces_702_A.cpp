#define IS_TEST 0

#if IS_TEST == 1
#include "../headers.hpp"
#else
#include <bits/stdc++.h>
#endif

// https://codeforces.com/contest/996/problem/A

using namespace std;

using ll = int64_t;

void solve(istream& ss) {
    int n;
    ss >> n;

    int prevvalue = 0;
    int value = 0;
    int res = 0;
    int current = 0;

    for (int i = 0; i < n; ++i) {
        ss >> value;

        if (i == 0 or value > prevvalue) ++current;
        else current = 1;

        prevvalue = value;
        res = max({res, current});
    }

    cout << res << '\n';
}

void test() {
    {
        istringstream ss(R"(5
1 7 2 11 15)");
        solve(ss);
    }
    {
        istringstream ss(R"(6
100 100 100 100 100 100)");
        solve(ss);
    }
    {
        istringstream ss(R"(3
1 2 3)");
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

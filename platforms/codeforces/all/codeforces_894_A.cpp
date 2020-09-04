#define IS_TEST 1

#if IS_TEST == 1
#include "../headers.hpp"
#else
#include <bits/stdc++.h>
#endif

// https://codeforces.com/problemset/problem/894/A

using namespace std;

using ll = int64_t;

int go_(size_t start, size_t p, int res, const string& s, const string& pattern) {
    if (start > s.size()) {

    }
    else if (p == pattern.size()) {
        ++res;
    }
    else {
        for (int i = start; i < s.size(); ++i) {
            if (s[i] == pattern[p]) {
                res = go_(i + 1, p + 1, res, s, pattern);
            }
        }
    }
    return res;
}

int go(const string& s) {
    return go_(0, 0, 0, s, "QAQ");
}

int solve(istream& ss) {
    string s;
    ss >> s;

    int res = go(s);
    cout << res << endl;
    return res;
}

void test() {
    {
        istringstream ss("QAQAQYSYIOIWIN");
        int res = solve(ss);
        assert(res == 4);
    }
    {
        istringstream ss(R"(QAQQQZZYNOIWIN)");
        int res = solve(ss);
        assert(res == 3);
    }
    {
        istringstream ss(R"(QA)");
        int res = solve(ss);
        assert(res == 0);
    }
    {
        istringstream ss(R"(IAQVAQZLQBQVQFTQQQADAQJA)");
        int res = solve(ss);
        assert(res == 24);
    }
    {
        istringstream ss(R"(QQAAQASGAYAAAAKAKAQIQEAQAIAAIAQQQQQ)");
        int res = solve(ss);
        assert(res == 378);
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

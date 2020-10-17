#include "../../template.hpp"

bool IsBalanced(const string& a) {
    int n = a.size(), i = 0;
    vector<char> s;
    for (int i = 0; i < n; ++i) {
        s.push_back(a[i]);
        while (not s.empty() and s.back() == ')') {
            s.pop_back();
            if (s.empty() or s.back() != '(') return false;
            s.pop_back();
        }
    }
    return s.empty();
}

void naive(const string& s, int from, int& res, string& current) {
    int n = s.size();
    if (from == s.size()) {
        if (IsBalanced(current)) {
            res = max(res, static_cast<int>(current.size()));
        }
        return;
    }
    for (int i = from; i < n; ++i) {
        naive(s, i + 1, res, current);
        current.push_back(s[i]);
        naive(s, i + 1, res, current);
        current.pop_back();
    }
}

int naive(const string& s) {
    int res = 0;
    string current;
    naive(s, 0, res, current);
    return res;
}

int tab(const string& s) {
    int n = s.size();
    vvi dp(n, vi(n));
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '(' and s[i + 1] == ')') {
            dp[i][i + 1] = 2;
        }
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 0, j = i + k; j < n; ++i, ++j) {
            if (s[i] == '(' and s[j] == ')') {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            for (int p = i; p < j; ++p) {
                dp[i][j] = max(dp[i][j], dp[i][p] + dp[p + 1][j]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() { TimeMeasure _; __x();
    cout << IsBalanced("()()") << '\n'; // true
    cout << IsBalanced("()())") << '\n'; // false
    cout << IsBalanced("()(((((()") << '\n'; // false
    cout << IsBalanced("((()))") << '\n'; // true
    cout << IsBalanced("()") << '\n'; // true
    cout << '\n';
    cout << naive("()())") << '\n'; // 4
    cout << naive("()(((((()") << '\n'; // 4
    cout << naive("((()))") << '\n'; // 6
    cout << naive("())") << '\n'; // 2
    cout << '\n';
    cout << tab("()())") << '\n'; // 4
    cout << tab("()(((((()") << '\n'; // 4
    cout << tab("((()))") << '\n'; // 6
    cout << tab("())") << '\n'; // 2
}

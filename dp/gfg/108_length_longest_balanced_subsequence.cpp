#include "../../template.hpp"

bool IsBalanced(string s, int i, int j) {
    if (i >= j) return true;
    int left = 0, right = 0;
    for (; i <= j; ++i) {
        const char ch = s[i - 1];
        if (ch == '(' and right != 0) return false;
        else if (ch == '(') ++left;
        else if (ch == ')' and left == 0) return false;
        else if (ch == ')') --left;
    }
    return left == 0;
}

bool IsBalanced(string s) {
    return IsBalanced(s, 1, s.size());
}

int naive(string s) {
    int n = s.size();
    int ans = 0;
    for (int i = 1; i < (1 << n); ++i) {
        string subseq;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subseq.push_back(s[j]);
            }
        }
        if (IsBalanced(subseq) and subseq.size() > ans) {
            ans = subseq.size();
        }
    }
    return ans;
}

int rec(string s, int i, int j) {
    if (i >= j) return 0;
    if (s[i - 1] == '(' and s[j - 1] == ')' and IsBalanced(s, i, j)) return j - i + 1;
    int maxcount = 0;
    for (int p = i + 1; p < j; ++p) {
        maxcount = max(maxcount, rec(s, i, p) + rec(s, p + 1, j));
    }
    return max({maxcount, rec(s, i + 1, j), rec(s, i, j - 1), rec(s, i + 1, j - 1)});
}

int rec(string s) {
    return rec(s, 1, s.size());
}

int rec2(string s, int i, int j) {
    if (i >= j) return 0;
    if (s[i - 1] == '(' and s[j - 1] == ')') {
        return max(
                2 + rec2(s, i + 1, j - 1),
                rec2(s, i + 1, j) + rec2(s, i, j - 1) - rec2(s, i + 1, j - 1));
    }
    return max(rec(s, i + 1, j), rec(s, i, j - 1));
}

int rec2(string s) {
    return rec2(s, 1, s.size());
}

int tab(string s) {
    int n = s.size();
    vvi dp(n + 2, vi(n + 2));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == '(' and s[j - 1] == ')' and IsBalanced(s, i, j)) {
                dp[i][j] = j - i + 1;
            }
            else {
                for (int p = i + 1; p < j; ++p) {
                    dp[i][j] = max(dp[i][j], dp[i][p] + dp[p + 1][j]);
                }
            }
            dp[i][j] = max({dp[i][j], dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]});
        }
    }
    return dp[1][n];
}

int tab2(string s) {
    int n = s.size();
    vvi dp(n + 2, vi(n + 2));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i >= j) {
                dp[i][j] = 0;
            }
            else if (s[i - 1] == '(' and s[j - 1] == ')') {
                dp[i][j] = max(2 + dp[i + 1][j - 1], dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]);
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[1][n];
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
    cout << rec("()())") << '\n'; // 4
    cout << rec("()(((((()") << '\n'; // 4
    cout << rec("((()))") << '\n'; // 6
    cout << rec("())") << '\n'; // 2
    cout << '\n';
    cout << rec2("()())") << '\n'; // 4
    cout << rec2("()(((((()") << '\n'; // 4
    cout << rec2("((()))") << '\n'; // 6
    cout << rec2("())") << '\n'; // 2
    cout << '\n';
    cout << tab("()())") << '\n'; // 4
    cout << tab("()(((((()") << '\n'; // 4
    cout << tab("((()))") << '\n'; // 6
    cout << tab("())") << '\n'; // 2
    cout << '\n';
    cout << tab2("()())") << '\n'; // 4
    cout << tab2("()(((((()") << '\n'; // 4
    cout << tab2("((()))") << '\n'; // 6
    cout << tab2("())") << '\n'; // 2
}

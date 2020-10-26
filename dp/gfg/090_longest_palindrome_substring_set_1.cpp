#include "../../template.hpp"

bool IsPalindrome(string s, int i, int j) {
    while (i <= j) {
        if (s[i - 1] != s[j - 1]) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}

int rec(string& s, int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    if (s[i - 1] == s[j - 1] and IsPalindrome(s, i, j)) {
        return j - i + 1;
    }
    return max(rec(s, i + 1, j), rec(s, i, j - 1));
}

int rec(string s) {
    int n = s.size();
    return rec(s, 1, n);
}

int tab(string s) {
    int n = s.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (i == j) {
                dp[i][j] = 1;
            }
            else if (s[i - 1] == s[j - 1] and IsPalindrome(s, i, j)) {
                dp[i][j] = j - i + 1;
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[1][n];
}

int tab2(string s) {
    int n = s.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        if (s[i - 1] == s[i - 2]) {
            dp[i - 1][i] = 2;
        }
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            if (s[i - 1] == s[j - 1] and dp[i + 1][j - 1] == j - i - 1) {
                dp[i][j] = j - i + 1;
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[1][n];
}

int rec_elems(string& s, vvi& dp, int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    if (s[i - 1] == s[j - 1] and dp[i][j] == j - i + 1) {
        cout << s.substr(i - 1, j - i + 1) << '\n';
        return j - i + 1;
    }
    if (dp[i + 1][j] > dp[i][j - 1]) {
        return rec_elems(s, dp, i + 1, j);
    }
    return rec_elems(s, dp, i, j - 1);
}

int rec_elems(string s) {
    int n = s.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        if (s[i - 1] == s[i - 2]) {
            dp[i - 1][i] = 2;
        }
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            if (s[i - 1] == s[j - 1] and dp[i + 1][j - 1] == j - i - 1) {
                dp[i][j] = j - i + 1;
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return rec_elems(s, dp, 1, n);
}

int main() { TimeMeasure _; __x();
    static const string s1 = "forgeeksskeegfor"; // geeksskeeg // 10
    static const string s2 = "Geeks"; // ee // 2
    cout << rec(s1) << endl;
    cout << rec(s2) << endl;
    cout << '\n';
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
    cout << '\n';
    cout << tab2(s1) << endl;
    cout << tab2(s2) << endl;
    cout << '\n';
    cout << rec_elems(s1) << endl;
    cout << rec_elems(s2) << endl;
}

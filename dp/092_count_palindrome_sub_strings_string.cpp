#include "../template.hpp"

bool IsPalindrome(const string& s, int i, int j) {
    while (i <= j) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}

int rec(const string& s, int i, int j) {
    if (i > j) return 0;
    if (j - i == 1) return s[i] == s[j];
    if (s[i] == s[j] && IsPalindrome(s, i, j) && j - i >= 2) {
        return 1 + rec(s, i + 1, j) + rec(s, i, j - 1) - rec(s, i + 1, j - 1);
    }
    return rec(s, i + 1, j) + rec(s, i, j - 1) - rec(s, i + 1, j - 1);
}

int rec(const string& s) {
    return rec(s, 0, s.size() - 1);
}

int tab(const string& s) {
    const int n = s.size();
    vvi dp(n, vi(n));
    int count = 0;

    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 2;
            ++count;
        }
    }

    for (int k = 2; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            int j = i + k;
            if (j < n && s[i] == s[j] && dp[i + 1][j - 1] != 0) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
                ++count;
            }
        }
    }

    return count;
}

int main() { TimeMeasure _; __x();
    static const string s1 = "abaab"; // 3
    static const string s2 = "abbaeae"; // 4

    cout << rec(s1) << endl;
    cout << rec(s2) << endl;
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
}

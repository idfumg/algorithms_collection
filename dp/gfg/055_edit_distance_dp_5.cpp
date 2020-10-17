#include "../../template.hpp"

int rec(string& s1, string& s2, int i, int j) {
    if (i < 0 or j < 0) return max(i, j) + 1;
    if (s1[i] == s2[j]) return rec(s1, s2, i - 1, j - 1);
    const auto a = rec(s1, s2, i - 1, j - 1);
    const auto b = rec(s1, s2, i - 1, j);
    const auto c = rec(s1, s2, i, j - 1);
    return min({a, b, c}) + 1;
}

int rec(string& s1, string& s2) {
    return rec(s1, s2, s1.size() - 1, s2.size() - 1);
}

int tab(string& s1, string& s2) {
    const auto m = s1.size();
    const auto n = s2.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                const auto a = dp[i - 1][j - 1];
                const auto b = dp[i - 1][j];
                const auto c = dp[i][j - 1];
                dp[i][j] = min({a, b, c}) + 1;
            }
        }
    }
    return dp[m][n];
}

int opt(string& s1, string& s2) {
    const auto m = s1.size();
    const auto n = s2.size();
    vvi dp(2, vi(n + 1));
    int idx = 0;
    for (int i = 0; i <= m; ++i) {
        idx = i & 1;
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[idx][j] = j;
            }
            else if (j == 0) {
                dp[idx][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[idx][j] = dp[1 - idx][j - 1];
            }
            else {
                const auto a = dp[1 - idx][j - 1];
                const auto b = dp[1 - idx][j];
                const auto c = dp[idx][j - 1];
                dp[idx][j] = min({a, b, c}) + 1;
            }
        }
    }
    return dp[idx][n];
}

int main() { TimeMeasure _; __x();
    string str1[2] = {"geek", "gesek"};
    string str2[2] = {"cat", "cut"};
    string str3[2] = {"sunday", "saturday"};
    string str4[2] = {"food", "money"};
    cout << "Recursive: " << rec(str1[0], str1[1]) << endl;
    cout << "Recursive: " << rec(str2[0], str2[1]) << endl;
    cout << "Recursive: " << rec(str3[0], str3[1]) << endl;
    cout << "Recursive: " << rec(str4[0], str4[1]) << endl;
    cout << endl;
    cout << "Tabulation: " << tab(str1[0], str1[1]) << endl;
    cout << "Tabulation: " << tab(str2[0], str2[1]) << endl;
    cout << "Tabulation: " << tab(str3[0], str3[1]) << endl;
    cout << "Tabulation: " << tab(str4[0], str4[1]) << endl;
    cout << endl;
    cout << "Optimization: " << opt(str1[0], str1[1]) << endl;
    cout << "Optimization: " << opt(str2[0], str2[1]) << endl;
    cout << "Optimization: " << opt(str3[0], str3[1]) << endl;
    cout << "Optimization: " << opt(str4[0], str4[1]) << endl;
}

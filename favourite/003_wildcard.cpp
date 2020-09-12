#include "../template.hpp"

static bool IsMatch(const std::string& S, const std::string& P) noexcept {
    const int m = size(S), n = size(P);
    vvb dp(m + 1, vb(n + 1));
    dp[0][0] = true;
    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 0 and P[j - 1] == '*') dp[i][j] = dp[i][j - 1];
            else if (i == 0 and P[j - 1] != '*') dp[i][j] = false;
            else if (P[j - 1] == '*') dp[i][j] = dp[i][j - 1] or dp[i - 1][j];
            else if (P[j - 1] == '?') dp[i][j] = true;
            else if (S[i - 1] == P[j - 1]) dp[i][j] = true;
        }
    }
    return dp[m][n];
}

int main() { TimeMeasure _; __x();
    cout << IsMatch("XYXZZXY", "X***Y") << endl; // true
    cout << IsMatch("XYXZZXY", "X*ZZ??") << endl; // true
    cout << IsMatch("XYXZZXY", "*X*X?") << endl; // true
    cout << IsMatch("XYXZZXY", "X***X") << endl; // false
    cout << IsMatch("XYXZZXY", "*") << endl; // true
}

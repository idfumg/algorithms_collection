#include "../template.hpp"

int tab(const string& s) {
    int n = s.size();
    vi dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        if (i * 2 <= n) {
            if (s.substr(0, i) == s.substr(i, i)) {
                dp[i * 2] = min(dp[i * 2], dp[i] + 1);
            }
        }
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    string s1 = "aaaaaaaa";
    string s2 = "aaaaaa";
    string s3 = "abcabca";
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
    cout << tab(s3) << endl;
}

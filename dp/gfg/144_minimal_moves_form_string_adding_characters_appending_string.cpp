#include "../../template.hpp"

int rec(string s, int n) {
    if (n == 0) return 0;
    if (n & 1) return rec(s, n - 1) + 1;
    if (s.substr(n / 2, n / 2) == s.substr(0, n / 2)) return min(rec(s, n - 1), rec(s, n / 2)) + 1;
    return rec(s, n - 1) + 1;
}

int rec(string s) {
    return rec(s, s.size());
}

int tab(string s) {
    int n = s.size();
    vi dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i & 1) dp[i] = dp[i - 1] + 1;
        else if (s.substr(i / 2, i / 2) == s.substr(0, i / 2)) dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
        else dp[i] = dp[i - 1] + 1;
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    string s1 = "aaaaaaaa"; // 4
    string s2 = "aaaaaa"; // 4
    string s3 = "abcabca"; // 5
    string s4 = "abdabca"; // 7
    cout << rec(s1) << endl;
    cout << rec(s2) << endl;
    cout << rec(s3) << endl;
    cout << rec(s4) << endl;
    cout << '\n';
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
    cout << tab(s3) << endl;
    cout << tab(s4) << endl;
}

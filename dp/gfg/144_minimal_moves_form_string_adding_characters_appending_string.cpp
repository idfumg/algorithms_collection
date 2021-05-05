#include "../../template.hpp"

int rec(string s, int n) {
    if (n == 0) return 0;
    if (n % 2 == 0 and s.substr(0, n / 2) == s.substr(n / 2, n / 2)) return rec(s, n / 2) + 1;
    return rec(s, n - 1) + 1;
}

int rec(string s) {
    return rec(s, s.size());
}

int tab(string s) {
    int n = s.size();
    vi dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0 and s.substr(0, n / 2) == s.substr(n / 2, n / 2)) dp[i] = dp[i / 2] + 1;
        else dp[i] = dp[i - 1] + 1;
    }
    return dp[n];
}

int main() { // TimeMeasure _; __x();
    string s1 = "aaaaaaaa"; // 4
    string s2 = "aaaaaa"; // 4
    string s3 = "abcabca"; // 5
    cout << rec(s1) << endl;
    cout << rec(s2) << endl;
    cout << rec(s3) << endl;
    cout << '\n';
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
    cout << tab(s3) << endl;
}

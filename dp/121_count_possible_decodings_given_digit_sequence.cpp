#include "../template.hpp"

int rec(const string& s, const int n) {
    if (n == 0 || n == 1) return 1;
    if (s[0] == '0') return 0;
    int count = 0;
    if (s[n - 1] != '0') {
        count += rec(s, n - 1);
    }
    if (s[n - 2] == '1' || (s[n - 2] == '2' && s[n - 1] < '7')) {
        count += rec(s, n - 2);
    }
    return count;
}

int rec(const string& s) {
    return rec(s, s.size());
}

int tab(const string& s) {
    int n = s.size();
    vi dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    if (s[0] == '0') return 0;
    for (int i = 2; i <= n; ++i) {
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }
        if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    string s1 = "121";
    string s2 = "1234";
    string s3 = "101";
    string s4 = "01";
    string s5 = "1221";
    cout << rec(s1) << endl;
    cout << rec(s2) << endl;
    cout << rec(s3) << endl;
    cout << rec(s4) << endl;
    cout << rec(s5) << endl;
    cout << endl;
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
    cout << tab(s3) << endl;
    cout << tab(s4) << endl;
    cout << tab(s5) << endl;
}

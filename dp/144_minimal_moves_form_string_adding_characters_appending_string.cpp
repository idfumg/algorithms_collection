#include "../template.hpp"

int rec(const string& s, int i) {
    if (i == 0) return 0;
    if (i % 2 == 0) {
        const auto part1 = s.substr(0, i / 2);
        const auto part2 = s.substr(i / 2, i / 2);
        if (part1 == part2) {
            return min(rec(s, i - 1) + 1, rec(s, i / 2) + 1);
        }
    }
    return rec(s, i - 1) + 1;
}

int rec(const string& s) {
    return rec(s, s.size());
}

int tab(const string& s) {
    int n = s.size();
    vi dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        if (i * 2 <= n) {
            const auto part1 = s.substr(0, i);
            const auto part2 = s.substr(i, i);
            if (part1 == part2) {
                dp[i * 2] = min(dp[i * 2], dp[i] + 1);
            }
        }
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
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

#include "../template.hpp"

int rec(string& s, int from, int prevsum) {
    int n = s.size();
    if (from >= n + 1) {
        return 1;
    }
    int count = 0, sum = 0;
    for (int i = from; i <= n; ++i) {
        sum += s[i - 1] - '0';
        if (sum >= prevsum) {
            count += rec(s, i + 1, sum);
        }
    }
    return count;
}

int rec(string& s) {
    return rec(s, 1, 0);
}

int tab(string& s) {
    int n = s.size(), total = 0;

    for (int i = 0; i < n; ++i) {
        total += s[i] - '0';
    }

    vvi dp(n + 1, vi(total + 1));

    for (int j = 0; j <= total; ++j) {
        dp[0][j] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= total; ++j) {
            int count = 0, sum = 0;
            for (int k = i; k >= 1; --k) {
                sum += s[k - 1] - '0';
                if (sum > j) break;
                count += dp[k - 1][sum];
            }
            dp[i][j] = count;
        }
    }

    return dp[n][total];
}

int main() { TimeMeasure _; __x();
    string s1 = "1119";
    string s2 = "1234";
    cout << rec(s1) << endl; // 7
    cout << rec(s2) << endl; // 6
    cout << tab(s1) << endl; // 7
    cout << tab(s2) << endl; // 6
}

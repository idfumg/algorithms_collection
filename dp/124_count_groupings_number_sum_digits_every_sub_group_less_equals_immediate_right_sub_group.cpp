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

int tab2(const string& s) {
    int n = size(s), total = 0;
    for (int i = 0; i < n; ++i) total += s[i] - '0';
    vvi dp(n + 2, vi(total + 2));
    for (int i = 0; i <= total; ++i) dp[n+1][i] = 1;
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j <= total; ++j) {
            int count = 0, sum = 0;
            for (int k = i; k <= n; ++k) {
                sum += s[k - 1] - '0';
                if (sum >= j) {
                    count += dp[k + 1][sum];
                }
            }
            dp[i][j] = count;
        }
    }
    return dp[1][0];
}

int rec_straight(const string& s, int n, int left, int right) {
    if (left > right) return 0;
    if (n == 0) return 1;
    return
        rec_straight(s, n - 1, left + s[n - 1] - '0', right) +
        rec_straight(s, n - 1, s[n - 1] - '0', left);
}

int rec_straight(const string& s) {
    return rec_straight(s, s.size(), 0, INF);
}

int tab_straight(const string& s) {
    int n = s.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += s[i] - '0';
    }
    vvvi dp(n + 1, vvi(sum + 1, vi(sum + 1)));
    for (int i = 0; i <= sum; ++i) {
        for (int j = 0; j <= sum; ++j) {
            if (i <= j) {
                dp[0][i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int left = 0; left <= sum; ++left) {
            for (int right = 0; right <= sum; ++right) {
                if (left > right) continue;
                if (left + s[i - 1] - '0' <= right) {
                    dp[i][left][right] = dp[i - 1][left + s[i - 1] - '0'][right];
                }
                if (s[i - 1] - '0' <= left) {
                    dp[i][left][right] += dp[i - 1][s[i - 1] - '0'][left];
                }
            }
        }
    }
    return dp[n][0][sum];
}

int main() { TimeMeasure _; __x();
    string s1 = "1119";
    string s2 = "1234";
    cout << rec(s1) << endl; // 7
    cout << rec(s2) << endl; // 6
    cout << tab(s1) << endl; // 7
    cout << tab(s2) << endl; // 6
    cout << tab2(s1) << endl; // 7
    cout << tab2(s2) << endl; // 6
    cout << rec_straight(s1) << endl; // 7
    cout << rec_straight(s2) << endl; // 6
    cout << tab_straight(s1) << endl; // 7
    cout << tab_straight(s2) << endl; // 6
}

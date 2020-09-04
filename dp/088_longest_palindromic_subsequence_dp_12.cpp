#include "../../template.hpp"

int rec(const string& s, int i, int j, string& current, string& maxi) {
    if (i > j) {
        if (current.size() * 2 > maxi.size()) {
            string reversed = current;
            reverse(reversed);
            maxi = current + reversed;
        }
        return 0;
    }
    if (i == j) {
        string reversed = current;
        reverse(reversed);
        current.push_back(s[i]);
        if (current.size() + reversed.size() > maxi.size()) maxi = current + reversed;
        current.pop_back();
        return 1;
    }
    if (s[i] == s[j]) {
        current.push_back(s[i]);
        const auto res = rec(s, i + 1, j - 1, current, maxi) + 2;
        current.pop_back();
        return res;
    }
    return max(rec(s, i + 1, j, current, maxi), rec(s, i, j - 1, current, maxi));
}

int rec(const string& s) {
    string current, maxi;
    const auto res = rec(s, 0, s.size() - 1, current, maxi);
    cout << '"' << maxi << '"' << endl;
    return res;
}

int tab(const string& s) {
    int n = s.size();
    vvi dp(n + 2, vi(n + 2));
    vvvi prev(n + 2, vvi(n + 2));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (i == j) {
                dp[i][j] = 1;
                prev[i][j] = {0, j - 1, 1};
            }
            else if (s[i - 1] == s[j - 1]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
                prev[i][j] = {i + 1, j - 1, 2};
            }
            else {
                if (dp[i + 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i + 1][j];
                    prev[i][j] = {i + 1, j, 0};
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                    prev[i][j] = {i, j - 1, 0};
                }
            }
        }
    }
    string res(dp[1][n], ' ');
    int i = 0, j = res.size() - 1;
    for (vi at = prev[1][n]; not at.empty();at=prev[at[0]][at[1]]){
        if (at[2] == 2) {
            res[i] = res[j] = s[at[1]];
            ++i;
            --j;
        }
        if (at[2] == 1) {
            res[i] = s[at[1]];
        }
    }
    debug(res);
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    static const string s1 = "bbabcbcab"; // 7
    static const string s2 = "geeksforgeeks"; // 5
    cout << rec(s1) << endl;
    cout << rec(s2) << endl;
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
}

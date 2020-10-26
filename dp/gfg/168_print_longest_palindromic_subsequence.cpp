#include "../../template.hpp"

int rec(string s, int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    if (s[i - 1] == s[j - 1]) {
        return 2 + rec(s, i + 1, j - 1);
    }
    return max(rec(s, i + 1, j),  rec(s, i, j - 1));
}

int rec(string s) {
    int n = s.size();
    return rec(s, 0, n);
}

int tab(string s) {
    int n = s.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (i == j) {
                dp[i][j] = 1;
            }
            else if (s[i - 1] == s[j - 1]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[1][n];
}

int rec_elems(string s, vvi& dp, int i, int j, string& current) {
    if (i > j) {
        cout << current;
        for_each(current.rbegin(), current.rend(), [&](char ch){cout << ch;});
        cout << '\n';
        return 0;
    }
    if (i == j) {
        cout << current << s[i - 1];
        for_each(current.rbegin(), current.rend(), [&](char ch){cout << ch;});
        cout << '\n';
        return 1;
    }
    if (s[i - 1] == s[j - 1]) {
        current.push_back(s[i - 1]);
        return 2 + rec_elems(s, dp, i + 1, j - 1, current);
    }
    if (dp[i + 1][j] >= dp[i][j]) {
        return rec_elems(s, dp, i + 1, j, current);
    }
    return rec_elems(s, dp, i, j - 1, current);
}

int rec_elems(string s) {
    int n = s.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (i == j) {
                dp[i][j] = 1;
            }
            else if (s[i - 1] == s[j - 1]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    string current;
    return rec_elems(s, dp, 0, n, current);
}

int tab_elems(string s) {
    int n = s.size();
    vvi dp(n + 1, vi(n + 1));
    vvvi prev(n + 1, vvi(n + 1));
    char middle = -1; // there is the only one middle element obviously
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (i == j) {
                dp[i][j] = 1;
                middle = s[j - 1];
            }
            else if (s[i - 1] == s[j - 1]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
                prev[i][j] = {i + 1, j - 1, 1};
            }
            else {
                if (dp[i + 1][j] >= dp[i][j - 1]) {
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
    string current;
    for (vi at = prev[1][n]; not at.empty(); at = prev[at[0]][at[1]]) {
        if (at[2] == 1) {
            current.push_back(s[at[1]]);
        }
    }
    cout << current;
    if (middle != -1) {
        cout << middle;
    }
    for_each(current.rbegin(), current.rend(), [&](char ch){cout << ch;});
    cout << '\n';
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    static const string s1 = "bbabcbcab"; // bacbcab // 7
    static const string s2 = "geeksforgeeks"; // eegee // 5
    cout << rec(s1) << endl;
    cout << rec(s2) << endl;
    cout << '\n';
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
    cout << '\n';
    cout << rec_elems(s1) << endl;
    cout << rec_elems(s2) << endl;
    cout << '\n';
    cout << tab_elems(s1) << endl;
    cout << tab_elems(s2) << endl;
}

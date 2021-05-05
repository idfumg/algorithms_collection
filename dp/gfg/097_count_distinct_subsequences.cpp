#include "../../template.hpp"

int naive(string s) {
    unordered_set<string> ans;
    int n = s.size();
    for (int i = 0; i < (1 << n); ++i) {
        string temp;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                temp += s[j];
            }
        }
        ans.insert(temp);
    }
    return ans.size();
}

void naive2(string s, int n, unordered_set<string>& ans, string& temp) {
    if (n == 0) {
        ans.insert(temp);
        return;
    }
    temp.push_back(s[n - 1]);
    naive2(s, n - 1, ans, temp);
    temp.pop_back();
    naive2(s, n - 1, ans, temp);
}

int naive2(string s) {
    unordered_set<string> ans;
    string temp;
    naive2(s, s.size(), ans, temp);
    return ans.size();
}

int tab(string s) {
    int n = s.size();
    vi visited(256, -1);
    vi dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] * 2;
        if (visited[s[i - 1] - '0'] != -1) {
            dp[i] -= dp[visited[s[i - 1] - '0'] - 1];
        }
        visited[s[i - 1] - '0'] = i;
    }
    return dp[n];
}

int main() { // TimeMeasure _; __x();
    const string s1 = "gfg"; // 7
    const string s2 = "ggg"; // 4

    cout << naive(s1) << endl;
    cout << naive(s2) << endl;
    cout << endl;
    cout << naive2(s1) << endl;
    cout << naive2(s2) << endl;
    cout << endl;
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
}

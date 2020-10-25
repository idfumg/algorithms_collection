#include "../../template.hpp"

void naive(string s, unordered_set<string>& ans, string& current, int from) {
    int n = s.size();
    if (from == n) {
        ans.insert(current);
        return;
    }
    for (int i = from; i < n; ++i) {
        naive(s, ans, current, i + 1);
        current.push_back(s[i]);
        naive(s, ans, current, i + 1);
        current.pop_back();
    }
}

int naive(string s) {
    unordered_set<string> ans;
    string current;
    naive(s, ans, current, 0);
    return ans.size();
}

int tab(string s) {
    int n = s.size();
    vi dp(n + 1, 1);
    vi last(27, -1);
    for (int i = 1; i <= n; ++i) {
        int ch = s[i - 1] - 'a';
        dp[i] = 2 * dp[i - 1];
        if (last[ch] != -1) {
            dp[i] = 2 * dp[i - 1] - dp[last[ch] - 1];
        }
        last[ch] = i;
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    const string s1 = "gfg"; // 7
    const string s2 = "ggg"; // 4
    cout << naive(s1) << endl;
    cout << naive(s2) << endl;
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
}

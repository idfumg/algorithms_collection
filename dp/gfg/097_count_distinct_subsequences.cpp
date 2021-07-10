#include "../../template.hpp"

int naive(string s) {
    int n = s.size();
    unordered_set<string> ans;
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

void rec(string s, int n, string& temp, unordered_set<string>& ans) {
    if (n == 0) {
        ans.insert(temp);
        return;
    }
    temp += s[n - 1];
    rec(s, n - 1, temp, ans);
    temp.pop_back();
    rec(s, n - 1, temp, ans);
}

int rec(string s) {
    unordered_set<string> ans;
    string temp;
    rec(s, s.size(), temp, ans);
    return ans.size();
}

int rec2(string s, int n) {
    if (n == 0) return 1;
    int count = 2 * rec2(s, n - 1);
    for (int j = n - 1; j >= 1; --j) {
        if (s[j - 1] == s[n - 1]) {
            count -= rec2(s, j - 1);
            break;
        }
    }
    return count;
}

int rec2(string s) {
    return rec2(s, s.size());
}

int tab(string s) {
    int n = s.size();
    vi visited(256, -1);
    vi dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 2 * dp[i - 1];
        if (visited[s[i - 1] - '0'] != -1) {
            dp[i] -= dp[visited[s[i - 1] - '0'] - 1];
        }
        visited[s[i - 1] - '0'] = i;
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    const string s1 = "gfg"; // 7
    const string s2 = "ggg"; // 4
    const string s3 = "ggg123eree1"; // 4

    cout << naive(s1) << endl;
    cout << naive(s2) << endl;
    cout << naive(s3) << endl;
    cout << endl;
    cout << rec(s1) << endl;
    cout << rec(s2) << endl;
    cout << rec(s3) << endl;
    cout << endl;
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
    cout << tab(s3) << endl;
}

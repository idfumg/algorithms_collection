#include "../../template.hpp"

static const unordered_set<string> words = {
    "mobile","samsung","sam","sung",
    "man","mango","icecream","and",
    "go","i","like","ice","cream",
};

bool rec(const string& s, int n, int count) {
    if (n == 0 and count == 1) return true;
    if (n == 0 and count != 1) return false;
    if (words.count(s.substr(n - 1, count))) return rec(s, n - 1, 1) or rec(s, n - 1, count + 1);
    return rec(s, n - 1, count + 1);
}

bool rec(const string& s) {
    return rec(s, s.size(), 1);
}

bool tab(const string& s) {
    int n = size(s);
    vi dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (words.count(s.substr(j, i - j)) and dp[j]) {
                dp[i] = 1;
            }
        }
    }
    return dp[n];
}

bool tab2(const string& s) {
    int n = size(s);
    vvi dp(n + 2, vi(n + 2));
    dp[0][1] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= 0; --j) {
            if (words.count(s.substr(i - 1, j))) dp[i][j] = dp[i - 1][1] or dp[i - 1][j + 1];
            else dp[i][j] = dp[i - 1][j + 1];
        }
    }
    return dp[n][1];
}

bool opt2(const string& s) {
    int n = size(s), idx = 0;
    vvi dp(2, vi(n + 2));
    dp[0][1] = true;
    for (int i = 1; i <= n; ++i) {
        idx = i & 1;
        for (int j = n; j >= 0; --j) {
            if (words.count(s.substr(i - 1, j))) dp[idx][j] = dp[1 - idx][1] or dp[1 - idx][j + 1];
            else dp[idx][j] = dp[1 - idx][j + 1];
        }
    }
    return dp[idx][1];
}

int main() { TimeMeasure _; __x();
    cout << rec("ilikesamsung") << endl;
    cout << rec("iiiiiiii") << endl;
    cout << rec("") << endl;
    cout << rec("ilikelikeimangoiii") << endl;
    cout << rec("samsungandmango") << endl;
    cout << rec("samsungandmangok") << endl;
    cout << endl;
    cout << tab("ilikesamsung") << endl;
    cout << tab("iiiiiiii") << endl;
    cout << tab("") << endl;
    cout << tab("ilikelikeimangoiii") << endl;
    cout << tab("samsungandmango") << endl;
    cout << tab("samsungandmangok") << endl;
    cout << endl;
    cout << tab2("ilikesamsung") << endl;
    cout << tab2("iiiiiiii") << endl;
    cout << tab2("") << endl;
    cout << tab2("ilikelikeimangoiii") << endl;
    cout << tab2("samsungandmango") << endl;
    cout << tab2("samsungandmangok") << endl;
    cout << endl;
    cout << opt2("ilikesamsung") << endl;
    cout << opt2("iiiiiiii") << endl;
    cout << opt2("") << endl;
    cout << opt2("ilikelikeimangoiii") << endl;
    cout << opt2("samsungandmango") << endl;
    cout << opt2("samsungandmangok") << endl;
}

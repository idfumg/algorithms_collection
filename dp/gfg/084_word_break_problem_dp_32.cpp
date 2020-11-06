#include "../../template.hpp"

static const unordered_set<string> words = {
    "mobile","samsung","sam","sung",
    "man","mango","icecream","and",
    "go","i","like","ice","cream",
};

bool rec(const string& s, int i, int count) {
    int n = s.size();
    if (i > n and count == 1) {
        return true;
    }
    if (i > n or count > n) {
        return false;
    }
    if (words.count(s.substr(i - 1, count)) and rec(s, i + count, 1)) {
        return true;
    }
    return rec(s, i, count + 1);
}

bool rec(const string& s) {
    return rec(s, 1, 1);
}

bool rec2(const string& s, int i, int count) {
    if (i == 0 and count == 1) {
        return true;
    }
    if (i == 0 and count != 1) {
        return false;
    }
    if (words.count(s.substr(i - 1, count)) and rec2(s, i - 1, 1)) {
        return true;
    }
    return rec2(s, i - 1, count + 1);
}

bool rec2(const string& s) {
    int n = s.size();
    return rec2(s, n, 1);
}

bool tab(const string& s) {
    int n = s.size();
    vvi dp(n + 1, vi(n + 2));
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= 1; --j) {
            if (words.count(s.substr(i - 1, j)) and dp[i - 1][1]) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j + 1];
            }
        }
    }
    return dp[n][1];
}

void rec_elems(const string& s, vvi& dp, int i, int count) {
    if (i == 0 and count == 1) {
        return;
    }
    if (i == 0 and count != 1) {
        return;
    }
    if (dp[i - 1][1] and dp[i][count]) {
        cout << s.substr(i - 1, count) << ' ';
        rec_elems(s, dp, i - 1, 1);
        return;
    }
    if (dp[i - 1][count + 1]) {
        rec_elems(s, dp, i - 1, count + 1);
    }
}

void rec_elems(const string& s) {
    int n = s.size();
    vvi dp(n + 1, vi(n + 2));
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= 1; --j) {
            if (words.count(s.substr(i - 1, j)) and dp[i - 1][1]) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j + 1];
            }
        }
    }
    rec_elems(s, dp, n, 1);
}

int main() { TimeMeasure _; __x();
    cout << rec("ilikesamsung") << endl; // true
    cout << rec("iiiiiiii") << endl; // true
    cout << rec("") << endl; // true
    cout << rec("ilikelikeimangoiii") << endl; // true
    cout << rec("samsungandmango") << endl; // true
    cout << rec("samsungandmangok") << endl; // false
    cout << endl;
    cout << rec2("ilikesamsung") << endl; // true
    cout << rec2("iiiiiiii") << endl; // true
    cout << rec2("") << endl; // true
    cout << rec2("ilikelikeimangoiii") << endl; // true
    cout << rec2("samsungandmango") << endl; // true
    cout << rec2("samsungandmangok") << endl; // false
    cout << endl;
    cout << tab("ilikesamsung") << endl;
    cout << tab("iiiiiiii") << endl;
    cout << tab("") << endl;
    cout << tab("ilikelikeimangoiii") << endl;
    cout << tab("samsungandmango") << endl;
    cout << tab("samsungandmangok") << endl;
    cout << endl;
    rec_elems("ilikesamsung"); cout << endl;
    rec_elems("iiiiiiii"); cout << endl;
    rec_elems(""); cout << endl;
    rec_elems("ilikelikeimangoiii"); cout << endl;
    rec_elems("samsungandmango"); cout << endl;
    rec_elems("samsungandmangok"); cout << endl;
}

#include "../../template.hpp"

struct Palindrome {
    string left;
    string right;
    std::size_t size() const noexcept { return left.size() + right.size(); }
};

void rec(const string& s, Palindrome& current, Palindrome& res, int i, int j) {
    if (i > j) {
        if (current.size() > res.size()) res = current;
        return;
    }
    if (i == j) {
        current.left += s[i];
        rec(s, current, res, i + 1, j - 1);
        current.left.pop_back();
        return;
    }
    if (s[i] == s[j]) {
        current.left += s[i];
        current.right += s[j];
        rec(s, current, res, i + 1, j - 1);
        current.left.pop_back();
        current.right.pop_back();
        return;
    }
    rec(s, current, res, i + 1, j);
    rec(s, current, res, i, j - 1);
}

string rec(const string& s) {
    Palindrome current, res;
    rec(s, current, res, 0, s.size() - 1);
    reverse(res.right);
    return res.left + res.right;
}

string tab(const string& s) {
    int n = s.size();
    vvi dp(n + 1, vi(n + 1));
    vvvi prev(n + 1, vvi(n + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (i == j) {
                dp[i][j] = 1;
                prev[i][j] = {i + 1, j - 1, 2};
            }
            else if (s[i - 1] == s[j - 1]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
                prev[i][j] = {i + 1, j - 1, 1};
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
    string left;
    string right;
    for (vi at = prev[1][n]; not at.empty(); at = prev[at[0]][at[1]]) {
        if (at[2] == 1) {
            left += s[at[1]];
            right += s[at[1]];
        }
        else if (at[2] == 2) {
            left += s[at[1]];
        }
    }
    reverse(right);
    return left + right;
}

int main() { TimeMeasure _; __x();
    static const string s1 = "bbabcbcab"; // bacbcab
    static const string s2 = "geeksforgeeks"; // eegee
    cout << rec(s1) << endl;
    cout << rec(s2) << endl;
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
}

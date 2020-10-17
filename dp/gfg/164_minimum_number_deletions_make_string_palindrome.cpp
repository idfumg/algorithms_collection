#include "../../template.hpp"

int tab(const string& s) { // With Longest Palindromic Subsequence (How long subseq from i..j)
    int n = s.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = n - 1; i >= 1; --i) {
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
    return n - dp[1][n];
}

int tab2(const string& s) { // With Straightforward Algorithm (How minimum to delete in i..j)
    int n = s.size();
    vvi dp(n + 1, vi(n + 1));
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (s[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    cout << tab("baca") << endl; // 1
    cout << tab("geek") << endl; // 2
    cout << tab("aebcbda") << endl; // 2
    cout << tab("geeksforgeeks") << endl; // 8
    cout << endl;
    cout << tab2("baca") << endl; // 1
    cout << tab2("geek") << endl; // 2
    cout << tab2("aebcbda") << endl; // 2
    cout << tab2("geeksforgeeks") << endl; // 8
}

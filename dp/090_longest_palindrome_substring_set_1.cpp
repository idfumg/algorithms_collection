#include "../../template.hpp"

int tab(const string& s) {
    const int n = s.size();
    vvi dp(n, vi(n));
    int count = -INF, position = 0;

    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        if (count < dp[i][i]) {
            count = dp[i][i];
            position = i;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 2;
            if (count < dp[i][i + 1]) {
                count = dp[i][i + 1];
                position = i;
            }
        }
    }

    for (int k = 2; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            int j = i + k;
            if (j < n && s[i] == s[j] && dp[i + 1][j - 1] != 0) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
                if (count < dp[i][j]) {
                    count = dp[i][j];
                    position = i;
                }
            }
        }
    }

    cout << s.substr(position, count) << endl;
    return count;
}

int tab2(const string& s) {
    int n = s.size(), maxi = -INF, maxipos = 0;
    vvi dp(n + 2, vi(n + 2));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) {
                dp[i][j] = 0;
            }
            else if (i == j) {
                dp[i][j] = 1;
            }
            else if (j - i == 1 and s[i - 1] == s[j - 1]) {
                dp[i][j] = 2;
            }
            else if (s[i - 1] == s[j - 1] and dp[i + 1][j - 1] > 0) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            if (dp[i][j] > maxi) {
                maxi = dp[i][j];
                maxipos = i;
            }
        }
    }
    cout << s.substr(maxipos - 1, maxi) << endl;
    return maxi;
}

tuple<int, int> FindPalindrome(const string& s, int left, int right) {
    while (left > 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    if (s[left + 1] == s[right - 1]) return make_tuple(right - left - 1, left + 1);
    return make_tuple(-1, -1);
}

int fast(const string& s) {
    int count = 0, position = 0;
    for (int i = 0; i < s.size(); ++i) {
        const auto& [count1, position1] = FindPalindrome(s, i, i);
        const auto& [count2, position2] = FindPalindrome(s, i, i + 1);
        if (count1 > count) {
            count = count1; position = position1;
        }
        if (count2 > count) {
            count = count2; position = position2;
        }
    }
    cout << s.substr(position, count) << endl;
    return count;
}

int main() { TimeMeasure _; __x();
    static const string s1 = "forgeeksskeegfor"; // geeksskeeg // 10
    static const string s2 = "Geeks"; // ee // 2
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
    cout << tab2(s1) << endl;
    cout << tab2(s2) << endl;
    cout << fast(s1) << endl;
    cout << fast(s2) << endl;
}

#include "../template.hpp"

static const unordered_set<string> words = {
    "this", "th", "is", "famous", "Word", "break",
    "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem",
};

static vvb GetLookupTable(const string& s) noexcept {
    const int n = size(s);
    vvb dp(n + 1, vb(n + 2));
    for (int i = 0; i <= n; ++i) {
        for (int j = n; j >= 1; --j) {
            if (i == 0 and j == 1) {
                dp[i][j] = true;
            }
            else if (i == 0 and j != 1) {
                dp[i][j] = false;
            }
            else {
                const auto word = s.substr(i - 1, j);
                if (words.count(word)) {
                    dp[i][j] = dp[i - 1][1];
                }
                else {
                    dp[i][j] = dp[i - 1][j + 1];
                }
            }
        }
    }
    return dp;
}

static bool helper(const string& s, int pos, int count, vector<string>& res, const vvb& dp) noexcept {
    if (pos == 0 and count == 1) {
        for (int i = size(res) - 1; i >= 0; --i) {
            cout << res[i] << " ";
        }
        cout << endl;
        return true;
    }
    if (pos == 0 && count != 1) {
        return false;
    }
    if (dp[pos][count]) {
        const auto word = s.substr(pos - 1, count);
        if (words.count(word)) {
            res.push_back(word);
            helper(s, pos - 1, 1, res, dp);
            res.pop_back();
        }
    }
    while (pos > 1 and not dp[pos - 1][count + 1]) {
        --pos;
        ++count;
    }
    return helper(s, pos - 1, count + 1, res, dp);
}

void WordBreak(const string& s) {
    const auto dp = GetLookupTable(s);
    if (not dp[size(s)][1]) {
        cout << "String can't be segmented" << endl;
        return;
    }
    vector<string> res;
    helper(s, size(s), 1, res, dp);
}

int main() { TimeMeasure _; __x();
    WordBreak("Wordbreakproblem");
}

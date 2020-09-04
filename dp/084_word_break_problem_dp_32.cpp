#include "../template.hpp"

bool rec(vector<string>& elems, const unordered_set<string>& words, const string& word, const int at, const int count) {
    if (at == -1 && count == 1) {
        //debug(elems);
        return true;
    }
    if (at < 0) return false;

    const auto suffix = word.substr(at, count);
    if (words.count(suffix) > 0) {
        elems.push_back(suffix);
        if (rec(elems, words, word, at - 1, 1)) {
            return true;
        }
        elems.pop_back();
    }
    return rec(elems, words, word, at - 1, count + 1);
}

bool rec(const unordered_set<string>& words, const string& word) {
    vector<string> elems;
    return rec(elems, words, word, word.size() - 1, 1);
}

bool tab(const unordered_set<string>& words, const string& word) {
    const int n = word.size();
    vb dp(n + 1);
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            const auto suffix = word.substr(j, i - j);
            if (dp[j] && words.count(suffix) > 0) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

bool tab2(const string& s) noexcept {
    int n = s.size();
    vvi dp(n + 2, vi(n + 2));
    for (int i = 0; i <= n; ++i) {
        for (int j = n; j >= 0; --j) {
            if (i == 0 and j <= 1) dp[i][j] = 1;
            else if (i == 0 and j != 1) dp[i][j] = 0;
            else if (words.count(s.substr(i - 1, j))) dp[i][j] = dp[i - 1][1] or dp[i - 1][j + 1];
            else dp[i][j] = dp[i - 1][j + 1];
        }
    }
    return dp[n][1];
}

int main() { TimeMeasure _; __x();
    static const unordered_set<string> wordsList = {
        "mobile","samsung","sam","sung",
        "man","mango","icecream","and",
        "go","i","like","ice","cream",
    };

    cout << rec(wordsList, "ilikesamsung") << endl;
    cout << rec(wordsList, "iiiiiiii") << endl;
    cout << rec(wordsList, "") << endl;
    cout << rec(wordsList, "ilikelikeimangoiii") << endl;
    cout << rec(wordsList, "samsungandmango") << endl;
    cout << rec(wordsList, "samsungandmangok") << endl;
    cout << endl;
    cout << tab(wordsList, "ilikesamsung") << endl;
    cout << tab(wordsList, "iiiiiiii") << endl;
    cout << tab(wordsList, "") << endl;
    cout << tab(wordsList, "ilikelikeimangoiii") << endl;
    cout << tab(wordsList, "samsungandmango") << endl;
    cout << tab(wordsList, "samsungandmangok") << endl;
    cout << endl;
    cout << tab2(wordsList, "ilikesamsung") << endl;
    cout << tab2(wordsList, "iiiiiiii") << endl;
    cout << tab2(wordsList, "") << endl;
    cout << tab2(wordsList, "ilikelikeimangoiii") << endl;
    cout << tab2(wordsList, "samsungandmango") << endl;
    cout << tab2(wordsList, "samsungandmangok") << endl;
}

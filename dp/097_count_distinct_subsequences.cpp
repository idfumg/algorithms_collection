#include "../template.hpp"

void brute(const string& s, set<string>& seqs, string& current, int from) {
    if (from >= s.size()) {
        seqs.insert(current);
        return;
    }
    for (int i = from; i < s.size(); ++i) {
        current.push_back(s[i]);
        brute(s, seqs, current, i + 1);
        current.pop_back();

        brute(s, seqs, current, i + 1);
    }
}

int brute(const string& s) {
    set<string> seqs;
    string current;
    brute(s, seqs, current, 0);
    return seqs.size();
}

int tab(const string& s) {
    const int n = s.size();
    vi dp(n + 1), last_occurence(256, -1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 2 * dp[i - 1];
        if (last_occurence[s[i - 1]] != -1) {
            dp[i] = dp[i] - dp[last_occurence[s[i - 1]]];
        }
        last_occurence[s[i - 1]] = i - 1;
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    const string s1 = "gfg"; // 7
    const string s2 = "ggg"; // 4
    cout << brute(s1) << endl;
    cout << brute(s2) << endl;
    cout << tab(s1) << endl;
    cout << tab(s2) << endl;
}

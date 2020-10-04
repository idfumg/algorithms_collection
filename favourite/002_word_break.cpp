#include "../template.hpp"

static const unordered_set<string> words = {
    "mobile","samsung","sam","sung",
    "man","mango","icecream","and",
    "go","i","like","ice","cream",
};

bool naive(const string& word, int from) {
    int n = word.size();
    if (from >= n) {
        return true;
    }
    for (int i = from; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (words.count(word.substr(i, j))) {
                if (naive(word, i + j)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool naive(const string& word) { // Straightworward check for an every variant
    return naive(word, 0);
}

bool rec(const string& word, int from, int count) {
    if (from == 0 and count == 1) {
        return true;
    }
    if (from == 0 and count > 1) {
        return false;
    }
    if (words.count(word.substr(from - 1, count)) and rec(word, from - 1, 1)) {
        return true;
    }
    return rec(word, from - 1, count + 1);
}

bool rec(const string& word) { // More ideological recursive solution (0.. n)
    return rec(word, word.size(), 1);
}

bool tab(const string& word) { // Iterative Dynamic Programming solution
    int n = word.size();
    vvb dp(n + 1, vb(n + 2));
    dp[0][1] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= 1; --j) {
            if (words.count(word.substr(i - 1, j)) and dp[i - 1][1]) {
                dp[i][j] = true;
            }
            dp[i][j] = dp[i][j] or dp[i - 1][j + 1];
        }
    }
    return dp[n][1];
}

void rec_elems(const string& word, vvb& dp, vector<string>& elems, int from, int count) {
    if (from == 0 and count == 1) {
        int n = elems.size();
        for (int i = n - 1; i >= 0; --i) cout << elems[i] << ' ';
        cout << '\n';
        return;
    }
    if (from == 0 and count != 1) {
        return;
    }
    if (dp[from][count]) {
        const auto temp = word.substr(from - 1, count);
        if (words.count(temp)) {
            elems.push_back(temp);
            rec_elems(word, dp, elems, from - 1,1);
            elems.pop_back();
            //return;
        }
    }
    while (from > 1 and not dp[from - 1][count + 1]) {
        --from;
        ++count;
    }
    rec_elems(word, dp, elems, from - 1, count + 1);
}

void rec_elems(const string& word, vvb& dp) {
    vector<string> elems;
    rec_elems(word, dp, elems, word.size(), 1);
}

void rec_elems(const string& word) { // Print all segmented words
    int n = word.size();
    vvb dp(n + 1, vb(n + 2));
    dp[0][1] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= 1; --j) {
            if (words.count(word.substr(i - 1, j)) and dp[i - 1][1]) {
                dp[i][j] = true;
            }
            dp[i][j] = dp[i][j] or dp[i - 1][j + 1];
        }
    }
    if (not dp[n][1]) {
        cout << '-' << '\n';
        return;
    }
    cout << '"' << word << '"' << ':' << '\n';
    rec_elems(word, dp);
    cout << '\n';
}

int main() { TimeMeasure _; __x();
    cout << naive("ilikesamsung") << endl; // true
    cout << naive("iiiiiiii") << endl; // true
    cout << naive("") << endl; // true
    cout << naive("ilikelikeimangoiii") << endl; // true
    cout << naive("samsungandmango") << endl; // true
    cout << naive("samsungandmangok") << endl; // false
    cout << endl;
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
    rec_elems("ilikesamsung");
    rec_elems("iiiiiiii");
    rec_elems("");
    rec_elems("ilikelikeimangoiii");
    rec_elems("samsungandmango");
    rec_elems("samsungandmangok");
}

#include "../template.hpp"

void Naive(const string& t, const string& s) {
    const size_t m = t.size();
    const size_t n = s.size();
    for (size_t i = 0; i < n; ++i) {
        bool found = true;
        for (size_t j = 0; j < m; ++j) {
            if (s[i + j] != t[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            cout << i << ' ';
        }
    }
    cout << endl;
}

vector<size_t> PrefixFunction(const string& s) {
    const size_t n = s.size();
    vector<size_t> pi(n);
    for (size_t i = 1; i < n; ++i) {
        size_t j = pi[i - 1];
        while (j > 0 and s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}

void FindOccurencies(const string& t, const string& s) {
    const vector<size_t> pi = PrefixFunction(t);
    const size_t m = t.size();
    const size_t n = s.size();
    size_t j = 0;
    for (size_t i = 0; i < n; ++i) {
        while (j > 0 and s[i] != t[j]) {
            j = pi[j - 1];
        }
        if (s[i] == t[j]) {
            ++j;
        }
        if (j == m) {
            cout << (i - m + 1) << ' ';
        }
    }
    cout << endl;
}

int main() { TimeMeasure _;
    Naive("ааbаа", "ааbааbааааbааbаааb"); // 0 5 14 19
    FindOccurencies("ааbаа", "ааbааbааааbааbаааb"); // 0 5 14 19
}

#include "../../template.hpp"

void LexiLargest(string s, int k) {
    int n = s.size();

    vi freq(27);
    for (char ch : s) {
        ++freq[ch - 'a'];
    }

    for (int i = 0; i < n; ++i) {
        if (freq[s[i] - 'a'] < k) {
            --freq[s[i] - 'a'];
            s[i] = ' ';
        }
        else {
            if (i + 1 < n) {
                if (s[i] < s[i + 1]) {
                    --freq[s[i] - 'a'];
                    s[i] = ' ';
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] != ' ') {
            cout << s[i];
        }
    }
    cout << '\n';
}

int main() { TimeMeasure _; __x();
    LexiLargest("banana", 2); // nn
}

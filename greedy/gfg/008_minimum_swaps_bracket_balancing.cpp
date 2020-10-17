#include "../../template.hpp"

void MinSwapsToBalanceBrackets(const string& s) {
    int left = 0, right = 0, n = s.size(), swaps = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '[' and right == 0) {
            ++left;
        }
        else if (s[i] == '[' and right > 0) { // swap
            swaps += right;
            --right;
        }
        else if (s[i] == ']' and left == 0) {
            ++right;
        }
        else if (s[i] == ']' and left > 0) {
            --left;
        }
    }
    cout << swaps << '\n';
}

int main() { TimeMeasure _;
    MinSwapsToBalanceBrackets("]][["); // 3
    MinSwapsToBalanceBrackets("[]][]["); // 2
    MinSwapsToBalanceBrackets("[[][]]"); // 0
    MinSwapsToBalanceBrackets("][][]["); // 3
    MinSwapsToBalanceBrackets("[[]][]"); // 0
}

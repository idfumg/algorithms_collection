#include "../../template.hpp"

void MinSwapsToBalanceBrackets(string s) {
    int n = s.size();
    int left = 0;
    int right = 0;
    int ans = 0;
    for (char ch : s) {
        if (ch == '[') {
            if (right == 0) {
                ++left;
            }
            else {
                ans += right;
                --right;
            }
        }
        else if (ch == ']') {
            if (left == 0) {
                ++right;
            }
            else {
                --left;
            }
        }
    }
    cout << ans << endl;
}

int main() { TimeMeasure _; __x();
    MinSwapsToBalanceBrackets("]][["); // 3
    MinSwapsToBalanceBrackets("[]][]["); // 2
    MinSwapsToBalanceBrackets("[[][]]"); // 0
    MinSwapsToBalanceBrackets("][][]["); // 3
    MinSwapsToBalanceBrackets("[[]][]"); // 0
}

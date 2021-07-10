#include "../../template.hpp"

void MinSwapsToBalanceBrackets(string s) {
    int left = 0, right = 0, ans = 0;
    for (char ch : s) {
        if (ch == '[' and right == 0) ++left;
        else if (ch == ']' and left == 0) ++right;
        else if (ch == '[') ans += right, right -= 1;
        else if (ch == ']') left -= 1;
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

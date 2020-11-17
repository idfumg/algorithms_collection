#include "../../template.hpp"

void BalancedParenthesesDepth(string s) {
    stack<char> stack;
    int count = 0;
    int maxCount = 0;
    for (char ch : s) {
        if (ch == '(') {
            stack.push(ch);
            count = 0;
        }
        else if (ch == ')') {
            if (stack.empty() or stack.top() != '(') {
                cout << -1 << endl;
                return;
            }
            else {
                stack.pop();
                ++count;
            }
        }
        maxCount = max(maxCount, count);
    }
    if (stack.empty()) {
        cout << maxCount << endl;
    }
    else {
        cout << -1 << endl;
    }
}

int main() { TimeMeasure _;
    BalancedParenthesesDepth("(((X)) (((Y))))"); // 4
    BalancedParenthesesDepth("( a(b) (c) (d(e(f)g)h) I (j(k)l)m)"); // 4
    BalancedParenthesesDepth("( p((q)) ((s)t) )"); // 3
    BalancedParenthesesDepth(""); // 0
    BalancedParenthesesDepth("b) (c) ()"); // -1
    BalancedParenthesesDepth("(b) ((c) ()"); // -1
}

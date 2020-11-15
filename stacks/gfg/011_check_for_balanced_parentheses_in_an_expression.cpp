#include "../../template.hpp"

bool IsMatchedParentheses(char ch1, char ch2) {
    return
        (ch1 == ')' and ch2 == '(') or
        (ch1 == '}' and ch2 =='{') or
        (ch1 == ']' and ch2 == '[');
}

bool CheckParentheses(string s) {
    stack<char> stack;
    for (char ch : s) {
        if (ch == '(' or ch == '{' or ch == '[') {
            stack.push(ch);
        }
        else if (not stack.empty() and IsMatchedParentheses(ch, stack.top())) {
            stack.pop();
        }
        else {
            break;
        }
    }
    return stack.empty();
}

int main() { TimeMeasure _;
    cout << CheckParentheses("[()]{}{[()()]()}”") << '\n'; // true
    cout << CheckParentheses("[(])") << '\n'; // false
    cout << CheckParentheses("{()}[]") << '\n'; // true
    cout << CheckParentheses("(((())))") << '\n'; // true
}

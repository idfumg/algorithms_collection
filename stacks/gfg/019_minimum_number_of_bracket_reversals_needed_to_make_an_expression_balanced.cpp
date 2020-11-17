#include "../../template.hpp"

int MinReversalsToMakeBalanced(string s) {
    int count = 0;
    stack<char> stack;
    for (char ch : s) {
        if (ch == '{') {
            stack.push(ch);
        }
        else {
            if (stack.empty() or stack.top() != '{') {
                stack.push(ch);
            }
            else {
                stack.pop();
            }
        }
    }
    while (not stack.empty()) {
        if (stack.size() < 2) {
            return -1;
        }
        char ch = stack.top(); stack.pop();
        if (stack.top() == '}' and ch == '{') {
            count += 2;
            stack.pop();
        }
        else if (stack.top() == '{' and ch == '{') {
            count += 1;
            stack.pop();
        }
        else if (stack.top() == '}' and ch == '}') {
            count += 1;
            stack.pop();
        }
    }
    return count;
}

int main() { TimeMeasure _;
    cout << MinReversalsToMakeBalanced("}{") << endl; // 2
    cout << MinReversalsToMakeBalanced("{{{") << endl; // -1
    cout << MinReversalsToMakeBalanced("{{{{") << endl; // 2
    cout << MinReversalsToMakeBalanced("{{{{}}") << endl; // 1
    cout << MinReversalsToMakeBalanced("}}{{}}") << endl; // 1
    cout << MinReversalsToMakeBalanced("}{{}}{{{") << endl; // 3
}

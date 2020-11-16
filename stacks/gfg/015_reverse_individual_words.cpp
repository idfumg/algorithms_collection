#include "../../template.hpp"

void ReverseWords(string s) {
    stack<char> stack;
    for (char ch : s) {
        if (isspace(ch)) {
            while (not stack.empty()) {
                cout << stack.top(); stack.pop();
            }
            cout << ch;
        }
        else {
            stack.push(ch);
        }
    }
    while (not stack.empty()) {
        cout << stack.top(); stack.pop();
    }
    cout << endl;
}

int main() { TimeMeasure _;
    ReverseWords("Hello World");
    ReverseWords("Geeks for Geeks");
}

#include "../../template.hpp"

void ReverseStringWithStack(string s) {
    stack<char> stack;
    for (char ch : s) {
        stack.push(ch);
    }
    debugn(stack);
}

int main() { TimeMeasure _;
    ReverseStringWithStack("GeeksQuiz"); // ziuQskeeG
}

#include "../../template.hpp"

bool isoperator(char ch) {
    return ch == '*' or ch == '-' or ch == '+' or ch == '^' or ch == '/';
}

string PostfixToInfix(const string& s) {
    int n = s.size();
    stack<string> st;
    for (int i = 0; i < n; ++i) {
        if (isalpha(s[i])) {
            st.push(string(1, s[i]));
        }
        else if (isoperator(s[i])) {
            auto operand1 = st.top(); st.pop();
            auto operand2 = st.top(); st.pop();
            st.push("(" + operand2 + s[i] + operand1 + ")");
        }
    }
    return st.top();
}

int main() { TimeMeasure _;
    cout << PostfixToInfix("ab*c+") << '\n';
}

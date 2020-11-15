#include "../../template.hpp"

bool isoperator(char ch) {
    return ch == '*' or ch == '-' or ch == '+' or ch == '^' or ch == '/';
}

string PrefixToPostfix(const string& s) {
    int n = s.size();
    stack<string> st;
    for (int i = n - 1; i >= 0; --i) {
        if (isalpha(s[i])) {
            st.push(string(1, s[i]));
        }
        else if (isoperator(s[i])) {
            auto op = string(1, s[i]);
            auto operand1 = st.top(); st.pop();
            auto operand2 = st.top(); st.pop();
            st.push(operand1 + operand2 + op);
        }
    }
    return st.top();
}

int main() { TimeMeasure _;
    cout << PrefixToPostfix("*-A/BC-/AKL") << '\n';
}

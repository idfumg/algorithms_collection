#include "../../template.hpp"

bool isoperator(char ch) {
    return ch == '*' or ch == '-' or ch == '+' or ch == '^' or ch == '/';
}

string PrefixToInfix(const string& s) {
    stack<string> st;

    int n = s.size();
    for (int i = n - 1; i >= 0; --i) {
        if (isalpha(s[i])) {
            st.push(string(1, s[i]));
        }
        else if (isoperator(s[i])) {
            auto op = string(1, s[i]);
            auto operand1 = st.top(); st.pop();
            auto operand2 = st.top(); st.pop();
            st.push("(" + operand1 + op + operand2 + ")");
        }
    }

    return st.top();
}

int main() { TimeMeasure _;
    cout << PrefixToInfix("*-A/BC-/AKL") << '\n';
}

#include "../../template.hpp"

int prec(char ch) {
    if (ch == '^') {
        return 3;
    }
    else if (ch == '*' or ch == '/') {
        return 2;
    }
    else if (ch == '+' or ch == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

string InfixToPostfix(const string& s) {
    string ans;
    stack<char> st;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        if ((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z')) {
            ans += s[i];
        }
        else if (s[i] == '(') {
            st.push('(');
        }
        else if (s[i] == ')') {
            while (not st.empty() and st.top() != '(') {
                ans += st.top(); st.pop();
            }
            if (st.top() == '(') {
                st.pop();
            }
        }
        else {
            while (not st.empty() and prec(s[i]) <= prec(st.top())) {
                ans += st.top(); st.pop();
            }
            st.push(s[i]);
        }
    }

    while (not st.empty()) {
        ans += st.top(); st.pop();
    }

    return ans;
}

int main() { TimeMeasure _;
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << InfixToPostfix(exp) << '\n'; // abcd^e-fgh*+^*+i-
}

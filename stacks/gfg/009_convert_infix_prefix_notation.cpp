#include "../../template.hpp"

bool isoperator(char ch) {
    return ch == '*' or ch == '-' or ch == '+' or ch == '^' or ch == '/';
}

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
        if (isalpha(s[i]) or isdigit(s[i])) {
            ans += s[i];
        }
        else if (s[i] == '(') {
            st.push('(');
        }
        else if (s[i] == ')') {
            while (not st.empty() and st.top() != '(') {
                ans += st.top(); st.pop();
            }
            st.pop();
        }
        else if (isoperator(s[i])) {
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

string InfixToPrefix(string s) {
    reverse(s.begin(), s.end());
    for (char& ch : s) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    auto ans = InfixToPostfix(s);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() { TimeMeasure _;
    cout << InfixToPrefix("(a-b/c)*(a/k-l)") << '\n'; //*-a/bc-/akl
}

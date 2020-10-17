#include "../../template.hpp"

vi GenFibTerms(int n) {
    vi terms(3);
    terms[0] = 0;
    terms[1] = 1;
    terms[2] = 1;
    int i = 3;
    while (terms.back() <= n) {
        terms.push_back(terms[i - 1] + terms[i - 2]);
        ++i;
    }
    if (terms.back() > n) {
        terms.pop_back();
    }
    return terms;
}

int CountOfFibTerms(int sum) {
    vi terms = GenFibTerms(sum);
    int n = terms.size(), ans = 0;
    for (int i = n - 1; i >= 1; --i) {
        int count = sum / terms[i];
        if (count > 0) {
            sum -= count * terms[i];
            ans += count;
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << CountOfFibTerms(4) << '\n';
    cout << CountOfFibTerms(17) << '\n';
    cout << CountOfFibTerms(0) << '\n';
    cout << CountOfFibTerms(1) << '\n';
    cout << CountOfFibTerms(-1) << '\n';
    cout << CountOfFibTerms(-INF) << '\n';
    cout << CountOfFibTerms(INF) << '\n';
}

#include "../../template.hpp"

int BinaryStringToNumber(const string& s) {
    int res = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
        res += (s[n - i - 1] - '0' == 1) << i;
    }
    return res;
}

int rec(int n, int prev, string& elems) {
    if (n == 0) {
        cout << BinaryStringToNumber(elems) << ' ';
        return 1;
    }
    if (n < 0) return 0;
    int count = 0;
    for (int i : {0, 1}) {
        if (prev == 1 and i == 1) continue;
        elems.push_back(to_string(i)[0]);
        count += rec(n - 1, i, elems);
        elems.pop_back();
    }
    return count;
}

int rec(int n) {
    if (n == 0) return 0;
    string elems;
    int count = 0;
    for (int i : {0, 1}) {
        elems.push_back(to_string(i)[0]);
        count += rec(n - 1, i, elems);
        elems.pop_back();
    }
    cout << endl;
    return count;
}

int main() { TimeMeasure _; __x();
    cout << rec(4) << endl; // 8
    cout << rec(3) << endl; // 5
}

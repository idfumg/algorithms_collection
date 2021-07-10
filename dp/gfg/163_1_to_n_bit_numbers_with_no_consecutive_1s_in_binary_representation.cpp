#include "../../template.hpp"

bool NoConsecutiveOnes(int n) {
    int prev = n & 1;
    for (n >>= 1; n > 0; n >>= 1) {
        int curr = n & 1;
        if (curr == 1 and prev == 1) return false;
        prev = curr;
    }
    return true;
}

vi naive_elems(int n) {
    vi ans;
    for (int i = 0; i < (1 << n); ++i) {
        if (NoConsecutiveOnes(i)) {
            ans.push_back(i);
        }
    }
    return ans;
}

int rec(int n, int prev) {
    if (n == 0) return 1;
    if (prev == 0) return rec(n - 1, 0) + rec(n - 1, 1);
    return rec(n - 1, 0);
}

int rec(int n) {
    return rec(n - 1, 0) + rec(n - 1, 1);
}

int tab(int n) {
    vvi dp(n + 1, vi(2));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 1; ++j) {
            if (i == 0) dp[i][j] = 1;
            else if (j == 0) dp[i][j] = dp[i - 1][0] + dp[i - 1][1];
            else dp[i][j] = dp[i - 1][0];
        }
    }
    return dp[n - 1][0] + dp[n - 1][1];
}

void rec_elems(int n, int prev, int num, vi& elems) {
    if (n == 0) {
        elems.push_back(num);
    }
    else if (prev == 0) {
        rec_elems(n - 1, 0, num * 2, elems);
        rec_elems(n - 1, 1, num * 2 + 1, elems);
    }
    else {
        rec_elems(n - 1, 0, num * 2, elems);
    }
}

vi rec_elems(int n) {
    vi elems;
    rec_elems(n - 1, 0, 0, elems);
    rec_elems(n - 1, 1, 1, elems);
    return elems;
}

int main() { TimeMeasure _; __x();
    cout << rec(4) << endl; // 8
    cout << rec(3) << endl; // 5
    cout << endl;
    cout << tab(4) << endl; // 8
    cout << tab(3) << endl; // 5
    cout << endl;
    cout << naive_elems(4) << endl; // 0 1 2 4 5 8 9 10
    cout << naive_elems(3) << endl; // 0 1 2 4 5
    cout << endl;
    cout << rec_elems(4) << endl; // 0 1 2 4 5 8 9 10
    cout << rec_elems(3) << endl; // 0 1 2 4 5
}

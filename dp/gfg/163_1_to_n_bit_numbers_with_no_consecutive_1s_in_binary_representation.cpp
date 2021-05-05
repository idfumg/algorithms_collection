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

vi naive(int n) {
    vi ans;
    for (int i = 0; i < (1 << n); ++i) {
        if (NoConsecutiveOnes(i)) {
            ans.push_back(i);
        }
    }
    return ans;
}

int with1(int n);

int with0(int n) {
    if (n == 1) return 1;
    return with0(n - 1) + with1(n - 1);
}

int with1(int n) {
    if (n == 1) return 1;
    return with0(n - 1);
}

int rec_count(int n) {
    return with0(n) + with1(n);
}

int rec_count2(int n, int prev) {
    if (n == 0) return 1;
    if (prev == 0) return rec_count2(n - 1, 1) + rec_count2(n - 1, 0);
    return rec_count2(n - 1, 0);
}

int rec_count2(int n) {
    return rec_count2(n, 0);
}

int rec(int n, int prev, int num, vi& ans) {
    if (n == 0) {
        ans.push_back(num);
        return 1;
    }
    if (prev == 0) {
        return rec(n - 1, 1, (num << 1) + 1, ans) + rec(n - 1, 0, num << 1, ans);
    }
    return rec(n - 1, 0, num << 1, ans);
}

vi rec(int n) {
    vi ans;
    rec(n, 0, 0, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() { // TimeMeasure _; __x();
    cout << naive(4) << endl; // 0 1 2 4 5 8 9 10
    cout << naive(3) << endl; // 0 1 2 4 5

    cout << rec_count(4) << endl; // 8
    cout << rec_count(3) << endl; // 5

    cout << rec_count2(4) << endl; // 8
    cout << rec_count2(3) << endl; // 5

    cout << rec(4) << endl; // 0 1 2 4 5 8 9 10
    cout << rec(3) << endl; // 0 1 2 4 5
}

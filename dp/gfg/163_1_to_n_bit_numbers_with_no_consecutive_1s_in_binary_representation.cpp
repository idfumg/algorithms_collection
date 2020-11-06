#include "../../template.hpp"

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

bool IsNonConsequentOnes(int n) {
    int prev = 0, digits = static_cast<int>(log2(n));
    for (int i = 1 << 0; i <= (1 << digits); prev = i, i <<= 1) {
        if ((n & prev) and (n & i)) {
            return false;
        }
    }
    return true;
}

vi naive(int n) {
    vi res;
    for (int i = 0; i < (1 << n); ++i) {
        if (IsNonConsequentOnes(i)) {
            res.push_back(i);
        }
    }
    return res;
}

void rec(int n, vi& res, int prev, si& elems) {
    if (n == 0) {
        int num = 0;
        for (int i = size(res) - 1; i >= 0; --i) {
            if (res[i] == 1) {
                num += pow(2, size(res) - i - 1);
            }
        }
        elems.insert(num);
        return;
    }
    for (int i : {0, 1}) {
        if (prev == 1 and i == 1) continue;
        res[n - 1] = i;
        rec(n - 1, res, i, elems);
    }
}

si rec(int n) {
    vi res(n);
    si elems;
    for (int i : {0, 1}) {
        res[n - 1] = i;
        rec(n - 1, res, i, elems);
    }
    return elems;
}

void rec_elems(int init, int n, int prev, int result) {
    if (n == 0) {
        cout << result << ' ';
        return;
    }
    if (prev == 0) {
        rec_elems(init, n - 1, 0, result);
        rec_elems(init, n - 1, 1, result + (1 << (init - n)));
        return;
    }
    rec_elems(init, n - 1, 0, result);
}

void rec_elems(int n) {
    return rec_elems(n, n, 0, 0);
}

int main() { TimeMeasure _; __x();
    cout << rec_count(4) << endl; // 8
    cout << rec_count(3) << endl; // 5

    cout << naive(4) << endl; // 0 1 2 4 5 8 9 10
    cout << naive(3) << endl; // 0 1 2 4 5

    cout << rec(4) << endl; // 0 1 2 4 5 8 9 10
    cout << rec(3) << endl; // 0 1 2 4 5

    rec_elems(4); cout << endl; // 0 1 2 4 5 8 9 10
    rec_elems(3); cout << endl; // 0 1 2 4 5
}

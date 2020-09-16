#include "../template.hpp"

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

void rec2(int total, int n, int prev, int num) {
    if (n == 0) {
        cout << num << ' ';
        return;
    }
    for (int i : {0, 1}) {
        if (i == 1 and prev == 1) continue;
        rec2(total, n - 1, i, num + (i << (total - n)));
    }
}

void rec2(int n) {
    rec2(n, n, 0, 0);
}

int main() { TimeMeasure _; __x();
    cout << rec(4) << endl;
    cout << rec(3) << endl;

    rec2(4); cout << endl;
    rec2(3); cout << endl;
}

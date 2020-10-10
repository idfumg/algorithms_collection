#include "../template.hpp"

void LossMinimization(vi& L, vi& T) {
    int n = L.size();
    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    stable_sort(idx.begin(), idx.end(),
                [&](int i, int j) {
                    return L[i] * T[j] > L[j] * T[i];
                });
    for (int i = 0; i < n; ++i) {
        cout << idx[i] + 1 << ' ';
    }
    cout << '\n';
}

int main() { TimeMeasure _;
    {
        vi L = { 3, 1, 2, 4 };
        vi T = { 4, 1000, 2, 5 };
        LossMinimization(L, T);
    }
    {
        vi L = { 1, 2, 3, 5, 6 };
        vi T = { 2, 4, 1, 3, 2 };
        LossMinimization(L, T);
    }
}

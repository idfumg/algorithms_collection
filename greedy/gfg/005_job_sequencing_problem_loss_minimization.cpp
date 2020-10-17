#include "../../template.hpp"

void LossMinimization(vi L, vi T) {
    int n = T.size();
    vi idxes(n);
    iota(idxes.begin(), idxes.end(), 0);
    const auto Predicate =
        [&](int i, int j){
            int time1 = T[i];
            int time2 = T[j];
            int loss1 = L[i];
            int loss2 = L[j];
            return loss1 * time2 > loss2 * time1;
        };
    stable_sort(idxes.begin(), idxes.end(), Predicate);
    for (int i = 0; i < n; ++i) {
        cout << idxes[i] + 1 << ' ';
    }
    cout << '\n';
}

int main() { TimeMeasure _; __x();
    {
        vi L = { 3, 1, 2, 4 };
        vi T = { 4, 1000, 2, 5 };
        LossMinimization(L, T); // 3 4 1 2
    }
    {
        vi L = { 1, 2, 3, 5, 6 };
        vi T = { 2, 4, 1, 3, 2 };
        LossMinimization(L, T); // 3 5 4 1 2
    }
}

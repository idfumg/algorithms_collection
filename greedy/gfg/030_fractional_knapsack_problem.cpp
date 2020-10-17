#include "../../template.hpp"

double FractionalKnapsack(vi value, vi weight, int total) {
    int n = value.size();
    double ans = 0;
    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
         [&](int a, int b){
             return value[a] / (double)weight[a] > (double)value[b] / weight[b];
         });
    for (int i = 0; i < n; ++i) {
        int j = idx[i];
        int currentWeight = weight[j] >= total ? total : weight[j];
        double currentCost = value[j] / weight[j] * currentWeight;
        total -= currentWeight;
        ans += currentCost;
    }
    return ans;
}

int main() { TimeMeasure _;
    vi value = {60,100,120};
    vi weight = {10,20,30};
    cout << FractionalKnapsack(value, weight, 50) << '\n'; // 240
}

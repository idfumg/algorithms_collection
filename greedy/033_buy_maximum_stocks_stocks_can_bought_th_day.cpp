#include "../template.hpp"

int BuyMaxStocks(vi price, int total) {
    int n = price.size(), ans = 0;
    vi idx(n);
    iota(idx.begin(), idx.end(), 1);
    sort(idx.begin(), idx.end(),
         [&](int i, int j){
             if (price[i - 1] == price[j - 1]) return i < j;
             return price[i - 1] < price[j - 1];
         });
    for (int i = 0; i < n and total > 0; ++i) {
        int count = min(total / price[idx[i] - 1], idx[i]);
        total -= price[idx[i] - 1] * count;
        ans += count;
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << BuyMaxStocks({10,7,19}, 45) << '\n'; // 4
    cout << BuyMaxStocks({7,10,4}, 100) << '\n'; // 6
}

#include "../../template.hpp"

pi MinAndMaxAmountToBuyAllCandies(vi candies, int k) {
    sort(candies);
    int n = candies.size(), mini = 0, maxi = 0;
    for(int i = 0, j = n - 1; i <= j; i += 1, j -= k) {
        mini += candies[i];
    }
    for(int i = 0, j = n - 1; i <= j; i += k, j -= 1) {
        maxi += candies[j];
    }
    return {mini, maxi};
}

int main() { TimeMeasure _;
    cout << MinAndMaxAmountToBuyAllCandies({3,2,1,4}, 2) << '\n'; // 3 7
}

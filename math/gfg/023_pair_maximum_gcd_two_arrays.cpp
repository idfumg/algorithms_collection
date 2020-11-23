#include "../../template.hpp"

pi brute(vi arr1, vi arr2) {
    int m = arr1.size();
    int n = arr2.size();
    int g = 0;
    int sum = 0;
    pi ans;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int currentGcd = gcd(arr1[i], arr2[j]);
            int currentSum = arr1[i] + arr2[j];
            if (currentGcd > g or (currentGcd == g and currentSum > sum)) {
                g = currentGcd;
                sum = currentSum;
                ans = {i, j};
            }
        }
    }

    return {arr1[ans.first], arr2[ans.second]};
}

pi PairWithMaxGcd(vi arr1, vi arr2) {
    return {};
}

int main() { TimeMeasure _; __x();
    cout << brute({3, 1, 4, 2, 8}, {5, 2, 12, 8, 3}) << endl; // 8,8
    cout << brute({2, 3, 5}, {7, 11, 13}) << endl; // 5,13
    cout << endl;
    cout << PairWithMaxGcd({3, 1, 4, 2, 8}, {5, 2, 12, 8, 3}) << endl;
    cout << PairWithMaxGcd({2, 3, 5}, {7, 11, 13}) << endl;
}

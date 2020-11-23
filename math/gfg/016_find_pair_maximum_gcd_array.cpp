#include "../../template.hpp"

int brute(vi arr) {
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int g = gcd(arr[i], arr[j]);
            ans = max(ans, g);
        }
    }
    return ans;
}

int FindAPairWithMaxGcd(vi arr) {
    int n = arr.size();
    return 0;
}

int main() { TimeMeasure _; __x();
    cout << brute({1, 2, 3, 4, 5}) << endl; // 2 // {2, 4}
    cout << brute({2, 3, 4, 8, 8, 11, 12}) << endl; // 8 // {8, 8}
    cout << endl;
    cout << FindAPairWithMaxGcd({1, 2, 3, 4, 5}) << endl; // 2 // {2, 4}
    cout << FindAPairWithMaxGcd({2, 3, 4, 8, 8, 11, 12}) << endl; // 8 // {8, 8}
}

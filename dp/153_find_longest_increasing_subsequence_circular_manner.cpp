#include "../template.hpp"

int tab1(vi arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        arr.push_back(arr[i]);
    }
    n *= 2;
    vi dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return max(dp);
}

int tab2(vi& arr) {
    int n = arr.size();
    vi dp(n * 2, 1);
    for (int i = 1; i < n * 2; ++i) {
        for (int j = 0; j < i; ++j) {
            int ifake = i % n;
            int jfake = j % n;
            if (arr[ifake] > arr[jfake]) {
                dp[ifake] = max(dp[ifake], dp[jfake] + 1);
            }
        }
    }
    return max(dp);
}

int main() { TimeMeasure _; __x();
    vi arr1 = {5, 4, 3, 2, 1}; // 2
    vi arr2 = {5, 6, 7, 1, 2, 3}; // 6
    vi arr3 = {1, 4, 6, 2, 3}; // 5
    cout << tab1(arr1) << endl;
    cout << tab1(arr2) << endl;
    cout << tab1(arr3) << endl;
    cout << '\n';
    cout << tab2(arr1) << endl;
    cout << tab2(arr2) << endl;
    cout << tab2(arr3) << endl;
}

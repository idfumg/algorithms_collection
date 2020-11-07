//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

void AllDistancesFitK(vi& arr, int k) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] - arr[i] > k) {
                cout << ":(" << '\n';
                return;
            }
        }
    }
    cout << "Yay!" << '\n';
}

int main() {
    const int n = 5;
    vi arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    AllDistancesFitK(arr, k);
}

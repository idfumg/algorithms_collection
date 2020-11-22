#include "../../template.hpp"

void FindTriplets(vi arr) {
    int n = arr.size();
    int total = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum + arr[i] == total) {
                cout << arr[i] << ' ' << arr[left] << ' ' << arr[right] << endl;
                break;
            }
            if (sum + arr[i] < total) ++left;
            else --right;
        }
    }
    cout << endl;
}

int main() { TimeMeasure _;
    FindTriplets({0, -1, 2, -3, 1});
    FindTriplets({1, -2, 1, 0, 5});
}

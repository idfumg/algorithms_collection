#include "../../template.hpp"

void FindClosestPair(vi arr, int key) {
    int n = arr.size();
    int i = 0;
    int j = n - 1;
    int maxi = 0;
    int elem1 = 0;
    int elem2 = 0;

    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum <= key) {
            if (maxi < sum) {
                maxi = sum;
                elem1 = i;
                elem2 = j;
            }
            ++i;
        }
        else {
            --j;
        }
    }

    cout << arr[elem1] << ' ' << arr[elem2] << '\n';
}

int main() { TimeMeasure _;
    FindClosestPair({10, 22, 28, 29, 30, 40}, 54); // 22 30
    FindClosestPair({1, 3, 4, 7, 10}, 15); // 4 10
}

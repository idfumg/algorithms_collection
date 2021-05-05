#include "../../template.hpp"

int MaximizeArraySum(vi arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int i = 0;
    while (arr[i] < 0 and k-- > 0) {
        arr[i++] *= -1;
    }

    if (arr[i] != 0 and k & 1) {
        arr[i] *= -1;
    }

    return accumulate(arr.begin(), arr.end(), 0);
}

int MaximizeArraySum2(vi arr, int k) {
    int n = arr.size();
    int posCount = 0;
    int posSum = 0;
    int posMin = INF;
    int zeroCount = 0;
    int negSum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0 and k > 0) {
            arr[i] *= -1;
            --k;
            ++posCount;
            posSum += arr[i];
            posMin = min(posMin, arr[i]);
        }
        else if (arr[i] < 0) {
            negSum += arr[i];
        }
        else if (arr[i] == 0) {
            ++zeroCount;
        }
        else {
            ++posCount;
            posSum += arr[i];
            posMin = min(posMin, arr[i]);
        }
    }
    if (k > 0 and zeroCount > 0) {
        k = 0;
    }
    if (k > 0 and posCount > 0) {
        if (k & 1) {
            posSum -= 2 * posMin;
            k = 0;
        }
    }

    return negSum + posSum;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {-2, 0, 5, -1, 2}; // 10
    vi arr2 = {9, 8, 8, 5}; // 20
    cout << MaximizeArraySum(arr1, 4) << '\n';
    cout << MaximizeArraySum(arr2, 3) << '\n';
    cout << endl;
    cout << MaximizeArraySum2(arr1, 4) << '\n';
    cout << MaximizeArraySum2(arr2, 3) << '\n';
}

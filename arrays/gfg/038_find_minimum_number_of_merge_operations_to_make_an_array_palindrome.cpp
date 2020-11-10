#include "../../template.hpp"

int MergeToAPalindrome(vi arr) {
    int n = arr.size();
    int count = 0;
    for (int i = 0, j = n - 1; i <= j;) {
        if (arr[i] == arr[j]) {
            ++i;
            --j;
        }
        else if (arr[i] < arr[j]) {
            arr[i + 1] = arr[i] + arr[i + 1];
            ++i;
            ++count;
        }
        else {
            arr[j - 1] = arr[j - 1] + arr[j];
            --j;
            ++count;
        }
    }
    return count;
}

int main() { TimeMeasure _;
    cout << MergeToAPalindrome({15, 4, 15}) << '\n'; // 0
    cout << MergeToAPalindrome({1, 4, 5, 1}) << '\n'; // 1
    cout << MergeToAPalindrome({11, 14, 15, 99}) << '\n'; // 3
}

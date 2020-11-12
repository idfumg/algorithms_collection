#include "../../template.hpp"

void Sort012(vi arr) {
    int n = arr.size();
    int left = 0;
    int mid = 0;
    int right = n - 1;
    while (mid <= right) {
        if (arr[mid] == 0) swap(arr[left++], arr[mid++]);
        else if (arr[mid] == 2) swap(arr[mid], arr[right--]);
        else if (arr[mid] == 1) ++mid;
    }
    cout << arr << '\n';
}

int main() { TimeMeasure _;
    Sort012({0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1});
    Sort012({0, 1, 2, 0, 1, 2});
}

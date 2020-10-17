#include "../../template.hpp"

int SumOfRectanglesAreas(vi arr) {
    int n = arr.size(), ans = 0;
    sort(arr);
    for (int i = 0, j = n - 1; i + 1 < j - 1;) {
        int a = arr[i];
        int b = arr[i + 1];
        int c = arr[j];
        int d = arr[j - 1];
        if (a != b and max(a, b) - 1 != min(a, b)) {
            ++i;
            continue;
        }
        if (c != d and max(c, d) - 1 != min(c, d)) {
            --j;
            continue;
        }
        ans += min(a, b) * min(c, d);
        i += 2;
        j -= 2;
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << SumOfRectanglesAreas({10,10,10,10,11,10,11,10}) << '\n'; // 210
    cout << SumOfRectanglesAreas({3,4,5,6}) << '\n'; // 15
    cout << SumOfRectanglesAreas({3,2,5,2}) << '\n'; // 0
}

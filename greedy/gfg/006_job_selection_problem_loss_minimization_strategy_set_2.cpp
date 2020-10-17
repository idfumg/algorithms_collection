#include "../../template.hpp"

void LossMinimization(vi arr, double loss) {
    int n = arr.size();
    double total = 0;
    sort(arr);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
        total += pow(1 - loss, n - i - 1) * arr[i];
    }
    cout << ':' << ' ' << total << '\n';
}

int main() { TimeMeasure _;
    {
        vi arr{ 3, 5, 4, 1, 2, 7, 6, 8, 9, 10 };
        LossMinimization(arr, 0.10); // 1 2 3 4 5 6 7 8 9 10 : 41.3811
    }
    {
        vi arr{4, 2, 151, 15, 1, 52, 12}; // 1 2 4 12 15 52 151 : 223.035
        LossMinimization(arr, 0.10);
    }
    {
        vi arr{3, 1, 41, 52, 15, 4, 1, 63, 12}; // 1 1 3 4 12 15 41 52 63 : 145.91и
        LossMinimization(arr, 0.20);
    }
}

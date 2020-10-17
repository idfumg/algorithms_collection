#include "../../template.hpp"

int MinCostToConnect(vi& arr) {
    int mini = INF, sum = 0;
    for (int value : arr) {
        mini = min(mini, value);
        sum += value;
    }
    return mini * (sum - mini);
}

int main() { TimeMeasure _;
    vi arr1 = {6, 2, 1, 5};
    vi arr2 = {5, 10};
    vi arr3 = {4, 3, 2, 5};
    cout << MinCostToConnect(arr1) << endl;
    cout << MinCostToConnect(arr2) << endl;
    cout << MinCostToConnect(arr3) << endl;
}

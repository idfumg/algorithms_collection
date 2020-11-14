#include "../../template.hpp"

void LeadersInTheArray(vi arr) {
    int n = arr.size();
    int maxi = -INF;
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] > maxi) {
            cout << arr[i] << ' ';
            maxi = arr[i];
        }
    }
}

int main() { TimeMeasure _;
    LeadersInTheArray({16, 17, 4, 3, 5, 2});
}

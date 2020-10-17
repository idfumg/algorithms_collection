#include "../../template.hpp"

int ConnectRopesWithMinCost(vi arr) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (const int item : arr) {
        pq.push(item);
    }
    int ans = 0;
    while (not pq.empty()) {
        int item1 = pq.top(); pq.pop();
        int item2 = pq.top(); pq.pop();
        ans += item1 + item2;
        if (not pq.empty()) {
            pq.push(item1 + item2);
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << ConnectRopesWithMinCost({4,3,2,6}) << '\n';
}

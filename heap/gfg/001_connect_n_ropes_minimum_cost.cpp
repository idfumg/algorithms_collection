#include "../../template.hpp"

void ConnectRopes(vi arr) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int value : arr) {
        pq.push(value);
    }
    int total = 0;
    while (pq.size() >= 2) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a + b);
        total += a + b;
    }
    cout << total << endl;
}

int main() { TimeMeasure _;
    ConnectRopes({4, 3, 2, 6});
}

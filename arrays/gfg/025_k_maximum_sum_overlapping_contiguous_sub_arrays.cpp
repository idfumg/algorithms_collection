#include "../../template.hpp"

void GetKMaxSums(vi arr, int k) {
    int n = arr.size();
    vi presum(n + 1);
    for (int i = 1; i <= n; ++i) {
        presum[i] = arr[i - 1] + presum[i - 1];
    }
    vi sums;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            sums.push_back(presum[j] - presum[i - 1]);
        }
    }
    sort(sums.rbegin(), sums.rend());
    for (int i = 0; i < k; ++i) {
        cout << sums[i] << ' ';
    }
    cout << endl;
}

void GetKMaxSums2(vi arr, int k) {
    int n = arr.size();
    vi presum(n + 1);
    for (int i = 1; i <= n; ++i) {
        presum[i] += arr[i - 1] + presum[i - 1];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int sum = presum[j] - presum[i - 1];
            if (pq.size() < k) {
                pq.push(sum);
            }
            else {
                if (pq.top() < sum) {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    while (not pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << endl;
}

int main() { TimeMeasure _;
    vi arr1 = {4, -8, 9, -4, 1, -8, -1, 6}; int k1 = 4;
    vi arr2 = {-2, -3, 4, -1, -2, 1, 5, -3}; int k2 = 3;

    GetKMaxSums(arr1, k1);
    GetKMaxSums(arr2, k2);
    cout << endl;
    GetKMaxSums2(arr1, k1);
    GetKMaxSums2(arr2, k2);
}

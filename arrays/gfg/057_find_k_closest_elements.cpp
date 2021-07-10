#include "../../template.hpp"

vi KClosestElemensNLogn1(const vi arr, const int k, const int x) {
    const int n = arr.size();
    multiset<pair<int, int>> pq;
    for (int i = 0; i < n; ++i) {
        pq.insert({abs(arr[i] - x), arr[i]});
        if (pq.size() > k) {
            const auto it = pq.find(*pq.rbegin());
            pq.erase(it);
        }
    }
    vector<int> res;
    transform(pq.begin(), pq.end(), back_inserter(res), [](const pi& p){return p.second;});
    sort(res.begin(), res.end());
    return res;
}

vi KClosestElemensNLogn(const vi arr, const int k, const int x) {
    const int n = arr.size();
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push({abs(arr[i] - x), arr[i]});
        if (pq.size() > k) {
            pq.pop();
        }
    }
    vector<int> res;
    res.reserve(k);
    while (not pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    sort(res.begin(), res.end());
    return res;
}

vi KClosestElemensLogn(const vi arr, const int k, const int x) {
    const int n = arr.size();
    const auto found = lower_bound(arr.begin(), arr.end(), x);
    if (found == arr.end()) return vector<int>(arr.begin() + n - k, arr.end());

    int idx = distance(arr.begin(), found);
    if (idx < k - 1) idx = k - 1;
    while (idx + 1 < n and idx - k + 1 >= 0 and abs(arr[idx - k + 1] - x) >= abs(arr[idx + 1] - x)) ++idx;
    while (idx >= k and abs(arr[idx - k] - x) < abs(arr[idx] - x)) --idx;
    while (idx >= k and abs(arr[idx - k] - x) == abs(arr[idx] - x) and arr[idx - k] < arr[idx]) --idx;

    return vector<int>(arr.begin() + idx - k + 1, arr.begin() + idx + 1);
}

int main() { TimeMeasure _;
    cout << KClosestElemensNLogn1({1,1,1,10,10,10}, 1, 9) << endl; // 10
    cout << KClosestElemensNLogn1({1,2,3,4,5}, 4, -1) << endl; // 1 2 3 4
    cout << KClosestElemensNLogn1({1,2,3,4,5}, 4, 3) << endl; // 1 2 3 4
    cout << KClosestElemensNLogn1({0,0,1,2,3,3,4,7,7,8}, 3, 5) << endl; // 3 3 4
    cout << KClosestElemensNLogn1({1,2,5,5,6,6,7,7,8,9}, 7, 7) << endl; // 5 5 6 6 7 7 8
    cout << KClosestElemensNLogn1({0,0,0,1,3,5,6,7,8,8}, 2, 2) << endl; // 1 3
    cout << KClosestElemensNLogn1({3,5,8,10}, 2, 15) << endl; // 8 10
    cout << KClosestElemensNLogn1({0,1,1,2,3,6,7,8,10,10,10,13,14,14,14,15,17,17,18,19,19,20,22,23,25,26,26,29,30,32,32,33,34,34,35,35,37,37,38,39,42,42,43,43,46,47,49,50,51,52,52,53,53,54,55,56,56,57,57,59,59,60,60,60,60,60,62,65,65,65,70,74,75,76,76,76,77,77,77,79,79,81,82,83,84,85,85,88,88,91,92,94,94,95,96,96,96,97,97,99}, 72, 47) << endl; // 13 14 14 14 15 17 17 18 19 19 20 22 23 25 26 26 29 30 32 32 33 34 34 35 35 37 37 38 39 42 42 43 43 46 47 49 50 51 52 52 53 53 54 55 56 56 57 57 59 59 60 60 60 60 60 62 65 65 65 70 74 75 76 76 76 77 77 77 79 79 81 82
    cout << endl;
    cout << KClosestElemensNLogn({1,1,1,10,10,10}, 1, 9) << endl; // 10
    cout << KClosestElemensNLogn({1,2,3,4,5}, 4, -1) << endl; // 1 2 3 4
    cout << KClosestElemensNLogn({1,2,3,4,5}, 4, 3) << endl; // 1 2 3 4
    cout << KClosestElemensNLogn({0,0,1,2,3,3,4,7,7,8}, 3, 5) << endl; // 3 3 4
    cout << KClosestElemensNLogn({1,2,5,5,6,6,7,7,8,9}, 7, 7) << endl; // 5 5 6 6 7 7 8
    cout << KClosestElemensNLogn({0,0,0,1,3,5,6,7,8,8}, 2, 2) << endl; // 1 3
    cout << KClosestElemensNLogn({3,5,8,10}, 2, 15) << endl; // 8 10
    cout << KClosestElemensNLogn({0,1,1,2,3,6,7,8,10,10,10,13,14,14,14,15,17,17,18,19,19,20,22,23,25,26,26,29,30,32,32,33,34,34,35,35,37,37,38,39,42,42,43,43,46,47,49,50,51,52,52,53,53,54,55,56,56,57,57,59,59,60,60,60,60,60,62,65,65,65,70,74,75,76,76,76,77,77,77,79,79,81,82,83,84,85,85,88,88,91,92,94,94,95,96,96,96,97,97,99}, 72, 47) << endl; // 13 14 14 14 15 17 17 18 19 19 20 22 23 25 26 26 29 30 32 32 33 34 34 35 35 37 37 38 39 42 42 43 43 46 47 49 50 51 52 52 53 53 54 55 56 56 57 57 59 59 60 60 60 60 60 62 65 65 65 70 74 75 76 76 76 77 77 77 79 79 81 82
    cout << endl;
    cout << KClosestElemensLogn({1,1,1,10,10,10}, 1, 9) << endl; // 10
    cout << KClosestElemensLogn({1,2,3,4,5}, 4, -1) << endl; // 1 2 3 4
    cout << KClosestElemensLogn({1,2,3,4,5}, 4, 3) << endl; // 1 2 3 4
    cout << KClosestElemensLogn({0,0,1,2,3,3,4,7,7,8}, 3, 5) << endl; // 3 3 4
    cout << KClosestElemensLogn({1,2,5,5,6,6,7,7,8,9}, 7, 7) << endl; // 5 5 6 6 7 7 8
    cout << KClosestElemensLogn({0,0,0,1,3,5,6,7,8,8}, 2, 2) << endl; // 1 3
    cout << KClosestElemensLogn({3,5,8,10}, 2, 15) << endl; // 8 10
    cout << KClosestElemensLogn({0,1,1,2,3,6,7,8,10,10,10,13,14,14,14,15,17,17,18,19,19,20,22,23,25,26,26,29,30,32,32,33,34,34,35,35,37,37,38,39,42,42,43,43,46,47,49,50,51,52,52,53,53,54,55,56,56,57,57,59,59,60,60,60,60,60,62,65,65,65,70,74,75,76,76,76,77,77,77,79,79,81,82,83,84,85,85,88,88,91,92,94,94,95,96,96,96,97,97,99}, 72, 47) << endl; // 13 14 14 14 15 17 17 18 19 19 20 22 23 25 26 26 29 30 32 32 33 34 34 35 35 37 37 38 39 42 42 43 43 46 47 49 50 51 52 52 53 53 54 55 56 56 57 57 59 59 60 60 60 60 60 62 65 65 65 70 74 75 76 76 76 77 77 77 79 79 81 82

}

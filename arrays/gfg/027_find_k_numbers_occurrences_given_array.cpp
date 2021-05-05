#include "../../template.hpp"

void KNumsWithMostOccurences(vi arr, int k) {
    unordered_map<int, int> tab;
    for (const auto value : arr) {
        ++tab[value];
    }
    priority_queue<pair<int, int>> pq;
    for (const auto& [key, value] : tab) {
        pq.push({value, key});
    }
    for (int i = 0; i < k and not pq.empty(); ++i) {
        cout << pq.top().second << ' ';
        pq.pop();
    }
    cout << endl;
}

void KNumsWithMostOccurences2(vi arr, int k) {
    unordered_map<int, int> tab;
    for (const auto& value : arr) {
        ++tab[value];
    }
    vi ans;
    for (const auto& [elem, count] : tab) {
        if (ans.size() < static_cast<size_t>(k)) {
            ans.push_back(elem);
            continue;
        }
        int mini = 0;
        for (int j = 0; j < k; ++j) {
            if (tab[ans[mini]] > tab[ans[j]] or (tab[ans[mini]] == tab[ans[j]] and ans[mini] > ans[j])) {
                mini = j;
            }
        }
        if (count > tab[ans[mini]] or (count == tab[ans[mini]] and elem > ans[mini])) {
            ans[mini] = elem;
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

void KNumsWithMostOccurences3(vi arr, size_t k) {
    unordered_map<int, int> tab;
    for (const auto& value : arr) {
        ++tab[value];
    }
    const auto comp = [&](int a, int b){ return tab[a] > tab[b]; };
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    for (const auto& [elem, count] : tab) {
        if (pq.size() < k) {
            pq.push(elem);
        }
        else if (tab[pq.top()] < count or (tab[pq.top()] == count and pq.top() < elem)) {
            pq.pop();
            pq.push(elem);
        }
    }
    while (not pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << endl;
}

void KNumsWithMostOccurences4(vi arr, int k) {
    int n = arr.size();
    unordered_map<int, int> map;
    for (int v : arr) {
        ++map[v];
    }
    vector<pair<int, int>> nums(map.begin(), map.end());
    sort(nums.begin(), nums.end(), [](pi a, pi b){
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    });
    for (int i = 0; i < k; ++i) {
        cout << nums[i].first << ' ';
    }
    cout << endl;
}


int main() { TimeMeasure _;
    KNumsWithMostOccurences({3, 1, 4, 4, 5, 2, 6, 1}, 2); // O(nlogn), Om(n)
    KNumsWithMostOccurences({7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9}, 4);
    cout << endl;
    KNumsWithMostOccurences2({3, 1, 4, 4, 5, 2, 6, 1}, 2); // O(nk), Om(k)
    KNumsWithMostOccurences2({7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9}, 4);
    cout << endl;
    KNumsWithMostOccurences3({3, 1, 4, 4, 5, 2, 6, 1}, 2); // O(n + klogk), Om(k)
    KNumsWithMostOccurences3({7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9}, 4);
    cout << endl;
    KNumsWithMostOccurences4({3, 1, 4, 4, 5, 2, 6, 1}, 2); // O(n + klogk), Om(k) // 4 1
    KNumsWithMostOccurences4({7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9}, 4); // 5 11 7 10
}

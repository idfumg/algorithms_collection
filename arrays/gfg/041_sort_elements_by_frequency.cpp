#include "../../template.hpp"

void SortByFrequency(vi arr) {
    int n = arr.size();
    unordered_map<int, int> freq;
    unordered_map<int, int> pos;
    for (int i = 0; i < n; ++i) {
        if (not pos.count(arr[i])) {
            pos[arr[i]] = i;
        }
        ++freq[arr[i]];
    }
    sort(arr.begin(), arr.end(),
         [&](int b, int a){
             if (freq[b] == freq[a]) {
                 return pos[b] < pos[a];
             }
             return freq[b] > freq[a];
         });
    cout << arr << '\n';
}

int main() { TimeMeasure _;
    SortByFrequency({2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8});
}

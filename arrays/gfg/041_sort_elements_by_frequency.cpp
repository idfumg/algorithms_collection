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

void SortByFrequency2(vi arr) {
    int n = arr.size();
    unordered_map<int, int> tab;
    for (int value : arr) {
        ++tab[value];
    }
    vi idxs(n, 0);
    iota(idxs.begin(), idxs.end(), 0);
    sort(idxs.begin(), idxs.end(),
         [&](int i, int j) {
             int a = arr[i];
             int b = arr[j];
             if (tab[a] == tab[b]) {
                 return i < j;
             }
             return tab[a] > tab[b];
         });
    for (int i = 0; i < n; ++i) {
        int idx = idxs[i];
        cout << arr[idx] << ' ';
    }
    cout << endl;
}

int main() { TimeMeasure _;
    SortByFrequency({2, 5, 2, 8, 5, 6, 8, 8}); // 8, 8, 8, 2, 2, 5, 5, 6
    SortByFrequency({2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8}); // 8, 8, 8, 2, 2, 5, 5, 6, -1, 9999999
    cout << endl;
    SortByFrequency2({2, 5, 2, 8, 5, 6, 8, 8}); // 8, 8, 8, 2, 2, 5, 5, 6
    SortByFrequency2({2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8}); // 8, 8, 8, 2, 2, 5, 5, 6, -1, 9999999
}

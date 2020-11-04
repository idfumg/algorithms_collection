#include "../../template.hpp"

void KNumsWithMostOccurences(vi arr, int k) {
    int n = arr.size();
    unordered_map<int, int> tab;
    for (int value : arr) {
        ++tab[value];
    }

    sort(arr.begin(), arr.end(),
         [&](int a, int b) {
             if (tab[a] == tab[b]) {
                 return a < b;
             }
             return tab[a] < tab[b];
         });

    unordered_set<int> ans;
    for (int i = n - 2; i >= 0; --i) {
        ans.insert(arr[i]);
        if (ans.size() == k) {
            break;
        }
    }
    cout << ans << '\n';
}

int main() { TimeMeasure _;
    KNumsWithMostOccurences({3, 1, 4, 4, 5, 2, 6, 1}, 2);
    KNumsWithMostOccurences({7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9}, 4);
}

#include "../../template.hpp"

int PoliceThief(vector<char> arr, int k) {
    vi police, thieves;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 'P') police.push_back(i);
        else if (arr[i] == 'T') thieves.push_back(i);
    }
    int i = 0, j = 0, m = police.size(), ans = 0;
    n = thieves.size();
    while (i < m and j < n) {
        if (abs(police[i] - thieves[j]) <= k) ++i, ++j, ++ans;
        else if (police[i] < thieves[j]) ++j;
        else ++i;
    }
    return ans;
}

int main() { TimeMeasure _;
    vector<char> arr1 = { 'P', 'T', 'T', 'P', 'T' }; // 2
    int k1 = 2;
    cout << "Maximum thieves caught: " << PoliceThief(arr1, k1) << endl;

    vector<char> arr2 = { 'T', 'T', 'P', 'P', 'T', 'P' }; // 3
    int k2 = 2;
    cout << "Maximum thieves caught: " << PoliceThief(arr2, k2) << endl;

    vector<char> arr3 = { 'P', 'T', 'P', 'T', 'T', 'P' }; // 3
    int k3 = 3;
    cout << "Maximum thieves caught: " << PoliceThief(arr3, 3) << endl;
}

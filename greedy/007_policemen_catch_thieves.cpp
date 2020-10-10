#include "../template.hpp"

int PoliceThief(vector<char>& arr, int k) {
    int n = arr.size();
    vector<char> officers, thieves;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 'P') {
            officers.push_back(i);
        }
        else {
            thieves.push_back(i);
        }
    }
    int i = 0, j = 0, res = 0;
    while (i < officers.size() and j < thieves.size()) {
        if (abs(officers[i] - thieves[j]) <= k) {
            ++i;
            ++j;
            ++res;
        }
        else if (officers[i] < thieves[j]) {
            ++i;
        }
        else {
            ++j;
        }
    }
    return res;
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

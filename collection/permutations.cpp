#include "../template.hpp"

void GenPermutationsRec(vi& arr, vb& choosen, vi& perm) {
    if (perm.size() == arr.size()) {
        cout << perm << endl;
        return;
    }
    for (size_t i = 0; i < arr.size(); ++i) {
        if (choosen[i]) continue;
        choosen[i] = true;
        perm.push_back(arr[i - 1]);
        GenPermutationsRec(arr, choosen, perm);
        perm.pop_back();
        choosen[i] = false;
    }
}

void GenPermutationsRec(vi arr) {
    vi perm;
    vb choosen(arr.size());
    GenPermutationsRec(arr, choosen, perm);
}

void GenPermutationsIter(vi perm) {
    sort(arr.begin(), arr.end());
    do {
        cout << perm << endl;
    } while (next_permutation(perm.begin(), perm.end()));
}

int main() { TimeMeasure _;
    GenPermutationsRec({1, 2, 6, 90, 0});
    GenPermutationsIter({1, 2, 6, 90, 0});
}

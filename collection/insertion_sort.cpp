#include "../template.hpp"

vi InsertionSort(vi arr) {
    for (std::size_t i = 1; i < arr.size(); ++i) {
        for (std::size_t j = i; j > 0 and arr[j] < arr[j - 1]; --j) {
            swap(arr[j], arr[j - 1]);
        }
    }
    return arr;
}

vi BinaryInsertionSort(vi arr) {
    for (std::size_t i = 1; i < arr.size(); ++i) {
        const auto insertionPoint = std::upper_bound(arr.begin() + 0, arr.begin() + i, arr[i]);
        std::rotate(insertionPoint, arr.begin() + i, arr.begin() + i + 1);
    }
    return arr;
}

int main() { TimeMeasure _;
    cout << InsertionSort({1, 20, 6, 4, 5}) << '\n';
    cout << BinaryInsertionSort({1, 20, 6, 4, 5}) << '\n';
}

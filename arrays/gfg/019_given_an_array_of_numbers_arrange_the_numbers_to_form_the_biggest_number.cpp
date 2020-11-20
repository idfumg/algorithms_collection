#include "../../template.hpp"

bool pred(int a, int b) {
    const string x = to_string(a);
    const string y = to_string(b);
    return stoi(x + y) > stoi(y + x);
}

void FormABigestNumber(vi arr) {
    sort(arr.begin(), arr.end(), pred);
    debugn(arr);
}

int main() { TimeMeasure _;
    vi arr1 = {54, 546, 548, 60};
    vi arr2 = {1, 34, 3, 98, 9, 76, 45, 4};

    FormABigestNumber(arr1); // 6054854654
    FormABigestNumber(arr2); // 998764543431
}

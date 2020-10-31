#include "../../template.hpp"

bool pred(const string& b, const string& a) {
    const string x = b + a;
    const string y = a + b;
    return x < y;
}

void FormABigestNumber(vi arr_) {
    int n = arr_.size();
    vector<string> arr(n);
    transform(arr_.begin(), arr_.end(), arr.begin(), [&](int a) {return to_string(a);});
    sort(arr.rbegin(), arr.rend(), pred);
    for_each(arr.begin(), arr.end(), [](const auto& s){cout << s;});
    cout << '\n';
}

int main() { TimeMeasure _;
    vi arr1 = {54, 546, 548, 60};
    vi arr2 = {1, 34, 3, 98, 9, 76, 45, 4};

    FormABigestNumber(arr1);
    FormABigestNumber(arr2);
}

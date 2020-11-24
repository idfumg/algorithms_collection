#include "../../template.hpp"

string LongMultiplication(const string& a, const string& b) {
    int m = a.size();
    int n = b.size();

    vi result(m + n);
    for (int i = m - 1, ai = 0; i >= 0; --i, ++ai) {
        int carry = 0;
        int bi = 0;
        for (int j = n - 1; j >= 0; --j, ++bi) {
            int sum = (a[i] - '0') * (b[j] - '0') + carry + result[ai + bi];
            carry = sum / 10;
            result[ai + bi] = sum % 10;
        }
        if (carry > 0) {
            result[ai + bi] += carry;
        }
    }

    int i = m + n - 1;
    for (; i >= 0 and result[i] == 0; --i) {
    }

    string s;
    for (; i >= 0; --i) {
        s += result[i] + '0';
    }

    if (s.empty()) {
        return "0";
    }
    return s;
}

int main() { TimeMeasure _;
    // 2118187521397235888154583183918321221520083884298838480662480
    cout << LongMultiplication("1235421415454545454545454544",
                               "1714546546546545454544548544544545") << endl;

    cout << LongMultiplication("1", "0") << endl; // 0
    cout << LongMultiplication("0", "1") << endl; // 0
    cout << LongMultiplication("2", "5") << endl; // 10
    cout << LongMultiplication("4154", "51454") << endl; // 213739916
}

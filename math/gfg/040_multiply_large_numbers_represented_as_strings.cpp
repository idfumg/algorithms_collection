#include "../../template.hpp"

string LongMultiplication(const string& a, const string& b) {
    int m = a.size();
    int n = b.size();
    string result(m + n, '0');

    for (int i = m - 1, ai = 0; i >= 0; --i, ++ai) {
        int carry = 0;
        for (int j = n - 1, bi = 0; j >= 0; --j, ++bi) {
            int sum = (a[i] - '0') * (b[j] - '0') + carry + (result[ai + bi] - '0');
            carry = sum / 10;
            result[ai + bi] = (sum % 10) + '0';
        }
        if (carry > 0) {
            result[ai + n] += carry;
        }
    }

    int i = m + n - 1;
    for (; i >= 0 and result[i] == '0'; --i) {
    }

    result.resize(i + 1);

    if (result.empty()) {
        return "0";
    }

    reverse(result.begin(), result.end());
    return result;
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

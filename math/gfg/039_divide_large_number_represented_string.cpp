#include "../../template.hpp"

string LongDivision(const string& number, int divisor) {
    int temp = 0;
    int idx = 0;
    int n = number.size();
    while (temp < divisor and idx < n) {
        temp = temp * 10 + number[idx++] - '0';
    }
    string ans;
    for (; idx < n; ++idx) {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[idx] - '0';
    }
    ans += (temp / divisor) + '0';
    if (ans.empty()) {
        return "0";
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << LongDivision("1260257", 37) << endl; // 34061
    cout << LongDivision("12313413534672234", 754) << endl; // 16330787181262
    cout << LongDivision("1248163264128256512", 125) << endl; // 9985306113026052
}

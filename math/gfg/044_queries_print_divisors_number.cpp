#include "../../template.hpp"

vvi FindDivisors(int total) {
    vvi ans(total + 1);
    for (int i = 1; i <= total; ++i) {
        for (int j = i; j <= total; j += i) {
            ans[j].push_back(i);
        }
    }
    return ans;
}

void PrintAllDivisors(vi nums) {
    int total = *max_element(nums.begin(), nums.end());
    vvi divisors = FindDivisors(total);
    for (int num : nums) {
        cout << divisors[num] << endl;
    }
}

int main() { TimeMeasure _;
    PrintAllDivisors({6, 10});
}

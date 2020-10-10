#include "../template.hpp"

int MaxSumOfThreeStacks(vi stack1, vi stack2, vi stack3) {
    int sum1 = accumulate(stack1.begin(), stack1.end(), 0);
    int sum2 = accumulate(stack2.begin(), stack2.end(), 0);
    int sum3 = accumulate(stack3.begin(), stack3.end(), 0);
    int m = stack1.size(), n = stack2.size(), p = stack3.size();
    int i = 0, j = 0, k = 0;
    while (i < m and j < n and k < p) {
        if (sum1 == sum2 and sum2 == sum3) return sum1;
        if (sum1 > sum2 and sum1 > sum3) sum1 -= stack1[i++];
        if (sum2 > sum1 and sum2 > sum3) sum2 -= stack2[j++];
        if (sum3 > sum1 and sum3 > sum2) sum3 -= stack3[k++];
    }
    return 0;
}

int main() { TimeMeasure _;
    cout << MaxSumOfThreeStacks({3,2,1,1,1}, {4,3,2}, {1,1,4,1}) << '\n'; // 5
    cout << MaxSumOfThreeStacks({3,10}, {4,5}, {2,1}) << '\n'; // 0
}

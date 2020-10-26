#include "../../template.hpp"

int rec(int eggs, int floors) {
    if (eggs == 1) {
        return floors;
    }
    if (floors <= 1) {
        return floors;
    }
    int count = INF;
    for (int floor = 1; floor <= floors; ++floor) {
        count = min(count, max(rec(eggs - 1, floor - 1), rec(eggs, floors - floor)) + 1);
    }
    return count;
}

int tab(int eggs, int floors) {
    vvi dp(eggs + 1, vi(floors + 1));
    for (int i = 1; i <= eggs; ++i) {
        for (int j = 1; j <= floors; ++j) {
            if (i == 1) {
                dp[i][j] = j;
            }
            else if (j <= 1) {
                dp[i][j] = j;
            }
            else {
                int count = INF;
                for (int floor = 1; floor <= j; ++floor) {
                    count = min(count, max(dp[i - 1][floor - 1], dp[i][j - floor]) + 1);
                }
                dp[i][j] = count;
            }
        }
    }
    return dp[eggs][floors];
}

int main() { TimeMeasure _; __x();
    // n - number of eggs, k - number of floors
    // find minimum number of trials in the worst case to find the critical floor on which an egg will broke
    cout << rec(2, 10) << endl; // 4
    cout << tab(2, 10) << endl; // 4
    cout << tab(2, 36) << endl; // 8
}

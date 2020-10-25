#include "../../template.hpp"

int rec1(vi wines, int L, int R, int year, int profit) {
    if (L > R) {
        return profit;
    }
    return max(rec1(wines, L + 1, R, year + 1, profit + wines[L - 1] * year),
               rec1(wines, L, R - 1, year + 1, profit + wines[R - 1] * year));
}

int rec1(vi wines) {
    return rec1(wines, 1, wines.size(), 1, 0);
}

int rec2(vi wines, int L, int R, int year) {
    if (L > R) {
        return 0;
    }
    return max(rec2(wines, L + 1, R, year + 1) + year * wines[L - 1],
               rec2(wines, L, R - 1, year + 1) + year * wines[R - 1]);
}

int rec2(vi wines) {
    return rec2(wines, 1, wines.size(), 1);
}

int rec3(vi wines, int L, int R) {
    if (L > R) {
        return 0;
    }
    int n = wines.size();
    int year = n - (R - L);
    return max(rec3(wines, L + 1, R) + year * wines[L - 1],
               rec3(wines, L, R - 1) + year * wines[R - 1]);
}

int rec3(vi wines) {
    return rec3(wines, 1, wines.size());
}

int tab1(vi wines) {
    int n = wines.size();
    vi temp = wines;
    sort(temp);
    int maxprofit = 0;
    for (int i = 1; i <= n; ++i) {
        maxprofit = maxprofit + temp[i - 1] * i;
    }
    vvvvi dp(n + 2, vvvi(n + 2, vvi (n + 3, vi(maxprofit + 2))));
    for (int L = n; L >= 1; --L) {
        for (int R = 1; R <= n; ++R) {
            for (int year = n + 1; year >= 1; --year) {
                for (int profit = maxprofit; profit >= 0; --profit) {
                    if (L > R) {
                        dp[L][R][year][profit] = profit;
                    }
                    else {
                        const auto cost1 = profit + wines[L - 1] * year;
                        const auto cost2 = profit + wines[R - 1] * year;
                        if (cost1 <= maxprofit) {
                            dp[L][R][year][profit] = max(dp[L][R][year][profit],
                                                         dp[L + 1][R][year + 1][cost1]);
                        }
                        if (cost2 <= maxprofit) {
                            dp[L][R][year][profit] = max(dp[L][R][year][profit],
                                                         dp[L][R - 1][year + 1][cost2]);
                        }
                    }
                }
            }
        }
    }
    return dp[1][n][1][0];
}

int tab2(vi wines) {
    int n = wines.size();
    vvvi dp(n + 2, vvi(n + 2, vi(n + 3)));
    for (int L = n; L >= 1; --L) {
        for (int R = 1; R <= n; ++R) {
            for (int year = n + 1; year >= 1; --year) {
                if (L > R) {
                    dp[L][R][year] = 0;
                }
                else {
                    const auto cost1 = dp[L + 1][R][year + 1] + wines[L - 1] * year;
                    const auto cost2 = dp[L][R - 1][year + 1] + wines[R - 1] * year;
                    dp[L][R][year] = max(cost1, cost2);
                }
            }
        }
    }
    return dp[1][n][1];
}

int tab3(vi wines) {
    int n = wines.size();
    vvi dp(n + 2, vi(n + 2));
    for (int L = n; L >= 1; --L) {
        for (int R = 1; R <= n; ++R) {
            if (L > R) {
                dp[L][R] = 0;
            }
            else {
                const auto year = n - (R - L);
                const auto cost1 = dp[L + 1][R] + wines[L - 1] * year;
                const auto cost2 = dp[L][R - 1] + wines[R - 1] * year;
                dp[L][R] = max(cost1, cost2);
            }
        }
    }
    return dp[1][n];
}

int tab_elems(vi wines) {
    int n = wines.size();
    vvi dp(n + 2, vi(n + 2));
    vvvi prev(n + 2, vvi(n + 2));
    for (int L = n; L >= 1; --L) {
        for (int R = 1; R <= n; ++R) {
            if (L > R) {
                dp[L][R] = 0;
            }
            else {
                const auto year = n - (R - L);
                const auto cost1 = dp[L + 1][R] + wines[L - 1] * year;
                const auto cost2 = dp[L][R - 1] + wines[R - 1] * year;
                if (cost1 > cost2) {
                    dp[L][R] = cost1;
                    prev[L][R] = {L + 1, R, L - 1};
                }
                else {
                    dp[L][R] = cost2;
                    prev[L][R] = {L, R - 1, R - 1};
                }
            }
        }
    }
    deque<int> elems;
    for (vi at = prev[1][n]; not at.empty(); at = prev[at[0]][at[1]]) {
        elems.push_back(wines[at[2]]);
    }
    debugn(elems);
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    vi wines = {2, 4, 6, 2, 5}; // 64
    cout << rec1(wines) << endl;
    cout << rec2(wines) << endl;
    cout << rec3(wines) << endl;
    cout << tab1(wines) << endl;
    cout << tab2(wines) << endl;
    cout << tab3(wines) << endl;
    cout << tab_elems(wines) << endl; // 2 5 2 4 6
}

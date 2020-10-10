#include "../template.hpp"

void rec(int w, int m, int n, int small, int large, int& ressmall, int& reslarge, int& reslen) {
    if (w < 0) {
        return;
    }

    if (w == reslen and reslarge < large) {
        ressmall = small;
        reslarge = large;
    }
    else if (w < reslen) {
        ressmall = small;
        reslarge = large;
        reslen = w;
    }

    rec(w - n, m, n, small, large + 1, ressmall, reslarge, reslen);
    rec(w - m, m, n, small + 1, large, ressmall, reslarge, reslen);
}

void rec(int w, int m, int n) {
    int small = 0, large = 0, len = INF;
    rec(w, m, n, 0, 0, small, large, len);
    cout << small << ' ' << large << ' ' << len << '\n';
}

void tab(int w, int m, int n) {
    vi arr = {m, n};
    vvi dp(w + 1, vi(3));
    int maxsum = -INF, maxm = 0, maxn = -INF;
    vvvi values(w + 1, vvi(3, {0, 0}));
    for (int j = 0; j <= 2; ++j) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= w; ++i) {
        for (int j = 1; j <= 2; ++j) {
            if (i >= arr[j - 1]) {
                if (dp[i - arr[j - 1]][j - 1] and dp[i - arr[j - 1]][j]) {
                    if (values[i - arr[j - 1]][j - 1][1] > values[i - arr[j - 1]][j][1]) {
                        values[i][j] = values[i - arr[j - 1]][j - 1];
                    }
                    else {
                        values[i][j] = values[i - arr[j - 1]][j];
                    }
                    dp[i][j] = true;
                    values[i][j][(arr[j - 1] == m) ? 0 : 1]++;
                }
                else if (dp[i - arr[j - 1]][j - 1]) {
                    dp[i][j] = true;
                    values[i][j] = values[i - arr[j - 1]][j - 1];
                    values[i][j][(arr[j - 1] == m) ? 0 : 1]++;
                }
                else if (dp[i - arr[j - 1]][j]) {
                    dp[i][j] = true;
                    values[i][j] = values[i - arr[j - 1]][j];
                    values[i][j][(arr[j - 1] == m) ? 0 : 1]++;
                }
            }
            if (not dp[i][j] and dp[i][j - 1]) {
                dp[i][j] = true;
                values[i][j] = values[i][j - 1];
            }
            if (dp[i][j]) {
                if (maxsum < i)  {
                    maxsum = i;
                    maxm = values[i][j][0];
                    maxn = values[i][j][1];
                }
                else if (maxsum == i and maxn < values[i][j][1]) {
                    maxm = values[i][j][0];
                    maxn = values[i][j][1];
                }
            }
        }
    }
    cout << maxm << ' ' << maxn << ' ' << w - maxsum << '\n';
}

void FitShelves(int w, int m, int n) {
    int small = 0, large = 0, space = INF;
    int maxLarge = w / n;
    for (int currentLarge = maxLarge; currentLarge >= 0; --currentLarge) {
        int currentSmall = (w - currentLarge * n) / m;
        int currentSpace = w - currentSmall * m - currentLarge * n;
        if (currentSpace == space and currentLarge > large) {
            large = currentLarge;
            small = currentSmall;
        }
        else if (currentSpace < space) {
            space = currentSpace;
            large = currentLarge;
            small = currentSmall;
        }
    }
    cout << small << ' ' << large << ' ' << space << '\n';
}

int main() { TimeMeasure _;
    rec(24, 3, 5); // 3 3 0
    rec(29, 3, 9); // 0 3 2
    rec(24, 4, 7); // 6 0 0
    rec(28, 4, 7); // 0 4 0
    rec(7, 3, 5); // 0 1 2
    cout << '\n';
    tab(24, 3, 5); // 3 3 0
    tab(29, 3, 9); // 0 3 2
    tab(24, 4, 7); // 6 0 0
    tab(28, 4, 7); // 0 4 0
    tab(7, 3, 5); // 0 1 2
    cout << '\n';
    FitShelves(24, 3, 5); // 3 3 0
    FitShelves(29, 3, 9); // 0 3 2
    FitShelves(24, 4, 7); // 6 0 0
    FitShelves(28, 4, 7); // 0 4 0
    FitShelves(7, 3, 5); // 0 1 2
}

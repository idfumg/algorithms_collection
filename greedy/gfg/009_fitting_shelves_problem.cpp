#include "../../template.hpp"

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

void tab2(int w, int m, int n) {
    int smalln = w / m, largen = w / n;
    int anssmall = 0, anslarge = -INF, answ = INF;
    for (int j = smalln; j >= 0; --j) {
        for (int k = largen; k >= 0; --k) {
            int occupied = j * m + k * n;
            int space = w - occupied;
            if (space >= 0) {
                if (space < answ or (space == answ and anslarge < k)) {
                    answ = space;
                    anssmall = j;
                    anslarge = k;
                }
            }
        }
    }
    cout << anssmall << ' ' << anslarge << ' ' << answ << '\n';
}

void FitShelves(int W, int M, int N) {
    int w = W, m = 0, n = 0;
    for (int bigCount = 0; bigCount <= W / N; ++bigCount) {
        int smallSpace = W - bigCount * N;
        int smallCount = smallSpace / M;
        int space = smallSpace - smallCount * M;
        if (space < w) {
            w = space;
            m = smallCount;
            n = bigCount;
        }
        else if (space == w and bigCount > n) {
            m = smallCount;
            n = bigCount;
        }
    }
    cout << m << ' ' << n << ' ' << w << endl;
}

int main() { TimeMeasure _;
    rec(24, 3, 5); // 3 3 0
    rec(29, 3, 9); // 0 3 2
    rec(24, 4, 7); // 6 0 0
    rec(28, 4, 7); // 0 4 0
    rec(7, 3, 5); // 2 0 1
    cout << '\n';
    tab(24, 3, 5); // 3 3 0
    tab(29, 3, 9); // 0 3 2
    tab(24, 4, 7); // 6 0 0
    tab(28, 4, 7); // 0 4 0
    tab(7, 3, 5); // 2 0 1
    cout << '\n';
    tab2(24, 3, 5); // 3 3 0
    tab2(29, 3, 9); // 0 3 2
    tab2(24, 4, 7); // 6 0 0
    tab2(28, 4, 7); // 0 4 0
    tab2(7, 3, 5); // 2 0 1
    cout << '\n';
    FitShelves(24, 3, 5); // 3 3 0
    FitShelves(29, 3, 9); // 0 3 2
    FitShelves(24, 4, 7); // 6 0 0
    FitShelves(28, 4, 7); // 0 4 0
    FitShelves(7, 3, 5); // 2 0 1
}

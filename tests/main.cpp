//#include "template.hpp"

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MOD static_cast<int64_t>(1e18 + 7)
#define PI (3.1415926535897932384626433832795)
#define INF static_cast<int32_t>(1e9)
#define LLINF static_cast<int64_t>(1e18)
//#define EPS static_cast<int32_t>(1e-9)

using ld = long double;
using ll = int64_t;
using ull = uint64_t;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using vvpi = vector<vpi>;
using vvvpi = vector<vvpi>;
using vvvvpi = vector<vvvpi>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vvvvi = vector<vvvi>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using si = set<int>;
using sll = set<ll>;

int rec(string& a, string& b, int m, int n, int k) {
    if (m == 0 and n != 0) return 0;
    if (k < 0) return 0;
    if (m < n) return 0;
    if (n == 0) return 1;
    if (m == 0) return 0;
    if (m == 1) return 0;

    if (a[m - 1] == b[n - 1]) {
        return rec(a, b, m - 1, n - 1, k) + rec(a, b, m - 1, n, k);
    }
    return rec(a, b, m - 1, n - 1, k - 1) + rec(a, b, m - 1, n, k);
}

int rec(string& a, string& b, int k) {
    return rec(a, b, a.size(), b.size(), k);
}

int tab(string& a, string& b, int K) {
    int m = a.size(), n = b.size();
    vvvi dp(m + 1, vvi(n + 1, vi(K + 1)));
    for (int k = 0; k <= K; ++k) {
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {

                if (i == 0 and j != 0) {
                    dp[i][j][k] = 0;
                }
                else if (j == 0) {
                    dp[i][j][k] = 1;
                }
                else if (i == 0 and j == 0) {
                    dp[i][j][k] = 1;
                }
                else if (k == 0) {
                    dp[i][j][k] = 0;
                }
                else if (a[i - 1] == b[j - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k];
                }
                else {
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - 1];
                }
            }
        }
    }
    return dp[m][n][K];
}

[[maybe_unused]] static const auto __x = [](){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(20); cout.setf(ios::boolalpha);};

int main() { //TimeMeasure _;
    //int T; cin >> T;
    //for (int t = 0; t < T; ++t) {
        int n; cin >> n;
        int k; cin >> k;
        string a; cin >> a;
        string b; cin >> b;
        cout << rec(a, b, k) << endl;
        cout << tab(a, b, k) << endl;
        //}

    return 0;
}

// 220000000000000
// 217871987498122

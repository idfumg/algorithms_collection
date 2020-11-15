// #include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INF static_cast<int32_t>(1e9)

using ll = int64_t;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;

[[maybe_unused]] static const auto ___x = [](){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::boolalpha);};

int main() {
    int n; cin >> n;
    int w; cin >> w;
    vvi incoming(n, vi(2));
    vvi outcoming(n, vi(2));
    for (int i = 0; i < n; ++i) {
        int startTime; cin >> startTime;
        int stopTime; cin >> stopTime;
        int cost; cin >> cost;
        incoming[i] = {startTime, cost};
        outcoming[i] = {stopTime, cost};
    }
    sort(incoming.begin(), incoming.end(), [](vi& a, vi& b){return a[0] < b[0];});
    sort(outcoming.begin(), outcoming.end(), [](vi& a, vi& b){return a[0] < b[0];});

    int i = 0;
    int j = 0;
    int total = 0;

    while (i < n and j < n) {
        if (outcoming[j][0] <= incoming[i][0]) {
            total -= outcoming[j][1];
            ++j;
        }
        else if (incoming[i][0] < outcoming[j][0]) {
            total += incoming[i][1];
            ++i;
        }
        if (total > w) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}

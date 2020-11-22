//#include "../../template.hpp"

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

ll UpperBound(vll& arr, ll key) {
    ll n = arr.size();
    ll low = 0;
    ll high = n - 1;
    while (low != high) {
        ll mid = low + (high - low) / 2;
        if (arr[mid] <= key) low = mid + 1;
        else high = mid;
    }
    return high;
}

int Closest(vll& arr, const ll total) {
    ll n = arr.size();
    ll m = n / 2;
    n = n - m;

    // debugn(m);
    // debugn(n);

    vll sums1;
    vll sums2;

    for (ll i = 0; i < (1 << m); ++i) {
        ll sum = 0;
        for (ll j = 0; j < m; ++j) {
            if (i & (1 << j)) {
                sum += arr[j];
            }
        }
        if (sum == total) {
            return total;
        }
        if (sum < total) {
            sums1.push_back(sum);
        }
    }

    for (ll i = 0; i < (1 << n); ++i) {
        ll sum = 0;
        for (ll j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += arr[j + m];
            }
        }
        if (sum == total) {
            return total;
        }
        if (sum < total) {
            sums2.push_back(sum);
        }
    }

    sort(sums2.begin(), sums2.end());

    // debugn(sums1);
    // debugn(sums2);

    ll ans = 0;
    n = sums2.size();

    for (ll sum : sums1) {
        ll key = total - sum;
        ll idx = UpperBound(sums2, key);
        //debug(sum); debug(key); debugn(sums2[idx]);
        if (idx == 0) {
            ans = max(ans, sum);
        }
        else {
            if (sums2[idx] + sum <= total) {
                ans = max({ans, sum, sums2[idx] + sum});
            }
            if (sums2[idx - 1] + sum <= total) {
                ans = max({ans, sum, sums2[idx - 1] + sum});
            }
        }
    }

    return ans;
}

int main() { ___x();
    ll n, total;
    cin >> n >> total;

    vll arr(n);
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << Closest(arr, total) << endl;
}

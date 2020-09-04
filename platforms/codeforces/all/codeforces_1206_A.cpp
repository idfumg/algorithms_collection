#include <iostream>
#include <cassert>
#include <limits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <array>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cstring>
#include <bitset>
#include <stack>
#include <queue>

#define MOD (1e9 + 7);
#define PI (3.14159265358979323846)

using ll = int64_t;
using ull = uint64_t;

using namespace std;

[[maybe_unused]] static auto __x = [](){ios_base::sync_with_stdio(0); cin.tie(0);};

int main() {
    ll res = 0;
    ll below_zero = 0;
    ll below_zero_sum = 0;
    ll above_zero = 0;
    ll above_zero_sum = 0;
    ll zeroes = 0;

    ll n; cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll a; cin >> a;
        if (a < 0) {
            below_zero_sum += a;
            below_zero += 1;
        }
        else if (a == 0) {
            zeroes += 1;
        }
        else {
            if (a > 1) {
                above_zero_sum += a;
                above_zero += 1;
            }
        }
    }

    if (below_zero > 0) {
        res = -below_zero_sum - 1 - (below_zero > 1 ? below_zero - 1 : 0);
    }

    if (below_zero > 0 && below_zero % 2 != 0 && zeroes > 0) {
        res += 1;
        zeroes -= 1;
        below_zero -= 1;
    }

    res += zeroes;

    if (below_zero > 0 && below_zero % 2 != 0) {
        res += 2;
    }

    if (above_zero > 0) {
        res += above_zero_sum - 1 - (above_zero > 1 ? above_zero - 1 : 0);
    }

    cout << res;
}

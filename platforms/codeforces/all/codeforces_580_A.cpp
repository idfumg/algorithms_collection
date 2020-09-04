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
    int n; cin >> n;
    ll prev = 0;
    ll res = 0;
    ll count = 0;
    for (int i = 0; i < n; ++i) {
        ll a; cin >> a;
        if (i == 0) {
            ++count;
        }
        else {
            if (prev <= a) {
                ++count;
            }
            else {
                res = max({res, count});
                count = 1;
            }
        }
        prev = a;
    }
    res = max({res, count});
    cout << res;
}

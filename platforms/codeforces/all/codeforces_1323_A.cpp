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
    int tests_total; cin >> tests_total;
    for (int test_count = 0; test_count < tests_total; ++test_count) {
        int n; cin >> n;
        bool i_need_odd = false;
        int prev_odd_idx = -1;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            int number; cin >> number;
            if (ok) {
                continue;
            }
            if (number % 2 != 0) {
                if (i_need_odd) {
                    cout << 2 << '\n';
                    cout << prev_odd_idx << ' ' << i + 1 << '\n';
                    ok = true;
                }
                else {
                    i_need_odd = true;
                    prev_odd_idx = i + 1;
                }
            }
            else {
                cout << 1 << '\n';
                cout << i + 1 << '\n';
                ok = true;
            }
        }
        if (not ok) {
            cout << -1 << '\n';
        }
        ok = false;
        i_need_odd = false;
        prev_odd_idx = -1;
    }
}

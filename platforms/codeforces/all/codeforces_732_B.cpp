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
    int k; cin >> k;
    int prev, curr, diff, total = 0;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (i != 0 && prev + curr < k) {
            diff = k - prev - curr;
            curr += diff;
            total += diff;
        }
        prev = curr;
        arr.push_back(prev);
    }
    cout << total << '\n';
    for (int elem : arr) cout << elem << ' ';
}

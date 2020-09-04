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

int where_jump(int start, int stop, int n, const string& s) {
    if (start >= stop) {
        return -1;
    }
    else if (stop > n) {
        return where_jump(start, n, n, s);
    }
    else if (s[stop] == '1') {
        return stop;
    }
    else {
        return where_jump(start, stop - 1, n, s);
    }
}

int go(int i, int jumps, int d, int n, const string& s) {
    if (i == n) {
        return jumps;
    }
    else if (i == -1) {
        return -1;
    }
    else {
        return go(where_jump(i, i + d, n, s), jumps + 1, d, n, s);
    }
}

int main() {
    int n; cin >> n;
    int d; cin >> d;
    string s; cin >> s;

    cout << go(0, 0, d, n - 1, s);
}

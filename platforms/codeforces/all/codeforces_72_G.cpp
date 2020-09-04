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

[[maybe_unused]] static const auto __x = [](){ios_base::sync_with_stdio(0); cin.tie(0);};

int fib(const int n) noexcept {
    int a = 1, b = 1, c;
    while (n-- >= 1) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int n; cin >> n;
    cout << fib(n);
}

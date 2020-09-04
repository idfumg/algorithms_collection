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
    vector<int> res;
    int i = 0, sum = 0;
    while (true) {
        int newvalue = i + 1;
        if (n - sum >= newvalue) {
            res.push_back(newvalue);
            sum += newvalue;
        }
        else {
            res.back() += n - sum;
            break;
        }
        ++i;
    }
    cout << res.size() << '\n';
    for (int elem : res) cout << elem << ' ';
}

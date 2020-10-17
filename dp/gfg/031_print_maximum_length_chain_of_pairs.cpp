#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MOD (1e9 + 7)
#define PI (3.1415926535897932384626433832795)
#define INF (1e9)
#define LLINF (1e18)
#define EPS (1e-9)

using ld = long double;
using ll = int64_t;
using ull = uint64_t;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvvll = vector<vector<vector<ll>>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using si = set<int>;
using sll = set<ll>;

template<class T, class U>
static ostream& operator << (ostream& os, const pair<T, U>& value) noexcept {
    return os << '{' << value.first << ',' << value.second << '}';
}

template<class T>
static ostream& operator << (ostream& os, const vector<pair<T, T>>& v) noexcept {
    for (const auto& value : v) os << '{' << value.first << ',' << value.second << '}' << ' ';
    return os << endl;
}

template<class T>
static ostream& operator << (ostream& os, const vector<T>& v) noexcept {
    for (const auto& value : v) os << value << ' ';
    return os << endl;
}

template<class T>
static ostream& operator << (ostream& os, const vector<vector<T>>& v) noexcept {
    os << '\n';
    for (const auto& L : v) os << L;
    return os << endl;
}

template<class T>
static ostream& operator << (ostream& os, const set<T>& s) noexcept {
    for (const auto& value : s) os << value << ' ';
    return os << endl;
}

template<class T>
static ostream& operator << (ostream& os, const unordered_set<T>& s) noexcept {
    for (const auto& value : s) os << value << ' ';
    return os << endl;
}

template<class T, class U>
static ostream& operator << (ostream& os, const map<T, U>& tab) noexcept {
    os << '\n';
    for (const auto& [key, value] : tab) os << key << ": " << value << '\n';
    return os << endl;
}

template<class T, class U>
static ostream& operator << (ostream& os, const unordered_map<T, U>& tab) noexcept {
    os << '\n';
    for (const auto& [key, value] : tab) os << key << ": " << value << '\n';
    return os << endl;
}

template<class T>
static istream& operator >> (istream& is, set<T>& s) noexcept {
    while (is) {
        T value; is >> value;
        s.insert(value);
    }
    return is;
}

template<class T>
static istream& operator >> (istream& is, vector<T>& v) noexcept {
    for (size_t i = 0; i < v.size(); ++i) is >> v[i];
    return is;
}

template<class T>
static istream& operator >> (istream& is, vector<vector<int>>& vv) noexcept {
    for (size_t i = 0; i < vv.size(); ++i) is >> vv[i];
    return is;
}

template<class T, class U>
static istream& operator >> (istream& is, unordered_map<T, U>& tab) noexcept {
    while (is) {
        T key; U value; is >> key >> value;
        tab[key] = value;
    }
    return is;
}

template<class T, class U>
static istream& operator >> (istream& is, map<T, U>& tab) noexcept {
    while (is) {
        T key; U value; is >> key >> value;
        tab[key] = value;
    }
    return is;
}

#define debug(VarName) cerr << "'" << #VarName << "': " << boolalpha << (VarName) << '\n';

class TimeMeasure final {
    time_t start;

public:
    TimeMeasure() noexcept {
        start = clock();
    }
    ~TimeMeasure() noexcept {
        cerr << "\nExecution time: " << ms() << " ms.\n";
    }
    ld ms() const noexcept {
        const auto stop = clock();
        const auto elapsed = static_cast<ld>(stop) - start;
        const auto ns = elapsed / CLOCKS_PER_SEC;
        const auto ms = ns * static_cast<ld>(1000.0);
        return ms;
    }
    friend ostream& operator<<(ostream& os, const TimeMeasure& tm) {
        return os << "\nElapsed time: " << tm.ms() << " ms.\n";
    }
};

ll power(ll a, ll p, const ll mod) noexcept {
    ll res = 1;
    while (p) {
        if (p & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        p /= 2;
    }
    return res % mod;
}

ll power(ll a, ll p) noexcept {
    ll res = 1;
    while (p) {
        if (p & 1) res *= a;
        a *= a;
        p /= 2;
    }
    return res;
}

[[maybe_unused]] static auto __x = [](){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::boolalpha);};

int condition(const pi& a, const pi& b) {
    return a.first > b.second;
}

pi count(vpi& arr, vi& dp, vi& index, int n, int i) {
    if (i < 0) return {0, -1};
    if (condition(arr[n], arr[i])) {
        const auto current = dp[i];
        const auto left = count(arr, dp, index, n, i - 1);
        if (current >= left.first) {
            index[n] = i;
            return {current, i};
        }
        else {
            index[n] = left.second;
            return left;
        }
    }
    return count(arr, dp, index, n, i - 1);
}

void rec(vpi& arr, vi& dp, vi& index, int n) {
    if (n < 1) return;
    rec(arr, dp, index, n - 1);
    dp[n] = count(arr, dp, index, n, n - 1).first + 1;
}

int rec(vpi arr) {
    sort(arr.begin(), arr.end());
    vi dp(arr.size(), 1);
    vi index(arr.size(), -1);
    rec(arr, dp, index, arr.size() - 1);
    int idx = max_element(dp.begin(), dp.end()) - dp.begin();
    int maxi = dp[idx];
    vpi path;
    for (; idx >= 0; idx = index[idx]) {
        path.push_back(arr[idx]);
    }
    reverse(path.begin(), path.end());
    cout << path;
    return maxi;
}

int tab(vpi arr) {
    const auto n = arr.size();
    sort(arr.begin(), arr.end());
    vi dp(n);
    vi index(n, -1);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (condition(arr[i], arr[j])) {
                if (dp[j] + 1 > dp[i]) {
                    index[i] = j;
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    int idx = max_element(dp.begin(), dp.end()) - dp.begin();
    int maxi = dp[idx];
    vpi path;
    for (; idx >= 0; idx = index[idx]) {
        path.push_back(arr[idx]);
    }
    reverse(path.begin(), path.end());
    cout << path;
    return maxi;
}

int main() { TimeMeasure _; __x();
    vpi arr1 = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    vpi arr2 = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
    vpi arr3 = {{6,8},{3,4}};

    cout << "Recursive: " << rec(arr1) << endl;
    cout << "Recursive: " << rec(arr2) << endl;
    cout << "Recursive: " << rec(arr3) << endl;
    cout << "Tabulation: " << tab(arr1) << endl;
    cout << "Tabulation: " << tab(arr2) << endl;
    cout << "Tabulation: " << tab(arr3) << endl;
}

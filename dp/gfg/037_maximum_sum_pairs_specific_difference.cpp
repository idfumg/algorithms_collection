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
using pi = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;
using vvpi = vector<vector<pi>>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vvvpi = vector<vector<vector<pi>>>;
using vvvi = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<ll>>>;
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

int rec(vi& arr, int k, int i) {
    if (i < 1) return 0;
    const auto a = rec(arr, k, i - 1);
    if (abs(arr[i] - arr[i - 1]) < k) {
        const auto b = rec(arr, k, i - 2) + arr[i] + arr[i - 1];
        return max(a, b);
    }
    return a;
}

int rec(vi arr, int k) {
    sort(arr.begin(), arr.end());
    return rec(arr, k, arr.size() - 1);
}

int tab(vi arr, int k) {
    const auto n = arr.size();
    sort(arr.begin(), arr.end());
    vi dp(n);
    for (int i = 1; i < n; ++i) {
        const auto a = dp[i - 1];
        if (abs(arr[i] - arr[i - 1]) < k) {
            const auto b = (i >= 2 ? dp[i - 2] : 0) + arr[i] + arr[i - 1];
            dp[i] = max(a, b);
        }
        else {
            dp[i] = a;
        }
    }
    return dp[n - 1];
}

int opt(vi arr, int k) {
    const auto n = arr.size();
    sort(arr.begin(), arr.end());
    vi dp(2);
    for (int i = 1; i < n; ++i) {
        const auto a = dp[1];
        if (abs(arr[i] - arr[i - 1]) < k) {
            const auto b = (i >= 2 ? dp[0] : 0) + arr[i] + arr[i - 1];
            dp[0] = dp[1];
            dp[1] = max(a, b);
        }
        else {
            dp[0] = dp[1];
            dp[1] = a;
        }
    }
    return dp[1];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {3, 5, 10, 15, 17, 12, 9};
    int k1 = 4;
    vi arr2 = {5, 15, 10, 300};
    int k2 = 12;

    cout << "Recursive: " << rec(arr1, k1) << endl;
    cout << "Recursive: " << rec(arr2, k2) << endl;
    cout << "Tabulation: " << tab(arr1, k1) << endl;
    cout << "Tabulation: " << tab(arr2, k2) << endl;
    cout << "Optimized: " << opt(arr1, k1) << endl;
    cout << "Optimized: " << opt(arr2, k2) << endl;
}

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

int rec(int n, int m) {
    if (n < m) return 1;
    if (n == m) return 2;
    return rec(n - 1, m) + rec(n - m, m);
}

int tab(int n, int m) {
    vi dp(n + 1);
    for (int i = 0; i <= n; ++i) {
        if (i < m) {
            dp[i] = 1;
        }
        else if (i == m) {
            dp[i] = 2;
        }
        else {
            dp[i] = dp[i - 1] + dp[i - m];
        }
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    cout << "Recursive: " << rec(2, 3) << endl;
    cout << "Recursive: " << rec(4, 4) << endl;
    cout << "Recursive: " << rec(7, 4) << endl;
    cout << "Tabulation: " << tab(2, 3) << endl;
    cout << "Tabulation: " << tab(4, 4) << endl;
    cout << "Tabulation: " << tab(7, 4) << endl;
}

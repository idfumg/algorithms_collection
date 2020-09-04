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
using vpi = vector<pair<int, int>>;
using vvpi = vector<vector<pair<int, int>>>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvvll = vector<vector<vector<ll>>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using si = set<int>;
using sll = set<ll>;

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

#define debug(VarName) cerr << "'" << #VarName << "': " << VarName << '\n';

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

[[maybe_unused]] static auto __x = [](){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15);};

int sum(const vi& v, const int n, const int i) {
    if (n == 0) return true;
    if (n < 0 or i < 0) return false;
    return sum(v, n - v[i], i - 1) or sum(v, n, i - 1);
}

int sum(const vi& v, const int n) {
    return sum(v, n, v.size() - 1);
}

int tab(const vi& v, const int n) {
    vvi dp(n + 1, vi(v.size() + 1));
    for (int i = 0; i <= v.size(); ++i) {
        dp[0][i] = true;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= v.size(); ++j) {
            if (i >= v[j - 1] and dp[i - v[j - 1]][j - 1] == 1) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[n][v.size()];
}

bool optimal(const vi& arr, int n) {
    vvb dp(2, vb(n + 1));
    for (int i = 0; i <= arr.size(); ++i) {
        for (int j = 0; j <= n; ++j) {
            int idx = i & 1;
            int previdx = 1 - idx;
            if (j == 0) {
                dp[idx][j] = true;
            }
            else {
                const auto a = dp[previdx][j];
                if (j >= arr[i - 1]) {
                    const auto b = dp[previdx][j - arr[i - 1]];
                    dp[idx][j] = a or b;
                }
                else {
                    dp[idx][j] = a;
                }
            }
        }
    }
    return dp[arr.size() & 1][n];
}

int main() { TimeMeasure _;
    const vi v = {3, 34, 4, 12, 5, 2};
    const int n = 9;
    cout << "Recursive: " << sum(v, n) << endl;
    cout << "Tabulation: " << tab(v, n) << endl;
    cout << "Optimal: " << optimal(v, n) << endl;

    {
        cout << endl;
        const vi v = {3, 34, 4, 12, 5, 2};
        const int n = 30;
        cout << "Recursive: " << sum(v, n) << endl;
        cout << "Tabulation: " << tab(v, n) << endl;
        cout << "Optimal: " << optimal(v, n) << endl;
    }
}

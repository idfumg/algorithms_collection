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

int rec(vvi& mat, int i, int j) {
    if (i < 0 or j < 0 or j >= mat[0].size() or j > i) return INT_MAX;
    const auto a = rec(mat, i - 1, j - 1);
    const auto b = rec(mat, i - 1, j);
    const auto c = rec(mat, i - 1, j + 1);
    const auto mini = min({a, b, c});
    if (mini != INT_MAX) {
        return mini + mat[i][j];
    }
    return mat[i][j];
}

int rec_(vvi&mat, int i, int j) {
    if (j < 0) return INT_MAX;
    return min(rec(mat, i, j), rec_(mat, i, j - 1));
}

int rec(vvi& mat) {
    const auto m = mat.size();
    const auto n = mat[0].size();
    return rec_(mat, m - 1, n - 1);
}

int choose(vvi& dp, int i, int j) {
    if (i < 0 or j < 0 or j >= dp[0].size() or i >= dp.size()) return INT_MAX;
    return dp[i][j];
}

int tab(vvi& mat) {
    const auto m = mat.size();
    const auto n = mat[0].size();
    vvi dp(m + 1, vi(n + 1, INT_MAX));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            const auto a = choose(dp, i - 1, j);
            const auto b = choose(dp, i - 1, j - 1);
            const auto c = choose(dp, i - 1, j + 1);
            const auto mini = min({a, b, c});
            if (mini != INT_MAX and mat[i][j] != INT_MAX) {
                dp[i][j] = mini + mat[i][j];
            }
            else {
                dp[i][j] = mat[i][j];
            }
        }
    }
    return *min_element(dp[m - 1].begin(), dp[m - 1].end());
}

int opt1(vvi& mat) {
    const auto m = mat.size();
    const auto n = mat[0].size();
    vvi dp(2, vi(n, INT_MAX));
    int idx;
    for (int i = 0; i < m; ++i) {
        idx = i & 1;
        for (int j = 0; j < i + 1; ++j) {
            const auto a = choose(dp, 1 - idx, j);
            const auto b = choose(dp, 1 - idx, j - 1);
            const auto c = choose(dp, 1 - idx, j + 1);
            const auto mini = min({a, b, c});
            if (mini != INT_MAX and mat[i][j] != INT_MAX) {
                dp[idx][j] = mini + mat[i][j];
            }
            else {
                dp[idx][j] = mat[i][j];
            }
        }
    }
    return *min_element(dp[idx].begin(), dp[idx].end());
}

int opt2(vvi& mat) {
    const auto m = mat.size();
    const auto n = mat[0].size();
    vvi dp(2, vi(n, INT_MAX));
    int idx = 0;
    for (int i = 0; i < m; ++i) {
        idx = i & 1;
        for (int j = 0; j < i + 1; ++j) {
            const auto a = choose(dp, 1 - idx, j - 1);
            const auto b = choose(dp, 1 - idx, j);
            const auto c = choose(dp, 1 - idx, j + 1);
            const auto mini = min({a, b, c});
            if (mini != INT_MAX) {
                dp[idx][j] = mini + mat[i][j];
            }
            else {
                dp[idx][j] = mat[i][j];
            }
        }
    }
    return *min_element(dp[idx].begin(), dp[idx].end());
}

int opt3(vvi& dp) {
    const auto m = dp.size();
    const auto n = dp[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            const auto a = choose(dp, i - 1, j);
            const auto b = choose(dp, i - 1, j - 1);
            const auto c = choose(dp, i - 1, j + 1);
            const auto mini = min({a, b, c});
            if (mini != INT_MAX) {
                dp[i][j] += mini;
            }
        }
    }
    return *min_element(dp[m - 1].begin(), dp[m - 1].end());
}

int main() { TimeMeasure _; __x();
    vvi mat1 = {{2, INT_MAX, INT_MAX},
                {3, 9, INT_MAX},
                {1, 6, 7}};
    vvi mat2 = {{2, INT_MAX, INT_MAX, INT_MAX},
                {3, 7, INT_MAX, INT_MAX},
                {8, 5, 6, INT_MAX},
                {6, 1, 9, 3}};
    vvi mat3 = {{3, INT_MAX, INT_MAX, INT_MAX},
                {6, 4, INT_MAX, INT_MAX},
                {5, 2, 7, INT_MAX},
                {9, 1, 8, 6}};
    cout << "Recursive: " << rec(mat1) << endl;
    cout << "Recursive: " << rec(mat2) << endl;
    cout << "Recursive: " << rec(mat3) << endl;
    cout << "Tabulation: " << tab(mat1) << endl;
    cout << "Tabulation: " << tab(mat2) << endl;
    cout << "Tabulation: " << tab(mat3) << endl;
    cout << "State Optimization1: " << opt1(mat1) << endl;
    cout << "State Optimization1: " << opt1(mat2) << endl;
    cout << "State Optimization1: " << opt1(mat3) << endl;
    cout << "State Optimization2: " << opt2(mat1) << endl;
    cout << "State Optimization2: " << opt2(mat2) << endl;
    cout << "State Optimization2: " << opt2(mat3) << endl;
    cout << "State Optimization3: " << opt3(mat1) << endl;
    cout << "State Optimization3: " << opt3(mat2) << endl;
    cout << "State Optimization3: " << opt3(mat3) << endl;
}

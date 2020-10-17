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

int rec(vvi& mat, vvpi& index, int i, int j) {
    if (i < 0 or j < 0) {
        return 0;
    }
    if (i == 0 and j == 0) {
        index[0][0] = {-1, -1};
        return mat[i][j];
    }
    if (i == 0) {
        index[i][j] = {i, j - 1};
        return rec(mat, index, i, j - 1) + mat[i][j];
    }
    if (j == 0) {
        index[i][j] = {i - 1, j};
        return rec(mat, index, i - 1, j) + mat[i][j];
    }
    const auto a = rec(mat, index, i - 1, j);
    const auto b = rec(mat, index, i, j - 1);
    if (a > b) {
        index[i][j] = {i - 1, j};
        return a + mat[i][j];
    }
    else {
        index[i][j] = {i, j - 1};
        return b + mat[i][j];
    }
}

int rec(vvi& mat) {
    const auto m = mat.size();
    const auto n = mat[0].size();
    vvpi index(m, vpi(n, {-1, -1}));
    const auto res = rec(mat, index, m - 1, n - 1);
    vi path;
    for (pi idx = {m - 1, n - 1}; idx.first >= 0 and idx.second >= 0;) {
        path.push_back(mat[idx.first][idx.second]);
        idx = index[idx.first][idx.second];
    }
    reverse(path.begin(), path.end());
    cout << path;
    return res;
}

int tab(vvi& mat) {
    const auto m = mat.size();
    const auto n = mat[0].size();
    vvi dp = mat;
    vvpi index(m, vpi(n, {-1, -1}));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 and j == 0) {
                dp[0][0] = mat[0][0];
                index[0][0] = {-1, -1};
            }
            else if (i == 0) {
                dp[0][j] = dp[0][j - 1] + mat[0][j];
                index[0][j] = {0, j - 1};
            }
            else if (j == 0) {
                dp[i][0] = dp[i - 1][0] + mat[i][0];
                index[i][0] = {i - 1, 0};
            }
            else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    index[i][j] = {i - 1, j};
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                    index[i][j] = {i, j - 1};
                }
                dp[i][j] += mat[i][j];
            }
        }
    }
    vi path;
    for (pi idx = {m - 1, n - 1}; idx.first >= 0 and idx.second >= 0;) {
        path.push_back(mat[idx.first][idx.second]);
        idx = index[idx.first][idx.second];
    }
    reverse(path.begin(), path.end());
    cout << path;
    return dp[m - 1][n - 1];
}

int main() { TimeMeasure _; __x();
    vvi mat = {{1, 2, 3},
               {4, 5, 6},
               {7, 8, 9}};
    cout << "Recursive: " << rec(mat) << endl;
    cout << "Tabulation: " << tab(mat) << endl;
}

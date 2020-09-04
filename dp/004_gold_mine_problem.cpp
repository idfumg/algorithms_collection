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

int mine_rec(const vvi& v, int row, int col) {
    if (row < 0 or row >= v.size() or col >= v[0].size()) return 0;
    const auto a = mine_rec(v, row - 1, col + 1);
    const auto b = mine_rec(v, row, col + 1);
    const auto c = mine_rec(v, row + 1, col + 1);
    return max({a, b, c}) + v[row][col];
}

int mine_rec(const vvi& v) {
    int res = 0;
    for (int row = 0; row < v.size(); ++row) {
        res = max(res, mine_rec(v, row, 0));
    }
    return res;
}

int mine_tab(const vvi& v) {
    const auto rows = v.size();
    const auto cols = v[0].size();
    vvi dp(rows + 2, vi(cols + 2));
    for (size_t row = 1; row <= rows; ++row) {
        dp[row][1] = v[row - 1][0];
    }
    for (size_t col = 2; col <= cols; ++col) {
        for (size_t row = 1; row <= rows; ++row) {
            const auto a = dp[row - 1][col - 1];
            const auto b = dp[row][col - 1];
            const auto c = dp[row + 1][col - 1];
            dp[row][col] = max({a, b, c}) + v[row - 1][col - 1];
        }
    }
    int res = 0;
    for (size_t row = 0; row <= rows; ++row) {
        res = max(res, dp[row][cols]);
    }
    return res;
}

int mine_opt(const vvi& v) {
    const auto rows = v.size();
    const auto cols = v[0].size();
    vi first(rows + 1);
    for (size_t row = 1; row <= rows; ++row) first[row] = v[row - 1][0];
    for (size_t col = 2; col <= cols; ++col) {
        vi second(rows + 1);
        for (size_t row = 1; row <= rows; ++row) {
            const auto a = first[row - 1];
            const auto b = first[row];
            const auto c = first[row + 1];
            second[row] = max({a, b, c}) + v[row - 1][col - 1];
        }
        first = second;
    }
    int res = 0;
    for (size_t row = 0; row <= rows; ++row) {
        res = max(res, first[row]);
    }
    return res;
}

int main() { TimeMeasure _;
    const auto v = vvi {{10, 33, 13, 15},
                        {22, 21, 04, 1},
                        {5, 0, 2, 3},
                        {0, 6, 14, 2}};
    cout << "Recursive: " << mine_rec(v) << endl;
    cout << "Tabulation: " << mine_tab(v) << endl;
    cout << "Tabulation: " << mine_opt(v) << endl;
}

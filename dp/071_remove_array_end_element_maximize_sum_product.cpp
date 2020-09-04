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
using vvvvi = vector<vector<vector<vector<int>>>>;
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

int rec(vi& arr, const int i, const int j, const int count, const int sum) {
    if (j < i) return 0;
    if (i == j) return sum + count * arr[i];
    return max({rec(arr, i + 1, j, count + 1, sum + count * arr[i]),
                rec(arr, i, j - 1, count + 1, sum + count * arr[j])});
}

int rec(vi& arr) {
    return rec(arr, 0, arr.size() - 1, 1, 0);
}

int tab(vi& arr) {
    const auto n = arr.size();
    vvvi dp(n + 2, vvi(n + 2, vi(n + 2)));

    for (int i = n; i > 0; --i) {
        for (int j = i; j <= n; ++j) {
            for (int k = n; k > 0; --k) {
                if (i == j) {
                    dp[i][j][k] = k * arr[i - 1];
                }
                else {
                    dp[i][j][k] = max(dp[i + 1][j][k + 1] + k * arr[i - 1],
                                      dp[i][j - 1][k + 1] + k * arr[j - 1]);
                }
            }
        }
    }
    return dp[1][n][1];
}

int opt(vi& arr) {
    const auto n = arr.size();
    vvvi dp(2, vvi(n + 1, vi(2)));
    int idxi = 0, idxk = 0, idxj = 0;

    for (int k = n; k > 0; --k) {
        idxk = k & 1;
        for (int i = n; i >= 1; --i) {
            idxi = i & 1;
            for (int j = i; j <= n; ++j) {

                if (i == j) {
                    dp[idxi][j][idxk] = n * arr[i - 1];
                }
                else {
                    dp[idxi][j][idxk] =
                        max(dp[1 - idxi][j][1 - idxk] + k * arr[i - 1],
                            dp[idxi][j - 1][1 - idxk] + k * arr[j - 1]);
                }
            }
        }
    }
    return dp[idxi][n][idxk];
}

int opt2(vi& arr) {
    const auto n = arr.size();
    vvi dp(2, vi(n + 1));
    int idxi = 0;

    for (int i = n; i >= 1; --i) {
        idxi = i & 1;
        for (int j = i; j <= n; ++j) {
            if (i == j) {
                dp[idxi][j] = n * arr[i - 1];
            }
            else {
                dp[idxi][j] =
                    max(dp[1 - idxi][j] + (n - j + i) * arr[i - 1],
                        dp[idxi][j - 1] + (n - j + i) * arr[j - 1]);
            }
        }
    }
    return dp[idxi][n];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 3, 1, 5, 2};
    vi arr2 = {1, 2};
    cout << "Recursive: " << rec(arr1) << endl;
    cout << "Recursive: " << rec(arr2) << endl;
    cout << "Tabulation: " << tab(arr1) << endl;
    cout << "Tabulation: " << tab(arr2) << endl;
    cout << "Optimized: " << opt(arr1) << endl;
    cout << "Optimized: " << opt(arr2) << endl;
    cout << "Optimized2: " << opt2(arr1) << endl;
    cout << "Optimized2: " << opt2(arr2) << endl;
}

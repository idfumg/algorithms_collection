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

int ismonotone(int n) {
    int prev = n % 10;
    n /= 10;
    while (n > 0) {
        int curr = n % 10;
        n /= 10;
        if (prev <= curr) {
            return false;
        }
        prev = curr;
    }
    return true;
}

int brute(int n) {
    int count = 0;
    for (int i = power(10, n - 1); i < power(10, n); ++i) {
        if (ismonotone(i)) {
            ++count;
        }
    }
    return count;
}

int rec(const int n, const int prev) {
    if (n == 0) return 1;
    if (prev == 0) return 0;
    const auto with = rec(n - 1, prev - 1);
    const auto without = rec(n, prev - 1);
    return with + without;
}

int rec(const int n) {
    const int m = 9;
    return rec(n, m);
}

int tab(const int n) {
    const int m = 9;
    vvi dp(n + 1, vi(m + 1));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0) {
                dp[i][j] = 1;
            }
            else if (j == 0) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            }
        }
    }
    return dp[n][m];
}

int opt(const int n) {
    const int m = 9;
    vvi dp(2, vi(m + 1));
    int idx = 0;

    for (int i = 0; i <= n; ++i) {
        idx = i & 1;
        for (int j = 0; j <= m; ++j) {
            if (i == 0) {
                dp[idx][j] = 1;
            }
            else if (j == 0) {
                dp[idx][j] = 0;
            }
            else {
                dp[idx][j] = dp[1 - idx][j - 1] + dp[idx][j - 1];
            }
        }
    }
    return dp[idx][m];
}

int main() { TimeMeasure _; __x();
    int n1 = 2;
    int n2 = 3;
    int n3 = 1;
    int n4 = 5;
    cout << "Bruteforce: " << brute(n1) << endl;
    cout << "Bruteforce: " << brute(n2) << endl;
    cout << "Bruteforce: " << brute(n3) << endl;
    cout << "Bruteforce: " << brute(n4) << endl;
    cout << "Recursive: " << rec(n1) << endl;
    cout << "Recursive: " << rec(n2) << endl;
    cout << "Recursive: " << rec(n3) << endl;
    cout << "Recursive: " << rec(n4) << endl;
    cout << "Tabulation: " << tab(n1) << endl;
    cout << "Tabulation: " << tab(n2) << endl;
    cout << "Tabulation: " << tab(n3) << endl;
    cout << "Tabulation: " << tab(n4) << endl;
    cout << "Optimization: " << opt(n1) << endl;
    cout << "Optimization: " << opt(n2) << endl;
    cout << "Optimization: " << opt(n3) << endl;
    cout << "Optimization: " << opt(n4) << endl;
}

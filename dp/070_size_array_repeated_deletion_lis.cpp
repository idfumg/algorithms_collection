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

int count(vi& arr, vi& dp, vi& elem, int n, int i) {
    if (i < 0) return 0;
    if (arr[n] > arr[i]) {
        const auto a = dp[i];
        const auto b = count(arr, dp, elem, n, i - 1);
        if (a > b) {
            elem[n] = i;
        }
        return max(a, b);
    }
    return count(arr, dp, elem, n, i - 1);
}

void rec(vi& arr, vi& dp, vi& elem, int& pos, int n) {
    if (n < 0) return;
    rec(arr, dp, elem, pos, n - 1);
    dp[n] = count(arr, dp, elem, n, n - 1) + (arr[n] != -1 ? 1 : 0);
    if (arr[pos] < arr[n]) pos = n;
}

int rec(vi& arr) {
    vi dp(arr.size(), 0);
    vi elem(arr.size(), -1);
    int pos = -1;
    rec(arr, dp, elem, pos, arr.size() - 1);
    const auto maxi = *max_element(dp.begin(), dp.end());
    if (maxi > 1) {
        for (int i = pos; i > -1; i = elem[i]) {
            arr[i] = - 1;
        }
    }
    return maxi;
}

int rec1(vi arr) {
    while (rec(arr) > 1);
    return count_if(arr.begin(), arr.end(), [](int a){return a != -1;});
}

int tab(vi arr) {
    const auto n = arr.size();
    while (true) {
        vi dp(n, 1), from(n, -1);
        int maxi = -INF, pos = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] == -1 or arr[j] == -1) continue;
                if (arr[j] < arr[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        from[i] = j;
                    }
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (dp[pos] < dp[i]) {
                        pos = i;
                    }
                }
            }
        }
        if (dp[pos] > 1) {
            for (int i = pos; i > -1; i = from[i]) {
                arr[i] = -1;
            }
        }
        if (pos == 0) {
            break;
        }
    }
    return count_if(arr.begin(), arr.end(), [](int a){return a != -1;});
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 2, 5, 3, 6, 4, 1};
    vi arr2 = {5, 3, 2};
    vi arr3 = {1, 2, 3, 1, 5, 2};
    vi arr4 = {3, 2, 6, 4, 5, 1};
    cout << "Recursive: " << rec1(arr1) << endl;
    cout << "Recursive: " << rec1(arr2) << endl;
    cout << "Recursive: " << rec1(arr3) << endl;
    cout << "Recursive: " << rec1(arr4) << endl;
    cout << "Tabulation: " << tab(arr1) << endl;
    cout << "Tabulation: " << tab(arr2) << endl;
    cout << "Tabulation: " << tab(arr3) << endl;
    cout << "Tabulation: " << tab(arr4) << endl;
}

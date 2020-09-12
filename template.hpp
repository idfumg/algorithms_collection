#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MOD static_cast<int64_t>(1e18 + 7)
#define PI (3.1415926535897932384626433832795)
#define INF static_cast<int32_t>(1e9)
#define LLINF static_cast<int64_t>(1e18)
#define EPS (1e-9)

using ld = long double;
using ll = int64_t;
using ull = uint64_t;
using vd = vector<double>;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using vvpi = vector<vpi>;
using vvvpi = vector<vvpi>;
using vvvvpi = vector<vvvpi>;
using vvi = vector<vi>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvvi = vector<vvvi>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using si = set<int>;
using sll = set<ll>;

ll mod(const ll x) noexcept {
    return (x % MOD + MOD) % MOD;
}

template<class T>
static ostream& operator << (ostream& os, const pair<T, T>& p) noexcept {
    return os << p.first << ',' << p.second;
}

template<class T>
static ostream& operator << (ostream& os, const vector<pair<T, T>>& v) noexcept {
    for (const auto& value : v) os << '{' << value.first << ',' << value.second << '}' << ' ';
    return os;// << endl;
}

template<class T>
static ostream& operator << (ostream& os, const deque<T>& v) noexcept {
    for (const auto& value : v) os << value << ' ';
    return os;// << endl;
}

template<class T>
static ostream& operator << (ostream& os, const vector<T>& v) noexcept {
    for (const auto& value : v) os << value << ' ';
    return os;// << endl;
}

template<class T>
static ostream& operator << (ostream& os, const vector<vector<T>>& v) noexcept {
    os << '\n';
    for (const auto& L : v) os << L << endl;
    return os;// << endl;
}

template<class T>
static ostream& operator << (ostream& os, const set<T>& s) noexcept {
    for (const auto& value : s) os << value << ' ';
    return os;// << endl;
}

template<class T>
static ostream& operator << (ostream& os, const unordered_set<T>& s) noexcept {
    for (const auto& value : s) os << value << ' ';
    return os;// << endl;
}

template<class T, class U>
static ostream& operator << (ostream& os, const map<T, U>& tab) noexcept {
    os << '\n';
    for (const auto& [key, value] : tab) os << key << ": " << value << '\n';
    return os;// << endl;
}

template<class T, class U>
static ostream& operator << (ostream& os, const unordered_map<T, U>& tab) noexcept{
    os << '\n';
    for (const auto& [key, value] : tab) os << key << ": " << value << '\n';
    return os;// << endl;
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
    TimeMeasure() noexcept
        : start(clock())
    {

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

template<class T>
void sort(T& arr) {
    sort(arr.begin(), arr.end());
}

template<class T>
void reverse(T& arr) {
    reverse(arr.begin(), arr.end());
}

template<class T>
int max(const T& elems) {
    return *max_element(elems.begin(), elems.end());
}

template<class T>
int min(const T& elems) {
    return *min_element(elems.begin(), elems.end());
}

template<class T>
void ruffle_sort(T& arr) { // qsort O(n^2) has complexity if elements sorted
    random_shuffle(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());
}

template <typename T,
          typename TIter = decltype(std::begin(std::declval<T>())),
          typename = decltype(std::end(std::declval<T>()))>
constexpr auto enumerate(T && iterable) noexcept
{
    struct iterator
    {
        size_t i;
        TIter iter;
        bool operator != (const iterator & other) const noexcept { return iter != other.iter; }
        iterator& operator ++ () noexcept { ++i; ++iter; return *this; }
        auto operator * () const noexcept { return std::tie(i, *iter); }
    };
    struct iterable_wrapper
    {
        T& iterable;
        auto begin() noexcept { return iterator{ 0, std::begin(iterable) }; }
        auto end() noexcept { return iterator{ 0, std::end(iterable) }; }
    };
    return iterable_wrapper{ std::forward<T>(iterable) };
}

#define trace() cout << "Line: " << __LINE__ << endl;

[[maybe_unused]] static const auto __x = [](){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::boolalpha);};

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
using vvi = vector<vector<int>>;

class TimeMeasure final {
    time_t start;

public:
    TimeMeasure() noexcept {
        start = clock();
    }
    ~TimeMeasure() noexcept {
        cerr << "\nExecution time: " << ms() << " ms.\n";
    }
    double ms() const noexcept {
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

ostream& operator << (ostream& os, const vi& v) {
    for (const auto value : v) os << value << ' ';
    return os << endl;
}

ostream& operator << (ostream& os, const vvi& v) {
    for (const auto& L : v) {
        os << L;
    }
    return os << endl;
}

istream& operator >> (istream& is, vi& v) {
    for (size_t i = 0; i < v.size(); ++i) is >> v[i];
    return is;
}

istream& operator >> (istream& is, vll& v) {
    for (size_t i = 0; i < v.size(); ++i) is >> v[i];
    return is;
}

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

template<class T>
class BIT final {
    vector<T> tree;

    ll lsb(const ll i) const noexcept {
        return i & -i; // using 2s complement () i & ((~i) + 1)
    }

public:
    BIT(const ll n) noexcept
        : tree(n + 1)
    {

    }

    BIT(const vector<T>& v) noexcept {
        tree.resize(v.size() + 1);

        for (ull i = 0; i < v.size(); ++i) {
            tree[i + 1] = v[i];
        }

        for (ull i = 1; i < tree.size(); ++i) {
            const auto parent = i + lsb(i);
            if (parent < tree.size()) {
                tree[parent] += tree[i];
            }
        }
    }

    ll operator [] (const ll i) noexcept {
        return tree[i];
    }

    ll prefix_sum(ll i) const noexcept {
        ll sum = 0;
        for (; i > 0; i -= lsb(i)) {
            sum += tree[i];
        }
        return sum;
    }

    ll range_sum(const ll i, const ll j) const noexcept {
        return prefix_sum(j) - prefix_sum(i - 1);
    }

    void update(ll i, const ll value) noexcept {
        for (; i < static_cast<ll>(tree.size()); i += lsb(i)) {
            tree[i] += value;
        }
    }

    void range_update(const ll i, const ll j, const ll value) noexcept {
        update(i, value);
        update(j + 1, -value);
    }

    void set(const ll i, const ll value) noexcept {
        const auto delta = value - range_sum(i, i);
        update(i, delta);
    }

    friend ostream& operator<<(ostream& os, const BIT& bit) {
        for (size_t i = 1; i < bit.tree.size(); ++i) {
            os << bit.tree[i] << ' ';
        }
        return os << endl;
    }
};

inline void fast_input(ll *a)
{
    char c = 0;
    while (c < 33) {
        c = getchar_unlocked();
    }
    *a=0;
    while (c > 33) {
        *a = *a * 10 + c - '0';
        c = getchar_unlocked();
    }
}

int main() { //TimeMeasure _;
    int t; cin >> t;

    while (t--) {
        ll n; cin >> n;
        ll u; cin >> u;
        BIT<ll> tree(n);

        while (u--) {
            ll l; cin >> l;
            ll r; cin >> r;
            ll value; cin >> value;
            tree.range_update(l + 1, r + 1, value);
        }

        ll q; cin >> q;
        while (q--) {
            ll index; cin >> index;
            cout << tree.prefix_sum(index + 1) << endl;
        }
    }

    return 0;
}

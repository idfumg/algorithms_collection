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

class BIT final {
    vll tree;

    ll lsb(const ll i) const noexcept {
        return i & -i; // using 2s complement () i & ((~i) + 1)
    }

public:
    ll operator [] (const ll i) noexcept {
        return tree[i];
    }

    BIT(const ll n) noexcept {
        tree = vll(n + 1);
    }

    BIT(const vll& v) noexcept {
        tree = vll(v.size() + 1);

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

void print_path(const vi& v) {
    for (int elem : v) cout << elem << ' ';
    cout << endl;
}

int recur(size_t start, int k, int last, int count, const vi& v) {
    if (k == 0) {
        ++count;
    }
    else {
        for (size_t i = start; i < v.size(); ++i) {
            if (i != 0 and v[i] < last) continue;
            count = recur(i + 1, k - 1, v[i], count, v);
        }
    }
    return count;
}

int recur(const vi& v, const int k) {
    return recur(0, k + 1, 0, 0, v);
}

int naive(const vi& v) {
    int count = 0;
    for (size_t i = 0; i < v.size() - 1; ++i) {
        for (size_t j = i + 1; j < v.size() - 2; ++j) {
            for (size_t k = j + 1; k < v.size(); ++k) {
                if (v[i] <= v[j] && v[j] <= v[k]) {
                    ++count;
                }
            }
        }
    }
    return count;
}

int main() { TimeMeasure _;
    ll n; cin >> n;
    ll k; cin >> k;
    vll v(n); cin >> v;

    vector<BIT> trees(k + 1, n);

    for (ll i = 0; i < n; ++i) {
        trees[0].update(v[i], 1);
        for (ll tree = 1; tree <= k; ++tree) {
            trees[tree].update(v[i], trees[tree - 1].prefix_sum(v[i] - 1));
        }
    }

    cout << trees.back().prefix_sum(n);

    return 0;
}

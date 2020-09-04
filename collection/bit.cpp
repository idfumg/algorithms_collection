#include <bits/stdc++.h>

using namespace std;

using ld = long double;
using ll = int64_t;
using ull = uint64_t;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vector<int>>;

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

int main() {
    return 0;
}

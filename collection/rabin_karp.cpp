#include <string>
#include <iostream>

using namespace std;

void RabinKarp(const string& pattern, const string& txt) {
    using ll = long long;

    const int d = 256; // input alphabet size
    const ll MOD = 1e10 + 7;

    const ll m = pattern.size();
    const ll n = txt.size();

    ll h = 1;
    for (ll i = 0; i < m - 1; ++i) {
        h = (h * d) % MOD;
    }

    ll patternHash = 0;
    ll txtHash = 0;
    for (ll i = 0; i < m; ++i) {
        patternHash = (d * patternHash + pattern[i]) % MOD;
        txtHash = (d * txtHash + txt[i]) % MOD;
    }

    for (ll i = 0; i <= n - m; ++i) {
        if (patternHash == txtHash) {
            if (equal(pattern.begin(), pattern.end(), txt.begin() + i)) {
                cout << i << ' ';
            }
        }
        if (i < n - m) {
            txtHash = (d * (txtHash - txt[i] * h) + txt[i + m]) % MOD;
            if (txtHash < 0) {
                txtHash = txtHash + MOD;
            }
        }
    }
}

int main() {
    RabinKarp("geek", "geek for geeks"); // 0 9
    return 0;
}

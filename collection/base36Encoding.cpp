#include "../template.hpp"

static const auto tab = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
static const auto BASE = 36;
static const auto SIZE = 6;

string Encode36(int n) {
    string ans(SIZE, '_');
    for (int pos = SIZE - 1; n > 0 and pos >= 0; n /= BASE, --pos) {
        ans[pos] = tab[n % BASE];
    }
    return ans;
}

long Decode36(const string& s) {
    long ans = 0;
    const int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] >= 'A' and s[i] <= 'Z') {
            ans = ans * BASE + s[i] - 'A' + 0;
        }
        else if (s[i] >= '0' and s[i] <= '9') {
            ans = ans * BASE + s[i] - '0' + 26;
        }
    }
    return ans;
}

int main() {
    long n1 = INT_MAX;
    long n2 = 12345;
    cout << n1 << '\n';
    cout << Encode36(n1) << '\n';
    cout << Decode36(Encode36(n1)) << '\n' << '\n';
    cout << n2 << '\n';
    cout << Encode36(n2) << '\n';
    cout << Decode36(Encode36(n2)) << '\n';
}

#include "../template.hpp"

void RearrangeKDistance(string s, int k) {
    vi freq(27);
    for (char ch : s) {
        ++freq[ch - 'a'];
    }

    vi idxes(27);
    iota(idxes.begin(), idxes.end(), 0);
    sort(idxes.begin(), idxes.end(), [&](int i, int j){return freq[i] > freq[j];});

    int n = s.size();
    string ans(n, ' ');
    int pos = 0;
    for (int i = 0; i < 27; ++i) {
        while (ans[pos] != ' ') {
            ++pos;
        }
        int idx = idxes[i];
        int count = freq[idx];
        int j = pos;
        while (count > 0 and j < n) {
            ans[j] = idx + 'a';
            j += k;
            --count;
        }
        if (j >= n and count > 0) {
            cout << "Not possible to rearrange" << '\n';
            return;
        }
    }
    cout << ans << '\n';
}

int main() { TimeMeasure _; __x();
    RearrangeKDistance("abb", 2); // bab
    RearrangeKDistance("aacbbc", 3); // abcabc
    RearrangeKDistance("geeksforgeeks", 3); // egkegkesfesor
    RearrangeKDistance("aaa", 2); // Not possible to rearrange
}

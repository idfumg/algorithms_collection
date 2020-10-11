#include "../template.hpp"

struct Item {
    char ch;
    int freq;
    bool operator<(const Item& rhs) const { return freq < rhs.freq; }
};

void RearrangeNoTheSameAdjacent(string s) { // O(nlogn)
    int n = s.size();

    vi freq(26);
    for (int i = 0; i < n; ++i) {
        ++freq[s[i] - 'a'];
    }

    priority_queue<Item> pq;
    for (int i = 0; i <= 26; ++i) {
        if (freq[i] > 0) {
            pq.push({static_cast<char>('a' + i), freq[i]});
        }
    }

    string ans(n, ' ');
    int idx = 0;
    Item prev = Item{' ', -1};

    while (not pq.empty()) {
        Item item = pq.top(); pq.pop();

        ans[idx++] = item.ch;
        --item.freq;

        if (prev.freq > 0) {
            pq.push(prev);
        }

        prev = item;
    }

    if (prev.freq <= 0) {
        cout << ans << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}

int main() { TimeMeasure _; __x();
    RearrangeNoTheSameAdjacent("aaabc"); // abaca
    RearrangeNoTheSameAdjacent("aaabb"); // ababa
    RearrangeNoTheSameAdjacent("aa"); // -1
    RearrangeNoTheSameAdjacent("aaaabc"); // -1
    RearrangeNoTheSameAdjacent("bbbaa"); // babab
    RearrangeNoTheSameAdjacent("bbaaacc"); // abcabca
}

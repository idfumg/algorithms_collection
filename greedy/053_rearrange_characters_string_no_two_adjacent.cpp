#include "../template.hpp"

struct Item {
    char id;
    int freq;
    bool operator<(const Item& rhs) const { return freq < rhs.freq; }
};

void RearrangeNoTheSameAdjacent(string s) {
    vi freq(27);
    for (char ch : s) {
        ++freq[ch - 'a'];
    }

    priority_queue<Item> pq;
    for (int i = 0; i <= 26; ++i) {
        if (freq[i] > 0) {
            pq.push({static_cast<char>(i + 'a'), freq[i]});
        }
    }

    Item prev = {' ', -1};
    string ans;

    while (not pq.empty()) {
        Item item = pq.top(); pq.pop();

        ans += item.id;
        --item.freq;

        if (prev.freq > 0) {
            pq.push(prev);
        }

        prev = item;
    }

    if (prev.freq > 0) {
        cout << "Not possible to rearrange" << '\n';
        return;
    }
    cout << ans << '\n';
}

int main() { TimeMeasure _; __x();
    RearrangeNoTheSameAdjacent("aaabc"); // abaca
    RearrangeNoTheSameAdjacent("aaabb"); // ababa
    RearrangeNoTheSameAdjacent("aa"); // -1
    RearrangeNoTheSameAdjacent("aaaabc"); // -1
    RearrangeNoTheSameAdjacent("bbbaa"); // babab
    RearrangeNoTheSameAdjacent("bbaaacc"); // abcabca
}

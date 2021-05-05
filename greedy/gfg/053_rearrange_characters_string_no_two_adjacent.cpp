#include "../../template.hpp"

void RearrangeNoTheSameAdjacent(string s) {
    int n = s.size();

    unordered_map<char, int> map;
    for (char ch : s) {
        ++map[ch];
    }

    priority_queue<pair<int, char>> pq;
    for (const auto& [ch, count] : map) {
        pq.push({count, ch});
    }

    string ans;
    pair<int, char> saved {-1, -1};

    while (not pq.empty()) {
        const auto [count, ch] = pq.top(); pq.pop();
        ans += ch;
        if (saved.first > 0) {
            pq.push(saved);
        }
        saved = {count - 1, ch};
    }

    if (saved.first > 0) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
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

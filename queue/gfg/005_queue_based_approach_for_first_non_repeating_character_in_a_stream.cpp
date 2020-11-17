#include "../../template.hpp"

void PrintFirstNonRepeating(string s) {
    unordered_map<char, int> tab;
    queue<char> queue;

    for (char ch : s) {
        ++tab[ch];
        if (tab.count(ch) == 1) {
            queue.push(ch);
        }
        while (not queue.empty() and tab[queue.front()] != 1) {
            queue.pop();
        }
        if (not queue.empty()) {
            cout << queue.front() << ' ';
        }
        else {
            cout << -1 << ' ';
        }
    }
    cout << endl;
}

int main() { TimeMeasure _;
    PrintFirstNonRepeating("aabc"); // a -1 b b
    PrintFirstNonRepeating("aac"); // a -1 c
}

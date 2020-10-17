#include "../../template.hpp"

int MinRoomsForEachGroup(const vector<string>& slots) {
    if (slots.empty() or slots[0].empty()) return 0;
    int ans = 0, m = slots[0].size(), n = slots.size();
    for (int i = 0; i < m; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            count += slots[j][i] - '0';
        }
        ans = max(ans, count);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    static const vector<string> slots1 = {"0101010",
                                          "1010101"};

    static const vector<string> slots2 = {"0101011",
                                          "0011001",
                                          "0110111"};

    cout << MinRoomsForEachGroup(slots1) << '\n'; // 1
    cout << MinRoomsForEachGroup(slots2) << '\n'; // 3
}

#include "../../template.hpp"

void AssignMiceToHoles(vi mice, vi holes) {
    if (mice.size() != holes.size()) return;
    sort(mice);
    sort(holes);
    int maxTime = -INF, n = mice.size();
    for (int i = 0; i < n; ++i) {
        maxTime = max(maxTime, abs(mice[i] - holes[i]));
    }
    cout << maxTime << '\n';
}

int main() { TimeMeasure _;
    AssignMiceToHoles({4, -4, 2}, {4, 0, 5}); // 4
    AssignMiceToHoles({-10, -79, -79, 67, 93, -85, -28, -94}, {-2, 9, 69, 25, -31, 23, 50, 78 }); // 102
}

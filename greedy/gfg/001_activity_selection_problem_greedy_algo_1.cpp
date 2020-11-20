#include "../../template.hpp"

void WhichExactlyOfActivities(vi start, vi finish) {
    int n = start.size();
    vi idxs(n);
    iota(idxs.begin(), idxs.end(), 0);
    sort(idxs.begin(), idxs.end(), [&](int a, int b){return finish[a] < finish[b];});
    int ans = 1;
    vi activities;
    int last = idxs[0];
    activities.push_back(last);
    for (int i = 1; i < n; ++i) {
        if (start[idxs[i]] >= finish[last]) {
            ++ans;
            last = idxs[i];
            activities.push_back(last);
        }
    }
    debug(activities); debugn(ans);
}

int main() { TimeMeasure _;
    WhichExactlyOfActivities({3, 8, 0, 5, 5, 1}, {4, 9, 6, 7, 9, 2}); // 4
    WhichExactlyOfActivities({10, 12, 20}, {20, 25, 30}); // 2
    WhichExactlyOfActivities({1, 3, 0, 5, 8, 5}, {2, 4, 6, 7, 9, 9}); // 4
}

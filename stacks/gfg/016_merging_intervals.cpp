#include "../../template.hpp"

bool predicate(vi& a, vi& b) {
    return a[0] < b[0];
}

void MergeIntervals(vvi intervals) {
    sort(intervals.begin(), intervals.end(), predicate);
    stack<vi> stack;
    for (const auto& b : intervals) {
        if (stack.empty()) {
            stack.push(b);
            continue;
        }
        const vi a = stack.top();
        if (b[0] >= a[0] and b[0] <= a[1]) {
            stack.pop();
            stack.push({min(a[0], b[0]), max(a[1], b[1])});
        }
        else {
            stack.push(b);
        }
    }
    debugn(stack);
}

int main() { TimeMeasure _;
    MergeIntervals({{1,3}, {2,4}, {5,7}, {6,8}}); // 5 8, 1 4
    MergeIntervals({{6,8}, {1,9}, {2,4}, {4,7}}); // 1 9
}

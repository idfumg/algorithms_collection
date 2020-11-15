#include "../../template.hpp"

void NextGreaterElement(vi arr) {
    int n = arr.size();
    stack<int> stack;
    vi ans(n, -1);
    for (int i = 0; i < n; ++i) {
        if (stack.empty()) {
            stack.push(i);
        }
        else {
            while (not stack.empty() and arr[stack.top()] < arr[i]) {
                ans[stack.top()] = arr[i];
                stack.pop();
            }
            stack.push(i);
        }
    }
    cout << ans << '\n';
}

int main() { TimeMeasure _;
    NextGreaterElement({4, 5, 2, 25}); // 5 25 25 -1
    NextGreaterElement({13, 7, 6, 12}); // -1 12 12 -1
    NextGreaterElement({11, 13, 21, 3}); // 13 21 -1 -1
}

#include "../../template.hpp"

void NextGreaterFrequencyElement(vi arr) {
    int n = arr.size();
    stack<int> stack;
    vi ans(n, -1);
    unordered_map<int, int> freq;
    for (int value : arr) {
        ++freq[value];
    }
    stack.push(0);
    for (int i = 0; i < n; ++i) {
        while (not stack.empty() and freq[arr[stack.top()]] < freq[arr[i]]) {
            ans[stack.top()] = arr[i];
            stack.pop();
        }
        stack.push(i);
    }
    cout << ans << '\n';
}

int main() { TimeMeasure _;
    NextGreaterFrequencyElement({1, 1, 2, 3, 4, 2, 1}); // -1, -1, 1, 2, 2, 1, -1
    NextGreaterFrequencyElement({1, 1, 1, 2, 2, 2, 2, 11, 3, 3}); // 2, 2, 2, -1, -1, -1, -1, 3, -1, -1
}

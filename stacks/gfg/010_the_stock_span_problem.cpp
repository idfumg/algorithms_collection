#include "../../template.hpp"

void StockSpan(vi arr) {
    int n = arr.size();
    stack<int> stack1;
    stack<int> stack2;
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (not stack1.empty() and stack1.top() < arr[i]) {
            stack1.pop();
            count += stack2.top(); stack2.pop();
        }
        stack1.push(arr[i]);
        stack2.push(count);
        cout << stack2.top() << ' ';
    }
    cout << '\n';
}

int main() { TimeMeasure _;
    StockSpan({100, 80, 60, 70, 60, 75, 85}); // {1, 1, 1, 2, 1, 4, 6}
    StockSpan({10, 4, 5, 90, 120, 80}); // 1 1 2 4 5 1
}

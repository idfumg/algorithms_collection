#include "../../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

bool IsSteppingNumber(int n) {
    int first = -1;
    while (n > 0) {
        int second = n % 10;
        if (first != -1) {
            if (abs(first - second) != 1) {
                return false;
            }
        }
        first = second;
        n /= 10;
    }
    return true;
}

vi Brute(int from, int to) { // O(n^2)
    vi res;
    for (int i = from; i <= to; ++i) { // O(n)
        if (IsSteppingNumber(i)) { // O(n)
            res.push_back(i);
        }
    }
    return res;
}

void bfs(int from, int to, int num, si& nums) {
    deque<int> q;
    q.push_back(num);

    while (not q.empty()) {
        int at = q.front(); q.pop_front();
        if (at >= from and at <= to) nums.insert(at);
        if (at < 0 or at > to) continue;
        q.push_back(at * 10 + at % 10 - 1);
        q.push_back(at * 10 + at % 10 + 1);
    }
}

si bfs(int from, int to) {
    si nums;
    for (int i = 0; i < 10; ++i) {
        bfs(from, to, i, nums);
    }
    return nums;
}

int main() { TimeMeasure _;
    cout << Brute(0, 21) << endl;
    cout << Brute(10, 15) << endl;
    cout << bfs(0, 21) << endl;
    cout << bfs(10, 15) << endl;
}

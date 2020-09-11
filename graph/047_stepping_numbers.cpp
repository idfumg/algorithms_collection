#include "../template.hpp"
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

void bfs(si& res, int from, int to, int num) {
    deque<int> q;
    q.push_back(num);
    while (not q.empty()) {
        int n = q.front(); q.pop_front();
        if (n >= from and n <= to) {
            res.insert(n);
        }
        if (num == 0 or n > to) {
            continue;
        }
        int last = n % 10;
        int stepA = n * 10 + last - 1;
        int stepB = n * 10 + last + 1;
        if (last == 0) {
            q.push_back(stepB);
        }
        else if (last == 9) {
            q.push_back(stepA);
        }
        else {
            q.push_back(stepA);
            q.push_back(stepB);
        }
    }
}

si BfsBased(int from, int to) {
    si res;
    for (int i = 0; i <= 9; ++i) {
        bfs(res, from, to, i);
    }
    return res;
}

int main() { TimeMeasure _;
    cout << Brute(0, 21) << endl;
    cout << Brute(10, 15) << endl;
    cout << BfsBased(0, 21) << endl;
    cout << BfsBased(10, 15) << endl;
}

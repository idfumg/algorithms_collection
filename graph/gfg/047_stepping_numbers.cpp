#include "../../template.hpp"

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

si bfs(int from, int to) { // O(n)
    qi q;
    si ans;

    for (int i = 0; i <= 9; ++i) {
        q.push(i);
    }

    while (not q.empty()) {
        int at = q.front(); q.pop();

        if (at < 0 or at > to) {
            continue;
        }

        if (at >= from and at <= to) {
            ans.insert(at);
        }

        for (int adj : {at * 10 + (at % 10 - 1), at * 10 + (at % 10 + 1)}) {
            q.push(adj);
        }
    }

    return ans;
}

int main() { TimeMeasure _;
    cout << Brute(0, 21) << endl;
    cout << Brute(10, 15) << endl;
    cout << bfs(0, 21) << endl;
    cout << bfs(10, 15) << endl;
}

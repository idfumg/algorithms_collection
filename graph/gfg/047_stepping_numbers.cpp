#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back(to);
    // graph[to].push_back(from);
    // graph.push_back({from, to});
    // graph[from].push_back({to, cost});
    // graph[to].push_back({from, cost});
    // graph.push_back({from, to, cost});
    // graph[from][to] = cost;
    // graph[to][from] = cost;
}

bool isStepping(int n) {
    int prev = n % 10;
    n /= 10;
    for (; n > 0; n /= 10) {
        int curr = n % 10;
        if (abs(curr - prev) != 1) {
            return false;
        }
        prev = curr;
    }
    return true;
}

vi brute(int from, int to) {
    vi ans;
    for (int i = from; i <= to; ++i) {
        if (isStepping(i)) {
            ans.push_back(i);
        }
    }
    return ans;
}

vi bfs(int a, int b) {
    deque<int> q;
    for (int i = 0; i < 10; ++i) {
        q.push_back(i);
    }

    vb visited(b + 1);

    while (not q.empty()) {
        int at = q.front(); q.pop_front();
        if (at >= 0 and at <= b) {
            visited[at] = true;
            q.push_back(at * 10 + at + 1);
            q.push_back(at * 10 + at - 1);
        }
    }

    vi ans;
    for (int i = 0; i <= b; ++i) {
        if (visited[i] and i >= a and i <= b) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << brute(0, 21) << endl; // 0 1 2 3 4 5 6 7 8 9 10 12 21
    cout << brute(10, 15) << endl; // 10, 12
    cout << bfs(0, 21) << endl;
    cout << bfs(10, 15) << endl;
}

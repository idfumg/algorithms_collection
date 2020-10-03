#include "../template.hpp"

struct Cell {
    int num;
    int dist;
};

int MinimumOpsToTransfrom(int from, int to) {
    unordered_set<int> visited;
    deque<Cell> q; q.push_back(Cell{from, 0});

    while (not q.empty()) {
        Cell at = q.front(); q.pop_front();
        if (at.num == to) return at.dist;
        visited.insert(at.num);
        if (not visited.count(at.num * 2)) {
            q.push_back(Cell{at.num * 2, at.dist + 1});
        }
        if (at.num - 1 >= 0 and not visited.count(at.num - 1)) {
            q.push_back(Cell{at.num - 1, at.dist + 1});
        }
    }
    return -1;
}

int MinimumOpsToTransfrom2(int from, int to) {
    if (from > to) swap(from, to);
    qi q;
    q.push(from);
    unordered_set<int> visited;
    unordered_map<int, int> dist;
    dist[from] = 0;
    while (not q.empty()) {
        int at = q.front(); q.pop();
        if (at == to) break;
        if (visited.count(at)) continue;
        visited.insert(at);

        int x = at * 2;
        if (x <= to * to) {
            if (not dist.count(x)) dist[x] = INF;
            dist[x] = min(dist[x], dist[at] + 1);
            q.push(x);
        }

        int y = at - 1;
        if (y >= 0) {
            if (not dist.count(y)) dist[y] = INF;
            dist[y] = min(dist[y], dist[at] + 1);
            q.push(y);
        }
    }
    return dist[to];
}

int main() { TimeMeasure _;
    cout << MinimumOpsToTransfrom(4, 7) << '\n'; // 2
    cout << MinimumOpsToTransfrom(2, 5) << '\n'; // 4
    cout << MinimumOpsToTransfrom2(4, 7) << '\n'; // 2
    cout << MinimumOpsToTransfrom2(2, 5) << '\n'; // 4
}

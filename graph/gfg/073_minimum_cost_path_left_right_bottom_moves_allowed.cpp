#include "../../template.hpp"

struct Node {
    int x;
    int y;
    int weight;
    bool operator<(const Node& rhs) const { return weight > rhs.weight; }
};

static const vvi directions = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
};

bool IsAllowed(vvi& grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    return i >= 0 and j >= 0 and i < m and j < n;
}

void FindMinPath(vvi& grid, const vi& from, const vi& to) {
    int m = grid.size(), n = grid[0].size();
    priority_queue<Node> pq;
    vvi dist(m, vi(n, INF));
    dist[from[0]][from[1]] = grid[from[0]][from[1]];
    pq.push({from[0], from[1], dist[from[0]][from[1]]});
    vvb visited(m, vb(n));
    while (not pq.empty()) {
        Node node = pq.top(); pq.pop();
        visited[node.x][node.y] = true;
        for (const auto& direction : directions) {
            int i = node.x + direction[0];
            int j = node.y + direction[1];
            if (IsAllowed(grid, i, j) and not visited[i][j]) {
                int cost = dist[node.x][node.y] + grid[i][j];
                if (dist[i][j] > cost) {
                    dist[i][j] = cost;
                    pq.push({i, j, cost});
                }
            }
        }
    }
    cout << dist[to[0]][to[1]] << endl;
}

int main() { TimeMeasure _;
    vvi grid = {{31, 100, 65, 12, 18},
                {10, 13, 47, 157, 6},
                {100, 113, 174, 11, 33},
                {88, 124, 41, 20, 140},
                {99, 32, 111, 41, 20}};
    int m = grid.size(), n = grid[0].size();
    FindMinPath(grid, {0, 0}, {m - 1, n - 1});
}

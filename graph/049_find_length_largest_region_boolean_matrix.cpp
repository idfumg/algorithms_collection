#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

static const vvi directions = {
    {-1, 0}, {1, 0},
    {0, -1}, {0, 1},
    {-1, -1}, {-1, 1},
    {1, 1}, {1, -1},
};

bool IsItValidCoords(vvi& graph, int i, int j) {
    int m = graph.size(), n = graph[0].size();
    return i >= 0 and j >= 0 and i < m and j < n and graph[i][j] != 0;
}

void dfs(vvi& graph, vvb& visited, int x, int y, int& count) {
    visited[x][y] = true;
    for (const auto& direction : directions) {
        int i = x + direction[0];
        int j = y + direction[1];
        if (IsItValidCoords(graph, i, j) and not visited[i][j]) {
            ++count;
            dfs(graph, visited, i, j, count);
        }
    }
}

void FindLargestRegion(vvi& graph) {
    int m = graph.size(), n = graph[0].size();
    int count = 0;
    vvb visited(m, vb(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (not visited[i][j]) {
                int nodes_count = 0;
                dfs(graph, visited, i, j, nodes_count);
                count = max(count, nodes_count);
            }
        }
    }
    cout << count << endl;
}

int main() { TimeMeasure _;
    vvi arr1 = {{0, 0, 1, 1, 0},
                {1, 0, 1, 1, 0},
                {0, 1, 0, 0, 0},
                {0, 0, 0, 0, 1}};
    vvi arr2 = {{0, 0, 1, 1, 0},
                {0, 0, 1, 1, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 1}};
    FindLargestRegion(arr1);
    FindLargestRegion(arr2);
}

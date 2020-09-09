#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

struct Node {
    int i;
    int j;
    int value;
    bool operator<(const Node& right) const { return value > right.value; }
};

vvi directions = {
    {0, 1},
    {1, 0},
    {-1, 0},
    {0, -1},
};

bool isValid(vvi& arr, int i, int j, int i2, int j2) {
    const int m = size(arr), n = size(arr[0]);
    return
        (not (i2 >= m or j2 >= n or i2 < 0 or j2 < 0)) and
        (arr[i][j] >= arr[i2][j2]);
}

void dfs(vvi& arr, vvb& visited, int i, int j) {
    visited[i][j] = true;
    for (const auto& direction : directions) {
        int i2 = i + direction[0];
        int j2 = j + direction[1];
        if (isValid(arr, i, j, i2, j2)) {
            if (not visited[i2][j2]) {
                dfs(arr, visited, i2, j2);
            }
        }
    }
}

vvi MinimalInitialVertices(vvi& arr) {
    int m = size(arr), n = size(arr[0]);
    vector<Node> nodes;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            nodes.push_back({i, j, arr[i][j]});
        }
    }
    sort(nodes);
    vvb visited(m, vb(n));
    vvi res;
    for (const auto& node : nodes) {
        if (not visited[node.i][node.j]) {
            res.push_back({node.i, node.j});
            dfs(arr, visited, node.i, node.j);
        }
    }
    return res;
}

int main() { TimeMeasure _;
    vvi arr = {{1,2,3},
               {2,3,1},
               {1,1,1}};
    vvi arr2 = {{3,3},
                {1,1}};
    cout << MinimalInitialVertices(arr) << endl;
    cout << MinimalInitialVertices(arr2) << endl;
}

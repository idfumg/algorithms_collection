#include "../../template.hpp"

struct Cell {
    int i;
    int j;
    friend ostream& operator<<(ostream& os, const Cell& cell) { return os << cell.i << ',' << cell.j; }
};

static const vvi directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(vvi graph, vvb& visited, Cell at) {
    int n = graph.size();
    visited[at.i][at.j] = true;
    for (const auto& direction : directions) {
        int i = at.i + direction[0];
        int j = at.j + direction[1];
        if (i >= 0 and j >= 0 and i < n and j < n and not visited[i][j] and graph[i][j] <= graph[at.i][at.j]) {
            dfs(graph, visited, {i, j});
        }
    }
}

vvi MinimalInitialVertices(vvi arr) {
    const int n = arr.size();

    vector<Cell> terminals;
    int terminalmaxi = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] > terminalmaxi) {
                terminalmaxi = arr[i][j];
                terminals.clear();
                terminals.push_back({i, j});
            }
            else if (arr[i][j] == terminalmaxi) {
                terminals.push_back({i, j});
            }
        }
    }

    vvi ans;
    vvb visited(n, vb(n));
    for (const auto& terminal : terminals) {
        if (not visited[terminal.i][terminal.j]) {
            ans.push_back({terminal.i, terminal.j});
            dfs(arr, visited, terminal);
        }
    }

    return ans;
}

int main() { TimeMeasure _;
    vvi arr = {{1,2,3},
               {2,3,1},
               {1,1,1}};
    vvi arr2 = {{3,3},
                {1,1}};
    cout << MinimalInitialVertices(arr) << '\n'; // {0,2}, {1,1}
    cout << MinimalInitialVertices(arr2) << '\n'; // {0,0}
}

#include "../../template.hpp"

struct Cell {
    int i, j, value;
    bool operator<(const Cell& rhs) const { return value < rhs.value; }
};

ostream& operator<<(ostream& os, const Cell& cell) {
    return os << '{' << cell.i << ',' << cell.j << '}';
}

static const vvi directions = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
};

bool IsValid(vvi& arr, int m, int n, int i, int j, const Cell& from) {
    return i >= 0 and j >= 0 and i < m and j < n and arr[i][j] <= from.value;
}

void bfs(vvi& arr, Cell from, vvb& visited) {
    int m = arr.size(), n = arr[0].size();
    queue<Cell> q;
    q.push(from);

    while (not q.empty()) {
        Cell cell = q.front(); q.pop();
        visited[cell.i][cell.j] = true;
        for (const auto& direction : directions) {
            int i = cell.i + direction[0];
            int j = cell.j + direction[1];
            if (IsValid(arr, m, n, i, j, cell) and not visited[i][j]) {
                q.push({i, j, arr[i][j]});
            }
        }
    }
}

vector<Cell> MinimalInitialVertices(vvi& arr) {
    int n = arr.size(), count = 0;
    priority_queue<Cell> cells;
    vector<Cell> res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cells.push({i, j, arr[i][j]});
        }
    }
    vvb visited(n, vb(n));
    while (not cells.empty()) {
        Cell cell = cells.top(); cells.pop();
        if (not visited[cell.i][cell.j]) {
            res.push_back(cell);
            bfs(arr, cell, visited);
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
    cout << MinimalInitialVertices(arr) << '\n'; // {0,2}, {1,1}
    cout << MinimalInitialVertices(arr2) << '\n'; // {0,0}
}

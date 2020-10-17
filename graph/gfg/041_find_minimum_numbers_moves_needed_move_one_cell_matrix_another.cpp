#include "../../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

struct Cell {
    int i;
    int j;
};

static const vvi directions = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

bool IsValid(vvi& arr, int i, int j){
    int n = size(arr);
    return i >= 0 and j >= 0 and i < n and j < n and arr[i][j] != 0;
}

int MinimumMoves(vvi& arr, Cell from, Cell to) {
    int n = size(arr);
    vvb visited(n, vb(n));
    deque<Cell> q;
    q.push_back(from);
    vvi dist(n, vi(n, -1));
    dist[from.i][from.j] = 0;
    while (not q.empty()) {
        Cell cell = q.front(); q.pop_front();
        visited[cell.i][cell.j] = true;
        for (const auto& direction : directions) {
            int i = cell.i + direction[0];
            int j = cell.j + direction[1];
            if (IsValid(arr, i, j) and not visited[i][j]) {
                dist[i][j] = dist[cell.i][cell.j] + 1;
                q.push_back(Cell{i, j});
            }
        }
    }
    return dist[to.i][to.j];
}

int main() { TimeMeasure _;
    vvi arr1 = {{ 0 , 3 , 2 },
                { 3 , 3 , 0 },
                { 1 , 3 , 0 }};
    vvi arr2 = {{ 3 , 3 , 1 , 0 },
                { 3 , 0 , 3 , 3 },
                { 2 , 3 , 0 , 3 },
                { 0 , 3 , 3 , 3 }};
    cout << MinimumMoves(arr1, Cell{2, 0}, Cell{0, 2}) << endl;
    cout << MinimumMoves(arr2, Cell{0, 2}, Cell{2, 0}) << endl;
}

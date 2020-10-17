#include "../../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

struct Cell {
    int i;
    int j;
    int dist;
};

static const vvi directions = {
    {-1, -2},
    {-1, 2},
    {1, 2},
    {1, -2},
    {2, 1},
    {2, -1},
    {-2, 1},
    {-2, -1},
};

bool IsValid(int n, int i, int j) {
    return i >= 1 and j >= 1 and i <= n and j <= n;
}

int MinStepToReachTarget(int n, Cell from, Cell to) {
    deque<Cell> q;
    q.push_back(from);
    vvb visited(n + 1, vb(n + 1));
    while (not q.empty()) {
        Cell cell = q.front(); q.pop_front();
        if (cell.i == to.i and cell.j == to.j) {
            return cell.dist;
        }
        visited[cell.i][cell.j] = true;
        for (const auto& direction : directions) {
            int i = cell.i + direction[0];
            int j = cell.j + direction[1];
            if (IsValid(n, i, j) and not visited[i][j]) {
                q.push_back(Cell{i, j, cell.dist + 1});
            }
        }
    }
    return 0;
}

int main() { TimeMeasure _;
    cout << MinStepToReachTarget(30, Cell{1, 1, 0}, Cell{30, 30, -1}) << endl;
}

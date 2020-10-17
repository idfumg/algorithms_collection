#include "../../template.hpp"

void OptimizeDebts(vvi& graph) {
    int n = graph.size();
    vvb reach(n, vb(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j]) {
                reach[i][j] = true;
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                reach[i][j] = reach[i][j] or (reach[i][k] and reach[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] and i != j) {
                for (int k = 0; k < n; ++k) {
                    if (k != i and k != j) {
                        if (reach[i][k] and reach[j][k]) {
                            graph[i][k] += graph[i][j];
                            graph[j][k] -= graph[i][j];
                            graph[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j]) {
                cout << i << " pays " << graph[i][j] << " to " << j << '\n';
            }
        }
    }
}

int main() { TimeMeasure _;
    vvi graph = {{0, 1000, 2000},
                 {0, 0, 5000},
                 {0, 0, 0}};
    OptimizeDebts(graph);
}

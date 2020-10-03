#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void FloydWarshall(vvi& graph) {
    int n = graph.size();
    vvi dist = graph;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    cout << dist << endl;
}

int main() { TimeMeasure _;
    /* Let us create the following weighted graph
            10
    (0)------->(3)
        |     /|\
    5 |     |
        |     | 1
    \|/     |
    (1)------->(2)
            3     */
    vvi graph = {{0, 5, INF, 10},
                 {INF, 0, 3, INF},
                 {INF, INF, 0, 1},
                 {INF, INF, INF, 0}};
    FloydWarshall(graph);
}

/*
Following matrix shows the shortest distances between every pair of vertices
      0      5      8      9
    INF      0      3      4
    INF    INF      0      1
    INF    INF    INF      0
*/

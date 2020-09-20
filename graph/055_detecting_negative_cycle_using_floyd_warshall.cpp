#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void DetectCycleFloydWarshall(vvi graph) {
    int n = size(graph);
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (graph[i][i] < 0) {
            cout << "Cycle detected" << endl;
            return;
        }
    }
    cout << "Cycle has not detected" << endl;
}

int main() { TimeMeasure _;
    vvi graph = { {0   , 1   , INF , INF},
                  {INF , 0   , -1  , INF},
                  {INF , INF , 0   ,  -1},
                  {-1  , INF , INF ,   0} };
    DetectCycleFloydWarshall(graph);
}

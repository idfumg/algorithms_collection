#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void TransitiveClosure(vvi& graph) {
    int n = graph.size();
    vvi reach = graph;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
    cout << reach << endl;
}

int main() { TimeMeasure _;
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3
    */
    vvi graph = {{1, 1, 0, 1},
                 {0, 1, 1, 0},
                 {0, 0, 1, 1},
                 {0, 0, 0, 1}};
    TransitiveClosure(graph);
}


/*
Following matrix is transitive closure of the given graph
1 1 1 1
0 1 1 1
0 0 1 1
0 0 0 1
*/

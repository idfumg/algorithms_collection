#include "../template.hpp"

using Graph = vvb;

void TransitiveClosure(Graph dp) {
    int n = dp.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = dp[i][j] or (dp[i][k] and dp[k][j]);
            }
        }
    }
    cout << dp << '\n';
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
    Graph graph = {{1, 1, 0, 1},
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

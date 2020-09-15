#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void PrintKCores(Graph& graph, int k) {
    int n = size(graph);
    vi degree(n), leaves;
    for (int i = 0; i < n; ++i) {
        degree[i] = graph.edges(i).size();
        if (degree[i] < k) {
            degree[i] = -1;
            leaves.push_back(i);
        }
    }
    while (not leaves.empty()) {
        vi temp;
        for (const auto& leaf : leaves) {
            for (const auto& edge : graph.edges(leaf)) {
                if (degree[edge.to] != -1) {
                    if (--degree[edge.to] < k) {
                        degree[edge.to] = -1;
                        temp.push_back(edge.to);
                    }
                }
            }
        }
        leaves = temp;
    }
    cout << "K-Cores:" << endl;
    for (int i = 0; i < n; ++i) {
        if (degree[i] >= k) {
            cout << i << ": ";
            for (const auto& edge : graph.edges(i)) {
                if (degree[edge.to] >= k) {
                    cout << edge.to << " ";
                }
            }
            cout << endl;
        }
    }
}

int main() { TimeMeasure _;
    int k = 3;
    Graph g1(9);
    g1.addUndirectedEdge(0, 1);
    g1.addUndirectedEdge(0, 2);
    g1.addUndirectedEdge(1, 2);
    g1.addUndirectedEdge(1, 5);
    g1.addUndirectedEdge(2, 3);
    g1.addUndirectedEdge(2, 4);
    g1.addUndirectedEdge(2, 5);
    g1.addUndirectedEdge(2, 6);
    g1.addUndirectedEdge(3, 4);
    g1.addUndirectedEdge(3, 6);
    g1.addUndirectedEdge(3, 7);
    g1.addUndirectedEdge(4, 6);
    g1.addUndirectedEdge(4, 7);
    g1.addUndirectedEdge(5, 6);
    g1.addUndirectedEdge(5, 8);
    g1.addUndirectedEdge(6, 7);
    g1.addUndirectedEdge(6, 8);
    PrintKCores(g1, k);

    cout << endl << endl;

    Graph g2(13);
    g2.addUndirectedEdge(0, 1);
    g2.addUndirectedEdge(0, 2);
    g2.addUndirectedEdge(0, 3);
    g2.addUndirectedEdge(1, 4);
    g2.addUndirectedEdge(1, 5);
    g2.addUndirectedEdge(1, 6);
    g2.addUndirectedEdge(2, 7);
    g2.addUndirectedEdge(2, 8);
    g2.addUndirectedEdge(2, 9);
    g2.addUndirectedEdge(3, 10);
    g2.addUndirectedEdge(3, 11);
    g2.addUndirectedEdge(3, 12);
    PrintKCores(g2, k);
}

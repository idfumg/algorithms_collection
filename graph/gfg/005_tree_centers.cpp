#include "../../template.hpp"
#include "../collection/graph.hpp"

vi FindTreeCenters(const Graph& graph) {
    vi leaves;

    vi degree(graph.size());
    for (int i = 0; i < graph.size(); ++i) {
        degree[i] = graph.edges(i).size();
        if (degree[i] <= 1) {
            leaves.push_back(i);
            degree[i] = 0;
        }
    }

    int total = leaves.size();
    while (total < graph.size()) {
        vi temp;

        for (const int leaf : leaves) {
            for (const auto& edge : graph.edges(leaf)) {
                if (--degree[edge.to] == 1) {
                    temp.push_back(edge.to);
                }
            }
        }

        leaves = temp;
        total += leaves.size();
    }

    return leaves;
}

int main() { TimeMeasure _;
    {
        Graph graph(9);
        graph.addUndirectedEdge(0, 1);
        graph.addUndirectedEdge(2, 1);
        graph.addUndirectedEdge(2, 3);
        graph.addUndirectedEdge(3, 4);
        graph.addUndirectedEdge(5, 3);
        graph.addUndirectedEdge(2, 6);
        graph.addUndirectedEdge(6, 7);
        graph.addUndirectedEdge(6, 8);
        cout << FindTreeCenters(graph); // 2
    }
    {
        Graph graph(4);
        graph.addUndirectedEdge(0, 1);
        graph.addUndirectedEdge(1, 2);
        graph.addUndirectedEdge(2, 3);
        cout << FindTreeCenters(graph); // 1 2
    }
    {
        Graph graph(7);
        graph.addUndirectedEdge(0, 1);
        graph.addUndirectedEdge(1, 2);
        graph.addUndirectedEdge(2, 3);
        graph.addUndirectedEdge(3, 4);
        graph.addUndirectedEdge(4, 5);
        graph.addUndirectedEdge(4, 6);
        cout << FindTreeCenters(graph); // 2 3
    }
    {
        Graph graph(2);
        graph.addUndirectedEdge(0, 1);
        cout << FindTreeCenters(graph); // 0 1
    }
}

#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

int dfs(Graph& graph, vb& visited, int at) {
    visited[at] = true;
    int count = 1;
    for (const auto& edge : graph.edges(at)) {
        if (not visited[edge.to]) {
            count += dfs(graph, visited, edge.to);
        }
    }
    return count;
}

int dfs(Graph& graph, int at) {
    vb visited(graph.size());
    return dfs(graph, visited, at);
}

int main() { TimeMeasure _;
    // Create a fully connected graph
    //           (0)
    //           / \
    //        5 /   \ 4
    //         /     \
    // 10     <   -2  >
    //   +->(2)<------(1)      (4)
    //   +--- \       /
    //         \     /
    //        1 \   / 6
    //           > <
    //           (3)
    int numNodes = 5;
    Graph graph(numNodes);
    graph.addDirectedEdge(0, 1, 4);
    graph.addDirectedEdge(0, 2, 5);
    graph.addDirectedEdge(1, 2, -2);
    graph.addDirectedEdge(1, 3, 6);
    graph.addDirectedEdge(2, 3, 1);
    graph.addDirectedEdge(2, 2, 10); // Self loop

    cout << "DFS node count starting at node 0: " << dfs(graph, 0) << endl; // 4
    cout << "DFS node count starting at node 4: " << dfs(graph, 4) << endl; // 1
}

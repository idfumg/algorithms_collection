#include "../../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void dfs(Graph& graph, vb& visited, vi& components, int at, int count) {
    visited[at] = true;
    components[count]++;
    for (const auto& edge : graph.edges(at)) {
        if (not visited[edge.to]) {
            dfs(graph, visited, components, edge.to, count);
        }
    }
}

int FindComponents(Graph& graph, vi& components) {
    int count = 0;
    vb visited(graph.size());
    for (int at = 0; at != graph.size(); ++at) {
        if (not visited[at]) {
            dfs(graph, visited, components, at, count++);
        }
    }
    return count;
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
    graph.addUndirectedEdge(0, 1, 4);
    graph.addUndirectedEdge(0, 2, 5);
    graph.addUndirectedEdge(1, 2, -2);
    graph.addUndirectedEdge(1, 3, 6);
    graph.addUndirectedEdge(2, 3, 1);
    graph.addUndirectedEdge(2, 2, 10); // Self loop

    vi components(graph.size());
    const int count = FindComponents(graph, components);
    cout << count << endl; // 2
    cout << components << endl; // 0 0 0 0 1
}

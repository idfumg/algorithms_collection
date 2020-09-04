#include "../template.hpp"
#include "graph.hpp"

void dfs(const Graph& graph, vb& visited, vi& components, int i, int componentCount) {
    visited[i] = true;
    components[i] = componentCount;
    for (const auto& edge : graph.edges(i)) {
        if (not visited[edge.to]) {
            dfs(graph, visited, components, edge.to, componentCount);
        }
    }
}

int FindComponents(const Graph& graph, vi& components) {
    int componentCount = 0;
    vb visited(graph.size());
    for (int i = 0; i < graph.size(); ++i) {
        if (not visited[i]) {
            dfs(graph, visited, components, i, componentCount++);
        }
    }
    return componentCount;
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

#include "../../template.hpp"
#include "graph.hpp"

int dfs(const Graph& graph, const int startNode) {
    int count = 0;
    vector<bool> visited(graph.size());
    stack<int> suspended;
    suspended.push(startNode);

    while (not suspended.empty()) {
        const int node = suspended.top(); suspended.pop();
        visited[node] = true;
        count += 1;

        for (const Edge& edge : graph.neighbors(node)) {
            if (not visited[edge.to]) {
                suspended.push(edge.to);
            }
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
    graph.addDirectedEdge(0, 1, 4);
    graph.addDirectedEdge(0, 2, 5);
    graph.addDirectedEdge(1, 2, -2);
    graph.addDirectedEdge(1, 3, 6);
    graph.addDirectedEdge(2, 3, 1);
    graph.addDirectedEdge(2, 2, 10); // Self loop

    cout << "DFS node count starting at node 0: " << dfs(graph, 0) << endl; // 4
    cout << "DFS node count starting at node 4: " << dfs(graph, 4) << endl; // 1
}

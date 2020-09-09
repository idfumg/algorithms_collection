#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

vi FindNodesLevels(Graph& graph, int root) {
    int n = graph.size();
    deque<int> q;
    q.push_back(root);
    vi dist(n, INF);
    dist[root] = 0;
    vb visited(n);
    while (not q.empty()) {
        int node = q.front(); q.pop_front();
        visited[node] = true;
        for (const auto& edge : graph.edges(node)) {
            if (not visited[edge.to]) {
                dist[edge.to] = dist[node] + 1;
                q.push_back(edge.to);
            }
        }
    }
    return dist;
}

int main() { TimeMeasure _;
    Graph graph(8);
    graph.addUndirectedEdge(0, 1);
    graph.addUndirectedEdge(0, 2);
    graph.addUndirectedEdge(1, 3);
    graph.addUndirectedEdge(1, 4);
    graph.addUndirectedEdge(1, 5);
    graph.addUndirectedEdge(2, 5);
    graph.addUndirectedEdge(2, 6);
    graph.addUndirectedEdge(6, 7);
    cout << FindNodesLevels(graph, 0) << endl;
}

#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

int MinNumberOfEdges(Graph& graph, int from, int to) {
    int n = size(graph);
    deque<int> q;
    q.push_back(from);
    vb visited(n);
    vi dist(n, INF);
    dist[from] = 0;
    while (not q.empty()) {
        int node = q.front(); q.pop_front();
        visited[node] = true;
        for (const auto& edge : graph.edges(node)) {
            if (not visited[edge.to]) {
                dist[edge.to] = min(dist[edge.to], dist[node] + 1);
                q.push_back(edge.to);
            }
        }
    }
    return dist[to];
}

int main() { TimeMeasure _;
    Graph graph(9);
    graph.addUndirectedEdge(0, 1);
    graph.addUndirectedEdge(0, 7);
    graph.addUndirectedEdge(1, 7);
    graph.addUndirectedEdge(1, 2);
    graph.addUndirectedEdge(2, 3);
    graph.addUndirectedEdge(2, 5);
    graph.addUndirectedEdge(2, 8);
    graph.addUndirectedEdge(3, 4);
    graph.addUndirectedEdge(3, 5);
    graph.addUndirectedEdge(4, 5);
    graph.addUndirectedEdge(5, 6);
    graph.addUndirectedEdge(6, 7);
    graph.addUndirectedEdge(7, 8);
    cout << MinNumberOfEdges(graph, 0, 5) << endl; // 3
}

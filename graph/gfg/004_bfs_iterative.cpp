#include "../../template.hpp"
#include "../collection/graph.hpp"

void bfs(const Graph& graph, vi& prev, int from) {
    vb visited(graph.size());
    deque<int> suspended;
    suspended.push_back(from);

    while (not suspended.empty()) {
        int node = suspended.front(); suspended.pop_front();
        visited[node] = true;
        for (const auto& edge : graph.edges(node)) {
            if (not visited[edge.to]) {
                suspended.push_back(edge.to);
                prev[edge.to] = node;
            }
        }
    }
}

vi ReconstructPath(vi& prev, int from, int to) {
    vi path;
    for (int at = to; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path);
    return path;
}

int main() { TimeMeasure _;
    int numNodes = 13;
    Graph graph(numNodes);

    graph.addUndirectedEdge(0, 7);
    graph.addUndirectedEdge(0, 9);
    graph.addUndirectedEdge(0, 11);
    graph.addUndirectedEdge(7, 11);
    graph.addUndirectedEdge(7, 6);
    graph.addUndirectedEdge(7, 3);
    graph.addUndirectedEdge(6, 5);
    graph.addUndirectedEdge(3, 4);
    graph.addUndirectedEdge(2, 3);
    graph.addUndirectedEdge(2, 12);
    graph.addUndirectedEdge(12, 8);
    graph.addUndirectedEdge(8, 1);
    graph.addUndirectedEdge(1, 10);
    graph.addUndirectedEdge(10, 9);
    graph.addUndirectedEdge(9, 8);

    vi prev(graph.size(), -1);
    bfs(graph, prev, 10);

    cout << ReconstructPath(prev, 10, 5); // 10 9 0 7 6 5
}

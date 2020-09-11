#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

si Intersection(const si& first, const si& second) {
    si res;
    if (empty(first)) {
        return second;
    }
    if (empty(second)) {
        return first;
    }
    for (const int value : first) {
        if (second.count(value)) {
            res.insert(value);
        }
    }
    return res;
}

si bfs(const Graph& graph, const int from, const si& marked, const int k) {
    int n = size(graph);
    vb visited(n);
    deque<int> q;
    q.push_back(from);
    si res;
    res.insert(from);
    vi dist(n);
    dist[from] = 0;
    while (not q.empty()) {
        int at = q.front(); q.pop_front();
        visited[at] = true;
        for (const auto& edge : graph.edges(at)) {
            if (not visited[edge.to]) {
                dist[edge.to] = dist[at] + 1;
                if (dist[edge.to] <= k) {
                    res.insert(edge.to);
                }
                q.push_back(edge.to);
            }
        }
    }
    return res;
}

si FindKDistance(const Graph& graph, const si& marked, const int k) {
    si res;
    for (const int node : marked) {
        const si nodes = bfs(graph, node, marked, k);
        res = Intersection(res, nodes);
    }
    return res;
}

int main() { TimeMeasure _;
    Graph graph(10);
    graph.addUndirectedEdge(1, 0);
    graph.addUndirectedEdge(0, 8);
    graph.addUndirectedEdge(0, 3);
    graph.addUndirectedEdge(2, 3);
    graph.addUndirectedEdge(3, 6);
    graph.addUndirectedEdge(3, 7);
    graph.addUndirectedEdge(3, 5);
    graph.addUndirectedEdge(4, 5);
    graph.addUndirectedEdge(5, 9);
    cout << FindKDistance(graph, {1, 2, 4}, 3) << endl;
}

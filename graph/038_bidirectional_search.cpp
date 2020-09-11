#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

int TheyIntersect(vb& visited1, vb& visited2) {
    for (int i = 0; i < size(visited1); ++i) {
        if (visited1[i] and visited2[i]) {
            return i;
        }
    }
    return -1;
}

vi GetPath(int node, vi& prev1, vi& prev2) {
    vi path;
    for (int at = node; at != -1; at = prev1[at]) {
        path.push_back(at);
    }
    reverse(path);
    for (int at = prev2[node]; at != -1; at = prev2[at]) {
        path.push_back(at);
    }
    return path;
}

void bfs(Graph& graph, deque<int>& q, vb& visited, vi& prev) {
    int at = q.front(); q.pop_front();
    visited[at] = true;
    for (const auto& edge : graph.edges(at)) {
        if (not visited[edge.to]) {
            prev[edge.to] = at;
            q.push_back(edge.to);
        }
    }
}

void FindPathBidirectional(Graph& graph, int from, int to) {
    int n = size(graph);
    vb visited1(n), visited2(n);
    vi prev1(n, -1), prev2(n, -1);
    deque<int> q1, q2;
    q1.push_back(from);
    q2.push_back(to);
    while (not q1.empty() and not q2.empty()) {
        bfs(graph, q1, visited1, prev1);
        bfs(graph, q2, visited2, prev2);
        const auto at = TheyIntersect(visited1, visited2);
        if (at != -1) {
            vi path = GetPath(at, prev1, prev2);
            cout << "Path exists at node: " << at << endl;
            cout << "Path: " << path << endl;
            return;
        }
    }
}

int main() { TimeMeasure _;
    Graph graph(15);
    graph.addUndirectedEdge(0, 4);
    graph.addUndirectedEdge(1, 4);
    graph.addUndirectedEdge(2, 5);
    graph.addUndirectedEdge(3, 5);
    graph.addUndirectedEdge(4, 6);
    graph.addUndirectedEdge(5, 6);
    graph.addUndirectedEdge(6, 7);
    graph.addUndirectedEdge(7, 8);
    graph.addUndirectedEdge(8, 9);
    graph.addUndirectedEdge(8, 10);
    graph.addUndirectedEdge(9, 11);
    graph.addUndirectedEdge(9, 12);
    graph.addUndirectedEdge(10, 13);
    graph.addUndirectedEdge(10, 14);
    FindPathBidirectional(graph, 0, 14);
}

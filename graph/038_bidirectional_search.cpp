#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void bfs(Graph& graph, qi& q, vb& visited, vi& prev) {
    int at = q.front(); q.pop();
    visited[at] = true;
    for (const auto& edge : graph.edges(at)) {
        if (not visited[edge.to]) {
            q.push(edge.to);
            prev[edge.to] = at;
        }
    }
}

int BothIntersect(vb& visited1, vb& visited2) {
    int n = size(visited1);
    for (int i = 0; i < n; ++i) {
        if (visited1[i] and visited2[i]) {
            return i;
        }
    }
    return -1;
}

vi GetPath(int from, vi& prev1, vi& prev2) {
    vi path;
    for (int at = from; at != -1; at = prev1[at]) {
        path.push_back(at);
    }
    reverse(path);
    for (int at = prev2[from]; at != -1; at = prev2[at]) {
        path.push_back(at);
    }
    return path;
}

void BiSearch(Graph& graph, int from, int to) {
    int n = size(graph);

    qi q1, q2;
    q1.push(from);
    q2.push(to);

    vb visited1(n), visited2(n);

    vi prev1(n, -1), prev2(n, -1);

    while (not q1.empty() and not q2.empty()) {
        bfs(graph, q1, visited1, prev1);
        bfs(graph, q2, visited2, prev2);

        const int at = BothIntersect(visited1, visited2);
        if (at != -1) {
            cout << "Intersection found" << endl;
            cout << GetPath(at, prev1, prev2) << endl;
            return;
        }
    }
}

int main() { TimeMeasure _;
    Graph g(15);
    g.addUndirectedEdge(0, 4);
    g.addUndirectedEdge(1, 4);
    g.addUndirectedEdge(2, 5);
    g.addUndirectedEdge(3, 5);
    g.addUndirectedEdge(4, 6);
    g.addUndirectedEdge(5, 6);
    g.addUndirectedEdge(6, 7);
    g.addUndirectedEdge(7, 8);
    g.addUndirectedEdge(8, 9);
    g.addUndirectedEdge(8, 10);
    g.addUndirectedEdge(9, 11);
    g.addUndirectedEdge(9, 12);
    g.addUndirectedEdge(10, 13);
    g.addUndirectedEdge(10, 14);

    int from = 0, to = 14;

    BiSearch(g, from, to);
}

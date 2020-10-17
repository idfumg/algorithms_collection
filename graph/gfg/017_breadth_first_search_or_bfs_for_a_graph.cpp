#include "../../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

vi bfs(Graph& graph, int from) {
    int n = graph.size();
    vb visited(n);
    deque<int> q;
    q.push_back(from);
    vi elems;
    while (not q.empty()) {
        int at = q.front(); q.pop_front();
        elems.push_back(at);
        visited[at] = true;
        for (const auto& edge : graph.edges(at)) {
            if (not visited[edge.to]) {
                q.push_back(edge.to);
            }
        }
    }
    return elems;
}

int main() { TimeMeasure _;
    int n = 4;
    Graph g(n);
    g.addDirectedEdge(0, 1);
    g.addDirectedEdge(0, 2);
    g.addDirectedEdge(1, 2);
    g.addDirectedEdge(2, 0);
    g.addDirectedEdge(2, 3);
    g.addDirectedEdge(3, 3);
    cout << bfs(g, 2) << endl;
}

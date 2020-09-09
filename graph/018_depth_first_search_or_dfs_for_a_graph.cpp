#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

vi dfs(Graph& graph, int from) {
    vi elems;
    int n = graph.size();
    stack<int> s;
    s.push(from);
    vb visited(n);
    while (not s.empty()) {
        int at = s.top(); s.pop();
        visited[at] = true;
        elems.push_back(at);
        for (const auto& edge : graph.edges(at)) {
            if (not visited[edge.to]) {
                s.push(edge.to);
            }
        }
    }
    return elems;
}

int main() { TimeMeasure _;
    Graph g(4);
    g.addDirectedEdge(0, 1);
    g.addDirectedEdge(0, 2);
    g.addDirectedEdge(1, 2);
    g.addDirectedEdge(2, 0);
    g.addDirectedEdge(2, 3);
    g.addDirectedEdge(3, 3);
    cout << dfs(g, 0) << endl; // 0 2 3 1
}

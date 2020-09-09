#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void bfs(Graph& graph, int level, int from) {
    int n = graph.size();
    deque<int> q;
    q.push_back(from);
    vb visited(n);
    int current_level = 0;
    while (not q.empty()) {
        int count = q.size();
        if (current_level++ == level) {
            cout << count << endl;
            return;
        }
        for (int i = 0; i < count; ++i) {
            int node = q.front(); q.pop_front();
            visited[node] = true;
            for (const auto& edge : graph.edges(node)) {
                if (not visited[edge.to]) {
                    q.push_back(edge.to);
                }
            }
        }
    }
}

void PrintNodesOnLevel(Graph& graph, int level, int from) {
    bfs(graph, level, from);
}

int main() { TimeMeasure _;
    Graph g(6);
    g.addUndirectedEdge(0, 1);
    g.addUndirectedEdge(0, 2);
    g.addUndirectedEdge(1, 3);
    g.addUndirectedEdge(2, 4);
    g.addUndirectedEdge(2, 5);

    int level = 2;

    PrintNodesOnLevel(g, level, 0);

    Graph g2(7);
    g2.addUndirectedEdge(0, 1);
    g2.addUndirectedEdge(0, 2);
    g2.addUndirectedEdge(1, 3);
    g2.addUndirectedEdge(1, 4);
    g2.addUndirectedEdge(1, 5);
    g2.addUndirectedEdge(2, 6);

    PrintNodesOnLevel(g2, level, 0);
}

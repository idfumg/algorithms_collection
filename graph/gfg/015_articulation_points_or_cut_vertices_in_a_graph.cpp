#include "../../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void dfs(Graph& graph, int i, vb& visited, vi& desc, vi& lows, int& id, vb& ap, int& rootOutcoming, int root, int parent) {
    if (root == parent) {
        rootOutcoming++;
    }
    visited[i] = true;
    desc[i] = lows[i] = id++;
    for (const auto& edge : graph.edges(i)) {
        if (edge.to == parent) {
            continue;
        }
        else if (not visited[edge.to]) {
            dfs(graph, edge.to, visited, desc, lows, id, ap, rootOutcoming, root, i);
            lows[i] = min(lows[i], lows[edge.to]);
            if (desc[i] < lows[edge.to] and i != root) {
                ap[i] = true;
            }
        }
        else {
            lows[i] = min(lows[i], desc[edge.to]);
        }
    }
}

void Tarjan(Graph& graph) {
    int n = graph.size(), id = 0;
    vb visited(n), ap(n);
    vi desc(n), lows(n);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            int rootOutcoming = 0;
            dfs(graph, i, visited, desc, lows, id, ap, rootOutcoming, i, -1);
            if (rootOutcoming > 1) {
                ap[i] = true;
            }
        }
    }
    cout << ap << endl;
}

void FindArticulationPoints(Graph& graph) {
    Tarjan(graph);
}

int main() { TimeMeasure _;
    cout << "\nArticulation points in first graph \n";
    // 1 0 0 1 0
    Graph g1(5);
    g1.addUndirectedEdge(1, 0);
    g1.addUndirectedEdge(0, 2);
    g1.addUndirectedEdge(2, 1);
    g1.addUndirectedEdge(0, 3);
    g1.addUndirectedEdge(3, 4);
    FindArticulationPoints(g1);

    cout << "\nArticulation points in second graph \n";
    // 0 1 1 0
    Graph g2(4);
    g2.addUndirectedEdge(0, 1);
    g2.addUndirectedEdge(1, 2);
    g2.addUndirectedEdge(2, 3);
    FindArticulationPoints(g2);

    cout << "\nArticulation points in third graph \n";
    // 0 1 0 0 0 0 0
    Graph g3(7);
    g3.addUndirectedEdge(0, 1);
    g3.addUndirectedEdge(1, 2);
    g3.addUndirectedEdge(2, 0);
    g3.addUndirectedEdge(1, 3);
    g3.addUndirectedEdge(1, 4);
    g3.addUndirectedEdge(1, 6);
    g3.addUndirectedEdge(3, 5);
    g3.addUndirectedEdge(4, 5);
    FindArticulationPoints(g3);
}

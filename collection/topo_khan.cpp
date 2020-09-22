#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

vi KhansTopologicalSort(vvvi& graph) {
    int n = graph.size(), total = 0;
    vi indegree(n), ordering;
    qi leaves;
    for (int i = 0; i < n; ++i) {
        for (vi& adj : graph[i]) {
            indegree[adj[0]] += 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            leaves.push(i);
        }
    }
    while (not leaves.empty()) {
        int leaf = leaves.front(); leaves.pop();
        ordering.push_back(leaf);
        for (vi& adj : graph[leaf]) {
            if (--indegree[adj[0]] == 0) {
                leaves.push(adj[0]);
            }
        }
        total += 1;
    }
    if (total != n) {
        cout << "Cycle detected" << endl;
        return {};
    }
    return ordering;
}

vi DAGShortestPath(vvvi& graph, const vi& ordering, int from) {
    int n = graph.size();
    vi dist(n, INF);
    dist[from] = 0;
    for (int i = 0; i < n; ++i) {
        int at = ordering[i];
        if (dist[at] == INF) continue;
        for (vi& adj : graph[at]) {
            dist[adj[0]] = min(dist[adj[0]], dist[at] + adj[1]);
        }
    }
    return dist;
}

int main() { TimeMeasure _;
    vvvi graph2(6);
    graph2[0].push_back({1, 3});
    graph2[0].push_back({2, 2});
    graph2[0].push_back({5, 3});
    graph2[1].push_back({3, 1});
    graph2[1].push_back({2, 6});
    graph2[2].push_back({3, 1});
    graph2[2].push_back({4, 10});
    graph2[3].push_back({4, 5});
    graph2[5].push_back({4, 7});

    const auto ordering2 = KhansTopologicalSort(graph2);
    cout << ordering2 << endl; // 0 1 5 2 3 4

    const auto distances2 = DAGShortestPath(graph2, ordering2, 0);
    cout << distances2 << endl; // 0 3 2 3 8 3
}

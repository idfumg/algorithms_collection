#include "../../template.hpp"

using Graph = vvi;

void AddDirectedEdge(Graph& graph, int from, int to) {
    graph.push_back({from, to});
}

int Find(vi& parent, vi& rank, int i) {
    int root = i, prev = i;
    if (parent[root] == -1) return root;
    for (; parent[root] != -1; root = parent[root]){}
    for (i = parent[i]; i != -1; prev = i, i = parent[i]) rank[prev] = root;
    rank[root] = 1;
    return root;
}

void Union(vi& parent, vi& rank, vi& count, int i, int j) {
    int iroot = Find(parent, rank, i);
    int jroot = Find(parent, rank, j);
    int irank = rank[iroot];
    int jrank = rank[jroot];
    if (iroot == jroot) {
        return;
    }
    else if (irank < jrank) {
        parent[iroot] = jroot;
        count[jroot] += count[iroot];
    }
    else if (irank > jrank) {
        parent[jroot] = iroot;
        count[iroot] += count[jroot];
    }
    else {
        parent[iroot] = jroot;
        count[jroot] += count[iroot];
        rank[jroot] += 1;
    }
}

void HowManyInGroup(Graph& graph, int n) {
    vi parent(n, -1), rank(n), count(n, 1);
    for (const auto& edge : graph) {
        Union(parent, rank, count, edge[0], edge[1]);
    }
    cout << max(count) << '\n';
}

int main() { TimeMeasure _;
    {
        int V = 3;
        Graph graph;
        AddDirectedEdge(graph, 1, 2);
        AddDirectedEdge(graph, 2, 3);
        HowManyInGroup(graph, V + 1); // 3
    }
    {
        int V = 10;
        Graph graph;
        AddDirectedEdge(graph, 1, 2);
        AddDirectedEdge(graph, 3, 1);
        AddDirectedEdge(graph, 3, 4);
        AddDirectedEdge(graph, 5, 4);
        AddDirectedEdge(graph, 3, 5);
        AddDirectedEdge(graph, 4, 6);
        AddDirectedEdge(graph, 5, 2);
        AddDirectedEdge(graph, 2, 1);
        AddDirectedEdge(graph, 7, 1);
        AddDirectedEdge(graph, 1, 2);
        AddDirectedEdge(graph, 9, 10);
        AddDirectedEdge(graph, 8, 9);
        HowManyInGroup(graph, V + 1); // 7
    }
}

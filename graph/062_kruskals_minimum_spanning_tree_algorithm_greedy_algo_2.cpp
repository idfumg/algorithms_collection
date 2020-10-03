#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void AddEdgesKruskal(vvi& graph, const vvi& nodes) {
    for (const vi& node : nodes) {
        graph.push_back({node[0], node[1], node[2]});
    }
}

int Find(vi& parent, vi& rank, int i) {
    int root = i, prev = i;
    if (parent[root] == -1) return root;
    for (; parent[root] != -1; root = parent[root]) {}
    for (i = parent[i]; i != -1; prev = i, i = parent[i]) parent[prev] = root;
    rank[root] = 1;
    return root;
}

bool Union(vi& parent, vi& rank, vi& count, int i, int j) {
    int iroot = Find(parent, rank, i), jroot = Find(parent, rank, j);
    int irank = rank[iroot], jrank = rank[jroot];
    if (iroot == jroot) {
        return false;
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
    return true;
}

void KruskalsMinSpanningTree(vvi& graph, const int n) {
    sort(graph.begin(), graph.end(), [](const auto& a, const auto& b){return a[2] < b[2];});
    vi parent(n, -1), rank(n), count(n, 1);
    int total_nodes = 0, total = 0;
    for (const vi& edge : graph) {
        if (Union(parent, rank, count, edge[0], edge[1])) {
            cout << edge[0] << '-' << edge[1] << ' ' << edge[2] << endl;
            total += edge[2];
            if (++total_nodes == n - 1) break;
        }
    }
    debugn(total);
}

int main() { TimeMeasure _;
    {
        int n = 9;
        vvi graph;
        AddEdgesKruskal(graph, {
                {0, 1, 4},
                {0, 7, 8},
                {1, 2, 8},
                {1, 7, 11},
                {7, 6, 1},
                {7, 8, 7},
                {8, 2, 2},
                {6, 5, 2},
                {2, 3, 7},
                {2, 5, 4},
                {5, 4, 10},
                {3, 4, 9},
            });
        KruskalsMinSpanningTree(graph, n); // 37
    }
    {
        int n = 5;
        vvi graph;
        AddEdgesKruskal(graph, {
                {0, 1, 2},
                {0, 3, 6},
                {1, 0, 2},
                {1, 2, 3},
                {1, 3, 8},
                {1, 4, 5},
                {2, 1, 3},
                {2, 4, 7},
                {3, 0, 6},
                {3, 1, 8},
                {3, 4, 9},
                {4, 1, 5},
                {4, 2, 7},
                {4, 3, 9},
            });
        KruskalsMinSpanningTree(graph, n); // 16
    }
}

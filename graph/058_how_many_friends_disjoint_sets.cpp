#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

// https://onlinejudge.org/external/106/p10608.pdf

void Init(vi& parent, vi& rank) {
    int n = size(parent);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int Find(vi& parent, vi& rank, int i) {
    int at = i, prev = i;
    for (; at != parent[at]; at = parent[at]) {}
    for (i = parent[i]; i != parent[i]; prev = i, i = parent[i]) {
        parent[prev] = at;
        rank[prev] = 1;
    }
    rank[at] = 1;
    return at;
}

void CompressPaths(vi& parent, int i, vi& visited) {
    int at = i, prev = i;
    for (; at != parent[at]; at = parent[at]) {}
    for (i = parent[i]; i != parent[i]; prev = i, i = parent[i]) {
        parent[prev] = at;
        visited[prev] = 1;
    }
}

void Union(vi& parent, vi& rank, int i, int j, vi& count) {
    int iroot = Find(parent, rank, i);
    int jroot = Find(parent, rank, j);
    int irank = rank[iroot];
    int jrank = rank[jroot];

    if (iroot == jroot) {
        return;
    }
    else if (irank  < jrank) {
        parent[iroot] = jroot;
        count[jroot] += count[iroot];
    }
    else if (irank  > jrank) {
        parent[jroot] = iroot;
        count[iroot] += count[jroot];
    }
    else if (irank == jrank) {
        parent[iroot] = jroot;
        rank[jroot]++;
        count[jroot] += count[iroot];
    }
}

void HowManyInGroup(vvi& edges, int n) {
    vi parent(n), rank(n), count(n, 1), visited(n);
    Init(parent, rank);

    for (const auto& edge : edges) {
        Union(parent, rank, edge[0], edge[1], count);
    }

    cout << max(count) << endl;
}

int main() { TimeMeasure _;
    {
        int V = 3;
        vvi edges;
        edges.push_back({1, 2});
        edges.push_back({2, 3});
        HowManyInGroup(edges, V + 1); // 3
    }
    {
        int V = 10;
        vvi edges;
        edges.push_back({1, 2});
        edges.push_back({3, 1});
        edges.push_back({3, 4});
        edges.push_back({5, 4});
        edges.push_back({3, 5});
        edges.push_back({4, 6});
        edges.push_back({5, 2});
        edges.push_back({2, 1});
        edges.push_back({7, 1});
        edges.push_back({1, 2});
        edges.push_back({9, 10});
        edges.push_back({8, 9});
        HowManyInGroup(edges, V + 1); // 7
    }
}

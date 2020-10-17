#include "../../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void Init(vi& parent, vi& rank) {
    int n = size(parent);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int Find(vi& parent, vi& rank, int i) {
    int at = i;
    for (; at != parent[at]; at = parent[at]) {}
    int prev = i;
    for (i = parent[i]; i != parent[i]; prev = i, i = parent[i]) {
        parent[prev] = at;
        rank[prev] = 1;
    }
    rank[at] = 1;
    return at;
}

bool Union(vi& parent, vi& rank, int i, int j) {
    int iroot = Find(parent, rank, i);
    int jroot = Find(parent, rank, j);
    int irank = rank[iroot];
    int jrank = rank[jroot];

    if (iroot == jroot) return true;
    else if (irank  < jrank) parent[iroot] = jroot;
    else if (irank  > jrank) parent[jroot] = iroot;
    else if (irank == jrank) parent[iroot] = jroot, rank[jroot]++;
    return false;
}

void DetectCycle(vvi& edges, int V) {
    vi parent(V), rank(V);
    Init(parent, rank);
    for (const auto& edge : edges) {
        if (Union(parent, rank, edge[0], edge[1])) {
            cout << "Cycle detected" << endl;
            return;
        }
    }
    cout << "Cycle has not detected" << endl;
}

int main() { TimeMeasure _;
    {
        vvi edges;
        edges.push_back({0, 1});
        edges.push_back({1, 2});
        edges.push_back({0, 2});
        DetectCycle(edges, 3); // yes
    }
    {
        vvi edges;
        edges.push_back({0, 1});
        edges.push_back({1, 2});
        edges.push_back({2, 3});
        edges.push_back({0, 2});
        DetectCycle(edges, 4); // yes
    }
    {
        vvi edges;
        edges.push_back({0, 1});
        edges.push_back({1, 2});
        edges.push_back({2, 3});
        DetectCycle(edges, 4); // no
    }
    {
        vvi edges;
        edges.push_back({1, 0});
        edges.push_back({0, 2});
        edges.push_back({2, 1});
        edges.push_back({0, 3});
        edges.push_back({3, 4});
        DetectCycle(edges, 5); // yes
    }
    {
        vvi edges;
        edges.push_back({0, 1});
        edges.push_back({0, 2});
        edges.push_back({1, 3});
        edges.push_back({2, 4});
        edges.push_back({3, 4});
        edges.push_back({4, 5});
        edges.push_back({5, 6});
        edges.push_back({6, 7});
        edges.push_back({7, 8});
        DetectCycle(edges, 9); // yes
    }
    {
        vvi edges;
        edges.push_back({9, 1});
        edges.push_back({0, 1});
        edges.push_back({1, 3});
        edges.push_back({3, 4});
        edges.push_back({4, 2});
        edges.push_back({2, 8});
        edges.push_back({2, 7});
        edges.push_back({4, 5});
        edges.push_back({5, 6});
        DetectCycle(edges, 10); // no
    }
}

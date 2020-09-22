#include "../template.hpp"

int Find(vi& parent, vi& rank, int i) {
    int root = i, prev = i;
    if (parent[root] == -1) return root;
    for (; parent[root] != -1; root = parent[root]) {}
    for (i = parent[i]; i != -1; prev = i, i = parent[i]) parent[prev] = root;
    rank[root] = 1;
    return root;
}

bool Union(vi& parent, vi& rank, vi& count, int i, int j) {
    int iroot = Find(parent, rank, i);
    int jroot = Find(parent, rank, j);
    int irank = rank[iroot];
    int jrank = rank[jroot];
    if (iroot == jroot) return false;
    if (irank < jrank) {
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

void KruskalsMinSpanningTree(vvi& edges, int n) {
    sort(edges.begin(), edges.end(), [](auto& a, auto& b){ return a[2] < b[2]; });
    vi parent(n, -1), rank(n, 0), count(n, 1);
    int total = 0;
    for (const auto& edge : edges) {
        if (Union(parent, rank, count, edge[0], edge[1])) {
            cout << edge[0] << '-' << edge[1] << ' ' << edge[2] << endl;
            total += edge[2];
        }
    }
    debugn(total);
}

int main() { TimeMeasure _;
    {
        int n = 9;
        vvi edges = {
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
        };
        KruskalsMinSpanningTree(edges, n); // 37
    }
    {
        int n = 5;
        vvi edges = {
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
        };
        KruskalsMinSpanningTree(edges, n); // 16
    }
}

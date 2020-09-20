#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void Init(vi& parent, vi& rank, vi& count) {
    const int n = size(parent);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
        count[i] = 1;
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

void Union(vi& parent, vi& rank, vi& count, int i, int j) {
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


int main() { TimeMeasure _;

}

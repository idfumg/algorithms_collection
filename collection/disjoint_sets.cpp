#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

int Find(vi& parent, vi& rank, int i) {
    int at = i, prev = i;
    for (; parent[at] != -1; at = parent[at]) {}
    for (i = parent[i]; i != -1; prev = i, i = parent[i]) parent[prev] = at;
    rank[at] = 1;
    return at;
}

void Union(vi& parent, vi& rank, vi& count, int i, int j) {
    int iroot = Find(parent, rank, i), jroot = Find(parent, rank, j);
    int irank = rank[iroot], jrank = rank[jroot];
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
        count [jroot] += count[iroot];
        rank[jroot] += 1;
    }
}

int main() { TimeMeasure _;

}

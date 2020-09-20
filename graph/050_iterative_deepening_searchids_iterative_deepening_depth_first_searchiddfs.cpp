#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

bool dls(vvi& graph, int from, int target, int depth) {
    if (from == target) return true;
    if (depth <= 0) return false;
    for (int node : graph[from]) {
        if (dls(graph, node, target, depth - 1)) return true;
    }
    return false;
}

bool iddfs(vvi& graph, int from, int target, int maxdepth) {
    for (int depth = 0; depth <= maxdepth; ++depth) {
        if (dls(graph, from, target, depth)) {
            return true;
        }
    }
    return false;
}

int main() { TimeMeasure _;
    vvi graph(7);
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(5);
    graph[2].push_back(6);
    cout << iddfs(graph, 0, 6, 3) << endl;
}

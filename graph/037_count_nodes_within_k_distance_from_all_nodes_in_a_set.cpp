#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void dfs(Graph& graph, vb& visited, int at, int k, set<int>& reachable) {
    if (k == 0) return;
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            reachable.insert(adj);
            dfs(graph, visited, adj, k - 1, reachable);
        }
    }
}

set<int> UnionSets(set<int>& a, const set<int>& b) {
    set<int> res;
    if (a.empty()) {
        return b;
    }
    if (b.empty()) {
        return a;
    }
    for (int elem : a) {
        if (b.count(elem)) {
            res.insert(elem);
        }
    }
    return res;
}

int FindKDistance(Graph& graph, const vi& nodes, int k) {
    int n = graph.size();
    vector<set<int>> sets;
    for (const int node : nodes) {
        vb visited(n);
        set<int> reachable;
        reachable.insert(node);
        dfs(graph, visited, node, k, reachable);
        sets.push_back(reachable);
    }
    set<int> res;
    for (const auto& elems : sets) {
        res = UnionSets(res, elems);
    }
    return res.size();
}

int main() { TimeMeasure _;
    Graph graph(10);
    AddEdge(graph, 1, 0);
    AddEdge(graph, 0, 8);
    AddEdge(graph, 0, 3);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 3, 6);
    AddEdge(graph, 3, 7);
    AddEdge(graph, 3, 5);
    AddEdge(graph, 4, 5);
    AddEdge(graph, 5, 9);
    cout << FindKDistance(graph, {1, 2, 4}, 3) << endl;
}

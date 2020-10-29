#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, const int from, const int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void dfs(const Graph& graph, vb& visited, unordered_map<int, int>& freqs, const int at, const int k) {
    ++freqs[at];
    if (k <= 0) return;
    visited[at] = true;
    for (const int adj : graph[at]) {
        if (not visited[adj]) {
            dfs(graph, visited, freqs, adj, k - 1);
        }
    }
}

vi FindKDistance(Graph& graph, const vi& terminals, int k) {
    int n = graph.size(), m = terminals.size();
    unordered_map<int, int> freqs;
    for (int i = 0; i < m; ++i) {
        vb visited(n);
        dfs(graph, visited, freqs, terminals[i], k);
    }
    vi ans;
    for (const auto& [key, value] : freqs) {
        if (value >= m) {
            ans.push_back(key);
        }
    }
    sort(ans);
    return ans;
}

void dfs2(Graph& graph, vb& visited, vb& reach, int k, int at) {
    visited[at] = true;
    reach[at] = k >= 0;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            dfs2(graph, visited, reach, k - 1, adj);
        }
    }
}

vi FindKDistance2(Graph& graph, vi terminals, int k) {
    int n = graph.size();
    vb reachFinal(n);

    for (int terminal : terminals) {
        vb visited(n);
        vb reach(n);

        dfs2(graph, visited, reach, k, terminal);

        for (int i = 0; i < n; ++i) {
            reachFinal[i] = (terminal == terminals[0]) ? reach[i] : (reach[i] and reachFinal[i]);
        }
    }

    vi ans;
    for (int i = 0; i < n; ++i) {
        if (reachFinal[i]) {
            ans.push_back(i);
        }
    }
    return ans;
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
    cout << FindKDistance2(graph, {1, 2, 4}, 3) << endl;
}

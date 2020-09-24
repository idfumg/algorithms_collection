#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

bool dfs(Graph& graph, vb& visited, int at, vi& disc, vi& lows, int& id, int parent, int root, int& outdegree) {
    if (parent == root) {
        ++outdegree;
    }
    visited[at] = true;
    disc[at] = lows[at] = id++;
    for (int adj : graph[at]) {
        if (adj == parent) {
            continue;
        }
        else if (not visited[adj]) {
            if (dfs(graph, visited, adj, disc, lows, id, at, root, outdegree)) return true;
            lows[at] = min(lows[at], lows[adj]);
            if (disc[at] <= lows[adj] and at != root) return true;
        }
        else {
            lows[at] = min(lows[at], disc[adj]);
        }
    }
    return false;
}

bool IsBiconnected(Graph& graph) {
    int n = graph.size(), id = 0;
    vb visited(n);
    vi disc(n), lows(n);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            int outdegree = 0;
            if (dfs(graph, visited, i, disc, lows, id, -1, i, outdegree)) return false;
            if (outdegree > 1) return false;
        }
    }
    if (not all_of(visited.begin(), visited.end(), [](bool v){return v;})) return false;
    return true;
}

int main() { TimeMeasure _;
    {
        Graph graph(2);
        AddEdge(graph, 0, 1);
        IsBiconnected(graph) ? cout << "Yes\n" : cout << "No\n"; // yes
    }

    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        AddEdge(graph, 2, 4);
        IsBiconnected(graph) ? cout << "Yes\n" : cout << "No\n"; // yes
    }

    {
        Graph graph(3);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        IsBiconnected(graph) ? cout << "Yes\n" : cout << "No\n"; // no
    }

    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        IsBiconnected(graph) ? cout << "Yes\n" : cout << "No\n"; // no
    }

    {
        Graph graph(3);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 0);
        IsBiconnected(graph) ? cout << "Yes\n" : cout << "No\n"; // yes
    }
}

#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void dfs(Graph& graph, vb& visited, vb& ap, vi& desc, vi& lows, int& id, int root, int at, int parent, int& rootOutdegree) {
    if (parent == root) {
        ++rootOutdegree;
    }
    visited[at] = true;
    desc[at] = lows[at] = id++;
    for (int adj : graph[at]) {
        if (adj == parent) {
            continue;
        }
        else if (not visited[adj]) {
            dfs(graph, visited, ap, desc, lows, id, root, adj, at, rootOutdegree);
            lows[at] = min(lows[at], lows[adj]);
            if (desc[at] <= lows[adj] and at != root) {
                ap[at] = true;
            }
        }
        else {
            lows[at] = min(lows[at], desc[adj]);
        }
    }
}

void FindArticulationPoints(Graph& graph) {
    int n = graph.size(), id = 0;
    vi desc(n), lows(n);
    vb visited(n), ap(n);
    for (int at = 0; at < n; ++at) {
        if (not visited[at]) {
            int rootOutdegree = 0;
            dfs(graph, visited, ap, desc, lows, id, at, at, -1, rootOutdegree);
            if (rootOutdegree > 1) {
                ap[at] = true;
            }
        }
    }
    cout << ap << endl;
}

int main() { TimeMeasure _;
    {
        Graph graph(9);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        AddEdge(graph, 3, 4);
        AddEdge(graph, 2, 5);
        AddEdge(graph, 5, 6);
        AddEdge(graph, 6, 7);
        AddEdge(graph, 7, 8);
        AddEdge(graph, 8, 5);
        FindArticulationPoints(graph); // 0 0 1 1 0 1 0 0 0
    }
    {
        Graph graph(3);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        FindArticulationPoints(graph); // 0 1 0
    }
    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        FindArticulationPoints(graph); // 1 0 0 1 0
    }
    {
        Graph graph(4);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        FindArticulationPoints(graph); // 0 1 1 0
    }
    {
        Graph graph(7);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 0);
        AddEdge(graph, 1, 3);
        AddEdge(graph, 1, 4);
        AddEdge(graph, 1, 6);
        AddEdge(graph, 3, 5);
        AddEdge(graph, 4, 5);
        FindArticulationPoints(graph); // 0 1 0 0 0 0 0
    }
}

#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

bool dfs(Graph& graph, vi& disc, vi& lows, vi& parent, int& id, int at) {
    disc[at] = lows[at] = id++;
    int children = 0;
    for (int adj : graph[at]) {
        if (disc[adj] == -1) {
            children += 1;
            parent[adj] = at;
            if (dfs(graph, disc, lows, parent, id, adj)) return true;
            lows[at] = min(lows[at], lows[adj]);
            if (parent[at] == -1 and children > 1) {
                return true;
            }
            if (parent[at] != -1 and disc[at] <= lows[adj]) {
                return true;
            }
        }
        else if (parent[at] != adj) {
            lows[at] = min(lows[at], disc[adj]);
        }
    }
    return false;
}

bool IsBiconnected(Graph& graph) {
    int n = graph.size(), id = 0;
    vi disc(n, -1), lows(n), parent(n, -1);
    for (int at = 0; at < n; ++at) {
        if (disc[at] == -1) {
            if (dfs(graph, disc, lows, parent, id, at)) return false;
        }
    }
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

#include "../../template.hpp"

struct Edge {
    int idx;
    bool isDisabled;
    bool isBridge;
};

using Graph = vector<vector<Edge>>;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back({to, false, false});
    graph[to].push_back({from, false, false});
}

void ReachAllVertices(Graph& graph, vb& visited, int from) {
    visited[from] = true;
    for (Edge& adj : graph[from]) {
        if (not visited[adj.idx]) {
            ReachAllVertices(graph, visited, adj.idx);
        }
    }
}

bool IsGraphConnected(Graph& graph) {
    int n = graph.size(), from = 0;
    for (int i = 0; i < n; ++i) {
        if (not graph[i].empty()) {
            from = i;
            break;
        }
    }
    if (from == n) {
        return true;
    }
    vb visited(n);
    ReachAllVertices(graph, visited, from);
    for (int i = 0; i < n; ++i) {
        if (not graph[i].empty() and not visited[i]) {
            return false;
        }
    }
    return true;
}

bool IsEulerian(Graph& graph) {
    if (not IsGraphConnected(graph)) {
        cout << "Graph is not Eulerian" << endl;
        return false;
    }
    int odd = 0, n =graph.size();
    for (int i = 0; i < n; ++i) {
        if (graph[i].size() % 2 != 0) {
            ++odd;
        }
    }
    if (odd > 2) {
        cout << "Graph is not Eulerian" << endl;
        return false;
    }
    else if (odd == 0) {
        cout << "Graph has Eulerian path and cycle" << endl;
        return true;
    }
    else {
        cout << "Graph has Eulerian path" << endl;
        return true;
    }
}

void MarkAsBridge(Graph& graph, int at, Edge& adj) {
    adj.isBridge = true;
    for (Edge& opposite : graph[adj.idx]) {
        if (opposite.idx == at) {
            opposite.isBridge = true;
            break;
        }
    }
}

void dfs(Graph& graph, vi& disc, vi& lows, vi& parent, int& id, int at) {
    disc[at] = lows[at] = id++;
    for (Edge& adj : graph[at]) {
        if (disc[adj.idx] == -1) {
            parent[adj.idx] = at;
            dfs(graph, disc, lows, parent, id, adj.idx);
            lows[at] = min(lows[at], lows[adj.idx]);
            if (disc[at] < lows[adj.idx]) {
                MarkAsBridge(graph, at, adj);
            }
        }
        else if (parent[at] != adj.idx) {
            lows[at] = min(lows[at], disc[adj.idx]);
        }
    }
}

void TarjanFindBridges(Graph& graph) {
    int n = graph.size(), id = 0;
    vi disc(n, -1), lows(n, -1), parent(n, -1);
    for (int i = 0; i < n; ++i) {
        if (disc[i] == -1) {
            dfs(graph, disc,  lows, parent, id, i);
        }
    }
}

int HowManyNonBridges(Graph& graph, int at) {
    int count = 0;
    for (Edge& adj : graph[at]) {
        if (not adj.isBridge and not adj.isDisabled) {
            ++count;
        }
    }
    return count;
}

void DisableEdge(Graph& graph, int at, Edge& edge) {
    edge.isDisabled = true;
    for (Edge& adj : graph[edge.idx]) {
        if (adj.idx == at) {
            adj.isDisabled = true;
            break;
        }
    }
}

void PrintEuleurPath(Graph& graph, int at) {
    int nonBridgesCount = HowManyNonBridges(graph, at);
    for (Edge& adj : graph[at]) {
        if (not adj.isDisabled) {
            if (nonBridgesCount > 0) {
                if (not adj.isBridge) {
                    cout << at << '-' << adj.idx << ' ';
                    DisableEdge(graph, at, adj);
                    PrintEuleurPath(graph, adj.idx);
                }
            }
            else {
                cout << at << '-' << adj.idx << ' ';
                DisableEdge(graph, at, adj);
                PrintEuleurPath(graph, adj.idx);
            }
        }
    }
}

void PrintEuleurPath(Graph& graph) {
    if (not IsEulerian(graph)) {
        cout << '-' << endl;
        return;
    }
    int n = graph.size(), from = 0;
    for (int i = 0; i < n; ++i) {
        if (graph[i].size() % 2 != 0) {
            from = i; // start from a vertex with an odd number of edges or just 0
            break;
        }
    }
    TarjanFindBridges(graph);
    PrintEuleurPath(graph, from); cout << endl;
}

int main() { TimeMeasure _;
    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        PrintEuleurPath(graph);
    }

    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        AddEdge(graph, 4, 0);
        PrintEuleurPath(graph);
    }

    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        AddEdge(graph, 1, 3);
        PrintEuleurPath(graph);
    }

    {
        // Let us create a graph with 3 vertices
        // connected in the form of cycle
        Graph graph(3);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 0);
        PrintEuleurPath(graph);
    }

    {
        // Let us create a graph with all vertices
        // with zero degree
        Graph graph(3);
        PrintEuleurPath(graph);
    }

    {
        Graph graph(4);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        PrintEuleurPath(graph);
    }

    {
        Graph graph(3);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 0);
        PrintEuleurPath(graph);
    }

    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        AddEdge(graph, 3, 2);
        AddEdge(graph, 3, 1);
        AddEdge(graph, 2, 4);
        PrintEuleurPath(graph);
    }
}

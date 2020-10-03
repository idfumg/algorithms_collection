#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void dfs(Graph& graph, vvb& isBridge, vi& nonBridges, vi& disc, vi& lows, vi& parent, int& id, int at) {
    disc[at] = lows[at] = id++;
    for (int adj : graph[at]) {
        if (disc[adj] == -1) {
            parent[adj] = at;
            dfs(graph, isBridge, nonBridges, disc, lows, parent, id, adj);
            lows[at] = min(lows[at], lows[adj]);
            if (disc[at] < lows[adj]) {
                isBridge[adj][at] = isBridge[at][adj] = true;
            }
        }
        else if (adj != parent[at]) {
            lows[at] = min(lows[at], disc[adj]);
        }
        nonBridges[at] += isBridge[at][adj] ? 0 : 1;
    }
}

void TarjanBridges(Graph& graph, vvb& isBridge, vi& nonBridges) {
    int n = graph.size(), id = 0;
    vi disc(n, -1), lows(n), parent(n, -1);
    for (int i = 0; i < n; ++i) {
        if (disc[i] == -1) {
            dfs(graph, isBridge, nonBridges, disc, lows, parent, id, i);
        }
    }
}

void TraverseAllConnectedVertices(Graph& graph, vb& visited, int at) {
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            TraverseAllConnectedVertices(graph, visited, adj);
        }
    }
}

bool IsGraphConnected(Graph& graph) {
    int n = graph.size(), from = -1;
    for (int i = 0; i < n; ++i) {
        if (not graph[i].empty()) {
            from = i;
            break;
        }
    }
    if (from == -1) return true;
    vb visited(n);
    TraverseAllConnectedVertices(graph, visited, from);
    for (int i = 0; i < n; ++i) {
        if (not visited[i] and not graph[i].empty()) {
            return false;
        }
    }
    return true;
}

bool IsEulerian(Graph& graph) {
    int n = graph.size();

    if (not IsGraphConnected(graph)) {
        return false;
    }

    int odd = 0;
    for (int i = 0; i < n; ++i) {
        if (graph[i].size() % 2 != 0) {
            ++odd;
        }
    }

    if (odd == 0) {
        cout << "Graph has Eulerian path and cycle" << endl;
        return true;
    }
    if (odd == 1 or odd == 2) {
        cout << "Graph has Eulerian path and cycle" << endl;
        return true;
    }
    cout << "Graph is not Eulerian" << endl;
    return false;
}

void dfs_euler(Graph& graph, vvb& isDisabled, vvb& isBridge, vi& nonBridges, int at) {
    for (int adj : graph[at]) {
        if (not isDisabled[at][adj]) {
            isDisabled[adj][at] = isDisabled[at][adj] = true;
            if (isBridge[at][adj] and nonBridges[at] == 0) {
                cout << at << '-' << adj << ' ';
                dfs_euler(graph, isDisabled, isBridge, nonBridges, adj);
            }
            else if (not isBridge[at][adj] and nonBridges[at] > 0) {
                cout << at << '-' << adj << ' ';
                nonBridges[at] -= 1;
                nonBridges[adj] -= 1;
                dfs_euler(graph, isDisabled, isBridge, nonBridges, adj);
            }
        }
    }
}

void PrintEuleurPath(Graph& graph) {
    int n = graph.size();

    if (not IsEulerian(graph)) {
        cout << '-' << '\n';
        return;
    }

    vvb isBridge(n, vb(n)), isDisabled(n, vb(n));
    vi nonBridges(n, 0);
    TarjanBridges(graph, isBridge, nonBridges);

    int from = 0;
    for (int i = 0; i < n; ++i) {
        if (graph[i].size() % 2 != 0) {
            from = i;
            break;
        }
    }

    dfs_euler(graph, isDisabled, isBridge, nonBridges, from);
    cout << '\n';
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

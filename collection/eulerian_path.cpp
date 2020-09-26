#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void ReachAllVertices(Graph& graph, vb& visited, int from) {
    visited[from] = true;
    for (int adj : graph[from]) {
        if (not visited[adj]) {
            ReachAllVertices(graph, visited, adj);
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

void dfs(Graph& graph, vi& disc, vi& lows, vi& parent, int& id, int at, vvb& isBridge, vi& nonBridges) {
    disc[at] = lows[at] = id++;
    for (int adj : graph[at]) {
        if (disc[adj] == -1) {
            parent[adj] = at;
            dfs(graph, disc, lows, parent, id, adj, isBridge, nonBridges);
            lows[at] = min(lows[at], lows[adj]);
            if (disc[at] < lows[adj]) {
                isBridge[at][adj] = isBridge[adj][at] = true;
            }
            else {
                nonBridges[at] += 1;
            }
        }
        else if (parent[at] != adj) {
            lows[at] = min(lows[at], disc[adj]);
        }
    }
}

void TarjanFindBridges(Graph& graph, vvb& isBridge, vi& nonBridges) {
    int n = graph.size(), id = 0;
    vi disc(n, -1), lows(n, -1), parent(n, -1);
    for (int i = 0; i < n; ++i) {
        if (disc[i] == -1) {
            dfs(graph, disc,  lows, parent, id, i, isBridge, nonBridges);
        }
    }
}

void PrintEuleurPath(Graph& graph, int at, vvb& isDisabled, vvb& isBridge, vi& nonBridges) {
    for (int adj : graph[at]) {
        if (not isDisabled[at][adj]) {
            if (nonBridges[at] > 0 and not isBridge[at][adj]) {
                cout << at << '-' << adj << ' ';
                isDisabled[at][adj] = isDisabled[adj][at] = true;
                nonBridges[at] -= 1;
                PrintEuleurPath(graph, adj, isDisabled, isBridge, nonBridges);
            }
            else {
                cout << at << '-' << adj << ' ';
                isDisabled[at][adj] = isDisabled[adj][at] = true;
                PrintEuleurPath(graph, adj, isDisabled, isBridge, nonBridges);
            }
        }
    }
}

void PrintEuleurPath(Graph& graph) {
    if (not IsEulerian(graph)) {
        cout << '-' << endl;
        return;
    }

    int n = graph.size();
    vvb isDisabled(n, vb(n)), isBridge(n, vb(n));
    vi nonBridges(n);
    TarjanFindBridges(graph, isBridge, nonBridges);

    int from = 0;
    for (int i = 0; i < n; ++i) {
        if (graph[i].size() % 2 != 0) {
            from = i; // start from a vertex with an odd number of edges or just 0
            break;
        }
    }
    PrintEuleurPath(graph, from, isDisabled, isBridge, nonBridges); cout << endl;
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

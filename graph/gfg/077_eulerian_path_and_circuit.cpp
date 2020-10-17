#include "../../template.hpp"

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

void IsEulerian(Graph& graph) {
    if (not IsGraphConnected(graph)) {
        cout << "Graph is not Eulerian" << endl;
        return;
    }
    int odd = 0, n =graph.size();
    for (int i = 0; i < n; ++i) {
        if (graph[i].size() % 2 != 0) {
            ++odd;
        }
    }
    if (odd > 2) {
        cout << "Graph is not Eulerian" << endl;
    }
    else if (odd == 0) {
        cout << "Graph has Eulerian path and cycle" << endl;
    }
    else {
        cout << "Graph has Eulerian path" << endl;
    }
}

int main() { TimeMeasure _;
    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        IsEulerian(graph);
    }

    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        AddEdge(graph, 4, 0);
        IsEulerian(graph);
    }

    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        AddEdge(graph, 1, 3);
        IsEulerian(graph);
    }

    {
        // Let us create a graph with 3 vertices
        // connected in the form of cycle
        Graph graph(3);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 0);
        IsEulerian(graph);
    }

    {
        // Let us create a graph with all veritces
        // with zero degree
        Graph graph(3);
        IsEulerian(graph);
    }
}

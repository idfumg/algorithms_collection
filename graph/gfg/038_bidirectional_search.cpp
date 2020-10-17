#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void bfs(Graph& graph, qi& q, vb& visited, vi& prev) {
    int at = q.front(); q.pop();
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            prev[adj] = at;
            q.push(adj);
        }
    }
}

int BothVisited(vb& visited1, vb& visited2) {
    int n = visited1.size();
    for (int i = 0; i < n; ++i) {
        if (visited1[i] and visited2[i]) {
            return i;
        }
    }
    return -1;
}

void PrintPath(vi& prev1, vi& prev2, int node) {
    vi path;
    for (int at = prev1[node]; at != -1; at = prev1[at]) {
        path.push_back(at);
    }
    reverse(path);
    cout << path;
    for (int at = node; at != -1; at = prev2[at]) {
        cout << at << ' ';
    }
    cout << '\n';
}

void BiSearch(Graph& graph, int from, int to) {
    int n = graph.size();
    vb visited1(n), visited2(n);
    vi prev1(n, -1), prev2(n, -1);
    qi q1, q2;
    q1.push(from);
    q2.push(to);
    while (not q1.empty() and not q2.empty()) {
        bfs(graph, q1, visited1, prev1);
        bfs(graph, q2, visited2, prev2);
        int at = BothVisited(visited1, visited2);
        if (at != -1) {
            cout << "Intersection found at position " << at << '\n';
            PrintPath(prev1, prev2, at);
            break;
        }
    }
}

int main() { TimeMeasure _;
    Graph g(15);
    AddEdge(g, 0, 4);
    AddEdge(g, 1, 4);
    AddEdge(g, 2, 5);
    AddEdge(g, 3, 5);
    AddEdge(g, 4, 6);
    AddEdge(g, 5, 6);
    AddEdge(g, 6, 7);
    AddEdge(g, 7, 8);
    AddEdge(g, 8, 9);
    AddEdge(g, 8, 10);
    AddEdge(g, 9, 11);
    AddEdge(g, 9, 12);
    AddEdge(g, 10, 13);
    AddEdge(g, 10, 14);

    int from = 0, to = 14;

    BiSearch(g, from, to);
}

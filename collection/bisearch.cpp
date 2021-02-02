#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back(to);
    graph[to].push_back(from);
    // graph.push_back({from, to});
    // graph[from].push_back({to, cost});
    // graph[to].push_back({from, cost});
    // graph.push_back({from, to, cost});
    // graph[from][to] = cost;
    // graph[to][from] = cost;
}

void bfs(vvi graph, deque<int>& q, vb& visited, vi& prev) {
    int at = q.front(); q.pop_front();
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            prev[adj] = at;
            q.push_back(adj);
        }
    }
}

int FindIntersection(vb& visited1, vb& visited2) {
    int n = visited1.size();
    for (int i = 0; i < n; ++i) {
        if (visited1[i] and visited2[i]) {
            return i;
        }
    }
    return -1;
}

void PrintIntersection(vi& prev1, vi& prev2, int idx) {
    deque<int> path;
    for (int at = idx; at != -1; at = prev1[at]) {
        path.push_front(at);
    }
    for (int at = prev2[idx]; at != -1; at = prev2[at]) {
        path.push_back(at);
    }
    cout << path << endl;
}

void BiSearch(vvi graph, int from, int to) {
    int n = graph.size();

    deque<int> q1;
    deque<int> q2;

    q1.push_back(from);
    q2.push_back(to);

    vb visited1(n);
    vb visited2(n);

    vi prev1(n, -1);
    vi prev2(n, -1);

    while (not q1.empty() and not q2.empty()) {
        bfs(graph, q1, visited1, prev1);
        bfs(graph, q2, visited2, prev2);
        int idx = FindIntersection(visited1, visited2);
        if (idx != -1) {
            cout << "found found intersection at " << idx << endl;
            PrintIntersection(prev1, prev2, idx);
            return;
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

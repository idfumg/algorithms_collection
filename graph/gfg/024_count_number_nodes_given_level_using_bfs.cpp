#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void PrintNodesOnLevel(vvi graph, int level, int from) {
    int n = graph.size();
    deque<int> q;
    q.push_back(from);
    vb visited(n);
    while (not q.empty()) {
        if (level-- == 0) {
            cout << q << endl;
            return;
        }
        int at = q.front(); q.pop_front();
        visited[at] = true;
        for (int adj : graph[at]) {
            if (not visited[adj]) {
                q.push_back(adj);
            }
        }
    }
}

int main() { TimeMeasure _;
    Graph g(6);
    AddEdge(g, 0, 1);
    AddEdge(g, 0, 2);
    AddEdge(g, 1, 3);
    AddEdge(g, 2, 4);
    AddEdge(g, 2, 5);

    int level = 2;

    PrintNodesOnLevel(g, level, 0); // 2 3

    Graph g2(7);
    AddEdge(g2, 0, 1);
    AddEdge(g2, 0, 2);
    AddEdge(g2, 1, 3);
    AddEdge(g2, 1, 4);
    AddEdge(g2, 1, 5);
    AddEdge(g2, 2, 6);

    PrintNodesOnLevel(g2, level, 0); // 2 3 4 5
}

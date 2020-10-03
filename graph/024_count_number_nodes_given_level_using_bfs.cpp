#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void PrintNodesOnLevel(Graph& graph, int level, int from) {
    qi q;
    q.push(from);
    int current_level = 0, n = graph.size();
    vb visited(n);
    while (not q.empty()) {
        if (current_level++ == level) {
            cout << q.size() << '\n';
            return;
        }
        for (int count = q.size(); count > 0; --count) {
            int at = q.front(); q.pop();
            visited[at] = true;
            for (int adj : graph[at]) {
                if (not visited[adj]) {
                    q.push(adj);
                }
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

    PrintNodesOnLevel(g, level, 0); // 3

    Graph g2(7);
    AddEdge(g2, 0, 1);
    AddEdge(g2, 0, 2);
    AddEdge(g2, 1, 3);
    AddEdge(g2, 1, 4);
    AddEdge(g2, 1, 5);
    AddEdge(g2, 2, 6);

    PrintNodesOnLevel(g2, level, 0); // 4
}

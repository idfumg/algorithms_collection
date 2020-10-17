#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void PrintKCores(Graph& graph, int k) {
    int n = graph.size();
    vi degree(n);
    qi leaves;
    for (int i = 0; i < n; ++i) {
        degree[i] = graph[i].size();
        if (degree[i] < k) {
            leaves.push(i);
        }
    }
    while (not leaves.empty()) {
        int at = leaves.front(); leaves.pop();
        for (int adj : graph[at]) {
            if (degree[adj] != 0 and --degree[adj] < k) {
                leaves.push(adj);
            }
        }
        degree[at] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (degree[i] != 0) {
            cout << i << ':' << ' ';
            for (int adj : graph[i]) {
                if (degree[adj] != 0) {
                    cout << adj << ' ';
                }
            }
            cout << '\n';
        }
    }
}

int main() { TimeMeasure _;
    int k = 3;
    Graph g1(9);
    AddEdge(g1, 0, 1);
    AddEdge(g1, 0, 2);
    AddEdge(g1, 1, 2);
    AddEdge(g1, 1, 5);
    AddEdge(g1, 2, 3);
    AddEdge(g1, 2, 4);
    AddEdge(g1, 2, 5);
    AddEdge(g1, 2, 6);
    AddEdge(g1, 3, 4);
    AddEdge(g1, 3, 6);
    AddEdge(g1, 3, 7);
    AddEdge(g1, 4, 6);
    AddEdge(g1, 4, 7);
    AddEdge(g1, 5, 6);
    AddEdge(g1, 5, 8);
    AddEdge(g1, 6, 7);
    AddEdge(g1, 6, 8);
    PrintKCores(g1, k);

    cout << endl << endl;

    Graph g2(13);
    AddEdge(g2, 0, 1);
    AddEdge(g2, 0, 2);
    AddEdge(g2, 0, 3);
    AddEdge(g2, 1, 4);
    AddEdge(g2, 1, 5);
    AddEdge(g2, 1, 6);
    AddEdge(g2, 2, 7);
    AddEdge(g2, 2, 8);
    AddEdge(g2, 2, 9);
    AddEdge(g2, 3, 10);
    AddEdge(g2, 3, 11);
    AddEdge(g2, 3, 12);
    PrintKCores(g2, k);

// 2: 3 4 6
// 3: 2 4 6 7
// 4: 2 3 6 7
// 6: 2 3 4 7
// 7: 3 4 6
}

#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back(to);
    // graph[to].push_back(from);
    // graph.push_back({from, to});
    // graph[from].push_back({to, cost});
    // graph[to].push_back({from, cost});
    // graph.push_back({from, to, cost});
    // graph[from][to] = cost;
    // graph[to][from] = cost;
    assert(cost >= 0 or cost <= 0);
}

void FindPaths(Graph& graph, int from, int to) {
    int n = graph.size();

    queue<vi> paths;
    paths.push({from});

    vb visited(n);

    while (not paths.empty()) {
        vi currentPath = paths.front(); paths.pop();
        int at = currentPath.back();
        visited[at] = true;

        for (int adj : graph[at]) {
            if (not visited[adj]) {
                vi newPath = currentPath + adj;
                if (adj == to) {
                    cout << newPath << '\n';
                }
                else {
                    paths.push(newPath);
                }
            }
        }
    }
}

int main() { TimeMeasure _;
    Graph graph(4);
    AddEdge(graph, 0, 3);
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 2);
    AddEdge(graph, 1, 3);
    AddEdge(graph, 2, 0);
    AddEdge(graph, 2, 1);
    FindPaths(graph, 2, 3);
// 2 0 3
// 2 1 3
// 2 0 1 3
}

#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

void FindPaths(Graph& graph, int from, int to) {
    int n = graph.size();
    vb visited(n);
    queue<vi> q;
    q.push({from});
    while (not q.empty()) {
        vi path = q.front(); q.pop();
        visited[path.back()] = true;
        for (int adj : graph[path.back()]) {
            if (not visited[adj]) {
                vi newpath = path;
                newpath.push_back(adj);
                if (newpath.back() == to) {
                    cout << newpath << '\n';
                }
                else {
                    q.push(newpath);
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
}
// 2 0 3
// 2 1 3
// 2 0 1 3

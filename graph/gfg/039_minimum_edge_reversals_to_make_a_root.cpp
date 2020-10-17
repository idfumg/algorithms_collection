#include "../../template.hpp"

using Graph = vvi;

void AddUndirectedEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void AddDirectedEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

bool NotInRealGraph(Graph& graph, int from, int to) {
    for (int adj : graph[from]) {
        if (adj == to) return false;
    }
    return true;
}

int bfs(Graph& graph, Graph& realgraph, int from) {
    int n = graph.size(), count = 0;
    qi q;
    vb visited(n);
    q.push(from);
    while (not q.empty()) {
        int at = q.front(); q.pop();
        visited[at] = true;
        for (int adj : graph[at]) {
            if (not visited[adj]) {
                q.push(adj);

                if (NotInRealGraph(realgraph, at, adj)) {
                    ++count;
                }
            }
        }
    }
    return count;
}

void MinReversalsToMakeRoot(Graph& graph, Graph& realgraph) {
    int mini = INF, n = graph.size(), root = -1;
    for (int i = 0; i < n; ++i) {
        int count = bfs(graph, realgraph, i);
        if (mini > count) {
            mini = count;
            root = i;
        }
    }
    cout << root << ' ' << mini << '\n';
}

int main() { TimeMeasure _;
    int n = 8;
    Graph graph(n);
    AddUndirectedEdge(graph, 0, 1);
    AddUndirectedEdge(graph, 2, 1);
    AddUndirectedEdge(graph, 3, 2);
    AddUndirectedEdge(graph, 3, 4);
    AddUndirectedEdge(graph, 5, 4);
    AddUndirectedEdge(graph, 5, 6);
    AddUndirectedEdge(graph, 7, 6);

    Graph graphReal(n);
    AddDirectedEdge(graphReal, 0, 1);
    AddDirectedEdge(graphReal, 2, 1);
    AddDirectedEdge(graphReal, 3, 2);
    AddDirectedEdge(graphReal, 3, 4);
    AddDirectedEdge(graphReal, 5, 4);
    AddDirectedEdge(graphReal, 5, 6);
    AddDirectedEdge(graphReal, 7, 6);

    MinReversalsToMakeRoot(graph, graphReal);
}

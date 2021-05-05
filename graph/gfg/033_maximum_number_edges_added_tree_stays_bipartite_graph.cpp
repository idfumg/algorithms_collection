#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from - 1].push_back(to - 1);
    graph[to - 1].push_back(from - 1);
    // graph.push_back({from, to});
    // graph[from].push_back({to, cost});
    // graph[to].push_back({from, cost});
    // graph.push_back({from, to, cost});
    // graph[from][to] = cost;
    // graph[to][from] = cost;
}

bool dfs(vvi graph, vi& color, int at) {
    for (int adj : graph[at]) {
        if (color[adj] == -1) {
            color[adj] = 1 - color[at];
            if (not dfs(graph, color, adj)) return false;
        }
        else if (color[at] == color[adj]) {
            return false;
        }
    }
    return true;
}

void FindMaxEdgesDFS(vvi graph) {
    int n = graph.size();
    vi color(n, -1);
    for (int at = 0; at < n; ++at) {
        if (color[at] == -1) {
            color[0] = 0;
            if (not dfs(graph,color, at)) {
                cout << "Not bipartite" << endl;
                return;
            }
        }
    }
    int reds = 0;
    int blacks = 0;
    int redsConnections = 0;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            ++reds;
            redsConnections += graph[i].size();
        }
        else if (color[i] == 1) {
            ++blacks;
        }
    }
    cout << reds * blacks - redsConnections << endl;
}

void FindMaxEdgesBFS(vvi graph) {
    int n = graph.size();
    vi color(n, -1);
    color[0] = 0;
    deque<int> q;
    q.push_back(0);
    while (not q.empty()) {
        int at = q.front(); q.pop_front();
        for (int adj : graph[at]) {
            if (color[adj] == -1) {
                color[adj] = 1 - color[at];
                q.push_back(adj);
            }
            else if (color[adj] == color[at]) {
                cout << "not a bipartite graph" << endl;
                return;
            }
        }
    }
    int reds = 0;
    int blacks = 0;
    int redsConnections = 0;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            ++reds;
            redsConnections += graph[i].size();
        }
        else if (color[i] == 1) {
            ++blacks;
        }
    }
    cout << reds * blacks - redsConnections << endl;
}

int main() { TimeMeasure _;
    {
        Graph graph(3);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 1, 3);
        FindMaxEdgesBFS(graph);
        FindMaxEdgesDFS(graph);
    }
    {
        Graph graph(5);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 1, 3);
        AddEdge(graph, 2, 4);
        AddEdge(graph, 3, 5);
        FindMaxEdgesBFS(graph);
        FindMaxEdgesDFS(graph);
    }
}

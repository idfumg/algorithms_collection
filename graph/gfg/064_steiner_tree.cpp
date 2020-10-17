#include "../../template.hpp"

using Node = vi;
using Graph = vector<vector<Node>>;

void AddEdge(Graph& graph, int from, int to, int weight) {
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
}

void Dijkstra(Graph& graph, vi& prev, vi& dist, int from) {
    int n = graph.size();
    dist[from] = 0;
    priority_queue<Node> pq;
    pq.push({from, dist[from]});
    vb visited(n);
    while (not pq.empty()) {
        Node node = pq.top(); pq.pop();
        visited[node[0]] = true;
        for (Node& adj : graph[node[0]]) {
            if (not visited[adj[0]]) {
                int cost = dist[node[0]] + adj[1];
                if (dist[adj[0]] > cost) {
                    dist[adj[0]] = cost;
                    prev[adj[0]] = node[0];
                    pq.push({adj[0], cost});
                }
            }
        }
    }
}

void FindPathToFreshTerminalVertex(Graph& graph, Graph& newgraph, vi& terminal_vertices, vb& intree) {
    int n = graph.size(), mindist = INF, minterminal = -1;
    vi prev, dist;

    for (int i = 0; i < n; ++i) {
        if (intree[i]) {
            vi prev_temp(n, -1), dist_temp(n, INF);
            Dijkstra(graph, prev_temp, dist_temp, i);

            for (int terminal : terminal_vertices) {
                if (not intree[terminal] and dist_temp[terminal] < mindist) {
                    mindist = dist_temp[terminal];
                    minterminal = terminal;
                    prev = prev_temp;
                    dist = dist_temp;
                }
            }
        }
    }

    for (int i = minterminal, j = prev[minterminal]; j != -1; i = j, j = prev[j]) {
        AddEdge(newgraph, j, i, dist[i] - dist[j]);
        intree[i] = true;
    }
}

void dfs(Graph& graph, vb& visited, int at) {
    visited[at] = true;
    for (Node& adj : graph[at]) {
        if (not visited[adj[0]]) {
            cout << at << '-' << adj[0] << ' ' << adj[1] << '\n';
            dfs(graph, visited, adj[0]);
        }
    }
}

void SteinerGraph(Graph& graph, vi& terminal_vertices) {
    int n = graph.size(), m = terminal_vertices.size();
    vb intree(n);
    Graph newgraph(n);

    intree[terminal_vertices[0]] = true;
    while (--m) {
        FindPathToFreshTerminalVertex(graph, newgraph, terminal_vertices, intree);
    }

    vb visited(n);
    while (--n) {
        if (not visited[n]) {
            dfs(newgraph, visited, n);
        }
    }
}

int main() { TimeMeasure _;
    // case 1: n = 2 terminals: find shortest path between two vertices of the graph O(n)
    // case 2: n = graph.size() terminals: find spanning tree of the graph O(nlogn)
    // case 3: n > 2 and n < graph.size() terminals: O(n * nlogn)
    int n = 6;
    Graph graph(n);
    AddEdge(graph, 0, 1, 7);
    AddEdge(graph, 0, 5, 6);
    AddEdge(graph, 1, 2, 1);
    AddEdge(graph, 1, 5, 5);
    AddEdge(graph, 5, 4, 10);
    AddEdge(graph, 5, 3, 4);
    AddEdge(graph, 2, 3, 1);
    AddEdge(graph, 2, 4, 3);
    AddEdge(graph, 4, 3, 1);
    vi terminal_vertices = {0, 2, 4, 5};
    SteinerGraph(graph, terminal_vertices); // cost: 12
}

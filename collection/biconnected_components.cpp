#include "../template.hpp"

using Graph = vvi;
using Edge = pi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void PrintBiconnectedComponent(stack<Edge>& edges, const Edge& terminalEdge) {
    while (not edges.empty()) {
        pi edge = edges.top(); edges.pop();
        cout << edge.first << '-' << edge.second << ' ';
        if (edge == terminalEdge) {
            cout << '\n';
            return;
        }
    }
}

void dfs(Graph& graph, vi& disc, vi& lows, vi& parent, stack<Edge>& edges, int& id, int at) {
    disc[at] = lows[at] = id++;
    int children = 0;
    for (int adj : graph[at]) {
        if (disc[adj] == -1) {
            children += 1;
            parent[adj] = at;
            edges.push({at, adj});
            dfs(graph, disc, lows, parent, edges, id, adj);
            lows[at] = min(lows[at], lows[adj]);
            if (parent[at] == -1 and children > 1) {
                PrintBiconnectedComponent(edges, Edge{at, adj});
            }
            if (parent[at] != -1 and disc[at] <= lows[adj]) {
                PrintBiconnectedComponent(edges, Edge{at, adj});
            }
        }
        else if (parent[at] != adj and disc[adj] < lows[at]) {
            lows[at] = min(lows[at], disc[adj]);
            edges.push({at, adj});
        }
    }
}

void PrintBiconnectedComponents(Graph& graph){
    int n = graph.size(), id = 0;
    stack<Edge> edges;
    vi disc(n, -1), lows(n), parent(n, -1);
    for (int at = 0; at < n; ++at) {
        if (disc[at] == -1) {
            dfs(graph, disc, lows, parent, edges, id, at);
            PrintBiconnectedComponent(edges, Edge{-1, -1});
        }
    }
}

int main() { TimeMeasure _;
    {
        Graph graph(12);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 1, 3);
        AddEdge(graph, 3, 1);
        AddEdge(graph, 2, 3);
        AddEdge(graph, 3, 2);
        AddEdge(graph, 2, 4);
        AddEdge(graph, 4, 2);
        AddEdge(graph, 3, 4);
        AddEdge(graph, 4, 3);
        AddEdge(graph, 1, 5);
        AddEdge(graph, 5, 1);
        AddEdge(graph, 0, 6);
        AddEdge(graph, 6, 0);
        AddEdge(graph, 5, 6);
        AddEdge(graph, 6, 5);
        AddEdge(graph, 5, 7);
        AddEdge(graph, 7, 5);
        AddEdge(graph, 5, 8);
        AddEdge(graph, 8, 5);
        AddEdge(graph, 7, 8);
        AddEdge(graph, 8, 7);
        AddEdge(graph, 8, 9);
        AddEdge(graph, 9, 8);
        AddEdge(graph, 10, 11);
        AddEdge(graph, 11, 10);
        PrintBiconnectedComponents(graph);
        // 4,2 3,4 3,1 2,3 1,2
// 8,9
// 8,5 7,8 5,7
// 6,0 5,6 1,5 0,1
// 10,11
    }

    cout << "-------------" << endl;

    {
        Graph graph(6);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 2);
        AddEdge(graph, 2, 5);
        AddEdge(graph, 2, 4);
        AddEdge(graph, 5, 4);
        AddEdge(graph, 4, 1);
        PrintBiconnectedComponents(graph);
        // 4,1
// 4,2 5,4 2,5
// 3,2
// 0,3
    }
}

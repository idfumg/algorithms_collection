#include "../../template.hpp"

using Graph = vvi;

void AddDirectedEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

vi KhansTopoSort(Graph& graph) {
    int n = graph.size();
    vi ordering;
    qi q;
    vi indegree(n);
    for (int i = 0; i < n; ++i) {
        for (int adj : graph[i]) {
            ++indegree[adj];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (not q.empty()) {
        int at = q.front(); q.pop();
        ordering.push_back(at);
        for (int adj : graph[at]) {
            if (--indegree[adj] == 0) {
                q.push(adj);
            }
        }
    }
    return ordering;
}

vi KhanTopoSort(vvi graph) {
    int n = graph.size();
    vi indegree(n);
    for (int i = 0; i < n; ++i) {
        for (int adj : graph[i]) {
            ++indegree[adj];
        }
    }
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push_back(i);
        }
    }
    vi ordering;
    while (not q.empty()) {
        int at = q.front(); q.pop_front();
        ordering.push_back(at);
        for (int adj : graph[at]) {
            if (--indegree[adj] == 0) {
                q.push_back(adj);
            }
        }
    }
    return ordering;
}

int MaximumEdgesToAdd(vvi graph) {
    int n = graph.size();
    int count = 0;
    vi ordering = KhanTopoSort(graph);
    for (int i = 0; i < n; ++i) {
        int at = ordering[i];
        vb visited(n);
        for (int adj : graph[at]) {
            visited[adj] = true;
        }
        for (int j = i + 1; j < n; ++j) {
            if (not visited[ordering[j]]) {
                ++count;
            }
        }
    }
    return count;
}

void MaximumEdgesToPrint(vvi graph) {
    int n = graph.size();
    vi ordering = KhanTopoSort(graph);
    for (int i = 0; i < n; ++i) {
        int at = ordering[i];
        vb visited(n);
        for (int adj : graph[at]) {
            visited[adj] = true;
        }
        for (int j = i + 1; j < n; ++j) {
            if (not visited[ordering[j]]) {
                cout << at << '-' << ordering[j] << endl;
            }
        }
    }
}

int main() { TimeMeasure _;
    Graph graph(6);
    AddDirectedEdge(graph, 5, 2);
    AddDirectedEdge(graph, 5, 0);
    AddDirectedEdge(graph, 4, 0);
    AddDirectedEdge(graph, 4, 1);
    AddDirectedEdge(graph, 2, 3);
    AddDirectedEdge(graph, 3, 1);
    cout << MaximumEdgesToAdd(graph) << endl; // 9
    MaximumEdgesToPrint(graph);
    /*
5-4
5-3
5-1
4-2
4-3
2-1
2-0
3-0
1-0
*/
}

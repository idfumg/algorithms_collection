#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void FindPaths(const Graph& graph, const int from, const int to) {
    int n = size(graph);
    deque<vector<int>> q;
    q.push_back({from});
    vb visited(n);
    while (not q.empty()) {
        vi path = q.front(); q.pop_front();
        visited[path.back()] = true;
        for (const auto& edge : graph.edges(path.back())) {
            if (not visited[edge.to]) {
                vi newpath = path; newpath.push_back(edge.to);
                if (newpath.back() == to) {
                    cout << newpath << endl;
                }
                else {
                    q.push_back(newpath);
                }
            }
        }
    }
}

int main() { TimeMeasure _;
    Graph graph(4);
    graph.addDirectedEdge(0, 3);
    graph.addDirectedEdge(0, 1);
    graph.addDirectedEdge(0, 2);
    graph.addDirectedEdge(1, 3);
    graph.addDirectedEdge(2, 0);
    graph.addDirectedEdge(2, 1);
    FindPaths(graph, 2, 3);
}

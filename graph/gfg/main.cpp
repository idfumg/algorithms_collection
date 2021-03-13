#include "../../template.hpp"

using Graph = vvi;

[[maybe_unused]] void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    assert(cost != INF);
    graph[from].push_back(to);
    graph[to].push_back(from);
    // graph.push_back({from, to});
    // graph[from].push_back({to, cost});
    // graph[to].push_back({from, cost});
    // graph.push_back({from, to, cost});
    // graph[from][to] = cost;
    // graph[to][from] = cost;
}


int main() { TimeMeasure _;

}

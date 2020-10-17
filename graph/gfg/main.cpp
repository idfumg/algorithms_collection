#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    //graph[from].push_back(to);
    //graph[to].push_back(from);
    //graph.push_back({from, to});
    //graph[from].push_back({to, cost});
    graph.push_back({from, to, cost});
}


int main() { TimeMeasure _;

}

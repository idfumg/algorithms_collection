#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"


int main() { TimeMeasure _;
    const int n = 5;
    Graph graph(n);
    graph.addDirectedEdge(0, 1);
    graph.addDirectedEdge(0, 4);
    graph.addDirectedEdge(0, 3);
    graph.addDirectedEdge(2, 0);
    graph.addDirectedEdge(3, 2);
    graph.addDirectedEdge(4, 1);
    graph.addDirectedEdge(4, 3);
    graph.display();
    cout << endl;
    graph.transpose();
    graph.display();
}

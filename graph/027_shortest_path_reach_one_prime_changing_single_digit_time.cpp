#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

vi SieveOfEratosthenes(const int n) {
    vb prime(n + 1, true);
    for (int p = 2; p * p <= n; ++p) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    vi primes;
    for (int i = 1000; i <= n; ++i) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

bool DiffersByASingleDigit(const int num1, const int num2) {
    const auto a = to_string(num1);
    const auto b = to_string(num2);
    assert(size(a) == size(b));
    assert(size(a) == 4);
    int count = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            ++count;
        }
    }
    return count == 1;
}

Graph CreateGraph(const vi& primes) {
    const int n = size(primes);
    Graph graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (DiffersByASingleDigit(primes[i], primes[j])) {
                graph.addUndirectedEdge(i, j);
            }
        }
    }
    return graph;
}

int bfs(const Graph& graph, const int from, const int to) {
    int n = graph.size();
    deque<int> q;
    q.push_back(from);
    vb visited(n);
    vi dist(n, INF);
    dist[from] = 0;
    while (not q.empty()) {
        int node = q.front(); q.pop_front();
        visited[node] = true;
        for (const auto& edge : graph.edges(node)) {
            dist[edge.to] = min(dist[edge.to], dist[node] + 1);
            if (not visited[edge.to]) {
                q.push_back(edge.to);
            }
            if (edge.to == to) {
                return dist[edge.to];
            }
        }
    }
    return dist[to];
}

int ShortestPath(const int a, const int b) {
    const vi primes = SieveOfEratosthenes(9999);
    const Graph graph = CreateGraph(primes);
    int from = INF, to = INF;
    for (int i = 0; i < size(primes); ++i) {
        if (primes[i] == a) {
            from = i;
        }
        if (primes[i] == b) {
            to = i;
        }
    }
    return bfs(graph, from, to);
}

int main() { TimeMeasure _;
    cout << ShortestPath(1033, 8179) << endl;
    cout << ShortestPath(1373, 8017) << endl;
    cout << ShortestPath(1033, 1033) << endl;
}

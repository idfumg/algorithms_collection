#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back(to);
    // graph[to].push_back(from);
    // graph.push_back({from, to});
    // graph[from].push_back({to, cost});
    // graph[to].push_back({from, cost});
    // graph.push_back({from, to, cost});
    // graph[from][to] = cost;
    // graph[to][from] = cost;
}

vi GetPrimes(int from, int to) {
    vb isprime(to + 1, true);
    for (int p = 2; p * p <= to; ++p) {
        if (isprime[p]) {
            for (int i = p * p; i <= to; i += p) {
                isprime[i] = false;
            }
        }
    }
    vi primes;
    for (int i = from; i <= to; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

bool IsEdge(int a, int b) {
    int count = 0;
    for (; a > 0 and b > 0; a /= 10, b /= 10) {
        count += (a % 10) != (b % 10);
    }
    return count == 1;
}

vvi GetGraph(vi primes) {
    int n = primes.size();
    vvi graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (IsEdge(primes[i], primes[j])) {
                graph[i].push_back(j);
            }
        }
    }
    return graph;
}

int bfs(int from, int to, vi primes, vvi graph) {
    int n = graph.size();

    deque<int> q;
    q.push_back(0);

    vb visited(n);

    vi dist(n, INF);
    dist[0] = 0;

    while (not q.empty()) {
        int at = q.front(); q.pop_front();
        visited[at] = true;
        for (int adj : graph[at]) {
            if (not visited[adj]) {
                dist[adj] = min(dist[adj], dist[at] + 1);
                q.push_back(adj);
            }
        }
    }

    return dist[n - 1];
}

int MinSteps(int a, int b) {
    vi primes = GetPrimes(a, b);
    vvi graph = GetGraph(primes);
    return bfs(a, b, primes, graph);
}

int main() { TimeMeasure _;
    cout << MinSteps(1033, 8179) << endl; // 6
    cout << MinSteps(1373, 8017) << endl; // 7
    cout << MinSteps(1033, 1033) << endl; // 0
}

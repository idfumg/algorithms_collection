#include "../../template.hpp"

using Graph = vvi;

vi GenPrimes(int from, int to) {
    vi prime(to + 1, true);
    for (int p = 2; p * p <= to; ++p) {
        if (prime[p]) {
            for (int i = p * p; i <= to; i += p) {
                prime[i] = false;
            }
        }
    }
    vi primes;
    for (int p = from; p <= to; ++p) {
        if (prime[p]) {
            primes.push_back(p);
        }
    }
    return primes;
}

bool IsValid(int x, int y) {
    int count = 0;
    while (x > 0 and y > 0) {
        int remx = x % 10;
        int remy = y % 10;
        x /= 10;
        y /= 10;
        count += remx != remy ? 1 : 0;
    }
    return count == 1;
}

Graph GenGraph(const vi& primes) {
    int n = size(primes);
    Graph graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (IsValid(primes[i], primes[j])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    return graph;
}

int bfs(const Graph& graph, int x, int y, const vi& primes) {
    int n = size(primes);
    int from = distance(begin(primes), find(begin(primes), end(primes), x));

    queue<int> q;
    q.push(from);

    vi dist(n, -1);
    dist[from] = 0;

    while (not q.empty()) {
        int at = q.front(); q.pop();
        if (primes[at] == y) {
            return dist[at];
        }
        for (int adj : graph[at]) {
            if (dist[adj] == -1) {
                q.push(adj);
                dist[adj] = dist[at] + 1;
            }
        }
    }
    return -1;
}

int MinSteps(int x, int y) {
    const int from = pow(10, static_cast<int>(log10(x)));
    const auto primes = GenPrimes(from, y);
    const auto graph = GenGraph(primes);
    return bfs(graph, x, y, primes);
}

int main() { TimeMeasure _;
    cout << MinSteps(1033, 8179) << endl;
    cout << MinSteps(1373, 8017) << endl;
    cout << MinSteps(1033, 1033) << endl;
}

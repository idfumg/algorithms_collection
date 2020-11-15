//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INF static_cast<int32_t>(1e9)

using ll = int64_t;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;

[[maybe_unused]] static const auto ___x = [](){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::boolalpha);};

void dfs(vvi& graph, int current, int sum, int k, int& count, vb& visited, int at) {
    if (current == 0) {
        if (sum == k and at == 0) {
            ++count;
        }
        return;
    }

    int n = graph.size();
    for (int adj = 0; adj < n; ++adj) {
        if (graph[at][adj] and not visited[adj]) {
            visited[adj] = true;
            dfs(graph, current - 1, sum + graph[at][adj], k, count, visited, adj);
            visited[adj] = false;
        }
    }
}

int main() {
    int n; cin >> n;
    int k; cin >> k;
    vvi graph(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int count = 0;
    vb visited(n);
    dfs(graph, n, 0, k, count, visited, 0);
    cout << count << endl;
}

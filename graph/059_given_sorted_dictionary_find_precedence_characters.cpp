#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

int dfs(vvi& graph, vi& ordering, vb& visited, int at, int pos) {
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            pos = dfs(graph, ordering, visited, adj, pos);
        }
    }
    ordering[pos] = at;
    return pos - 1;
}

vi TopologicalSort(vvi& graph, int n) {
    vi ordering(n);
    vb visited(n);
    int pos = n - 1;
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            pos = dfs(graph, ordering, visited, i, pos);
        }
    }
    return ordering;
}

void PrintOrder(const vector<string>& words, int n) {
    vvi graph(n);
    for (int i = 0; i < n - 1; ++i) {
        const auto& word1 = words[i];
        const auto& word2 = words[i + 1];
        for (int j = 0; j < min(word1.size(), word2.size()); ++j) {
            if (word1[j] != word2[j]) {
                graph[word1[j] - 'a'].push_back(word2[j] - 'a');
                break;
            }
        }
    }
    vi ordering = TopologicalSort(graph, n);
    debugn(ordering);
    for (int i = 0; i < n; i++) {
        cout << static_cast<char>(ordering[i] + 'a') << ' ';
    }
    cout << endl;
}

int main() { TimeMeasure _;
    PrintOrder({"caa", "aaa", "aab"}, 3); // c a b
    PrintOrder({"baa", "abcd", "abca", "cab", "cad"}, 4); // b d a c
}

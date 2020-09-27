#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

bool IsTransitionAllowed(const string& a, const string& b) {
    int m = a.size(), n = b.size(), count = 0;
    if (m != n) return false;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            ++count;
        }
    }
    return count == 1;
}

Graph CreateGraph(const vector<string>& words) {
    int n = words.size();
    Graph graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (IsTransitionAllowed(words[i], words[j])) {
                AddEdge(graph, i, j);
            }
        }
    }
    return graph;
}

int bfs(Graph& graph, int from, int to) {
    int n = graph.size();
    vi dist(n);
    dist[from] = 0;
    vb visited(n);
    qi q;
    q.push(from);
    while (not q.empty()) {
        int at = q.front(); q.pop();
        visited[at] = true;
        if (at == to) break;
        for (int adj : graph[at]) {
            if (not visited[adj]) {
                dist[adj] = dist[at] + 1;
                q.push(adj);
            }
        }
    }
    return dist[to];
}

int ShortestChainLen(vector<string>& words, const string& a, const string& b) {
    words.push_back(a);
    Graph graph = CreateGraph(words);
    int n = graph.size(), from = 0, to = 0;
    for (int i = 0; i < n; ++i) {
        if (a == words[i]) from = i;
        if (b == words[i]) to = i;
    }
    return bfs(graph, from, to);
}

int main() { TimeMeasure _;
    {
        vector<string> words = {
            "poon",
            "plee",
            "same",
            "poie",
            "plie",
            "poin",
            "plea",
        };
        cout << ShortestChainLen(words, "toon", "plea") << endl;
    }
    {
        vector<string> words = {
            "hot",
            "pot",
            "pod",
            "dod",
            "dog",
            "hog",
            "hig",
            "hit",
        };
        cout << ShortestChainLen(words, "hot", "hit") << endl;
    }
}

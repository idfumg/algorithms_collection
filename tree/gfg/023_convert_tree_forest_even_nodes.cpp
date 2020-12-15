#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void inorder(Node* root) {
    if (not root) return;
    inorder(root->left);
    cout << root->value << ' ';
    inorder(root->right);
}

void AddEdge(vvi& graph, int from, int to) {
    graph[from - 1].push_back(to - 1);
    graph[to - 1].push_back(from - 1);
}

int dfs(vvi graph, vb& visited, int at, int& ans) {
    int count = 0;

    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            int current = dfs(graph, visited, adj, ans);
            if (current % 2 == 0) {
                ++ans;
            }
            else {
                count += current;
            }
        }
    }

    return count + 1;
}

int EdgesToRemove(vvi graph, int from) {
    int n = graph.size();
    int ans = 0;
    vb visited(n);
    dfs(graph, visited, from, ans);
    return ans;
}

int main() { TimeMeasure _; __x();
    int n = 10;
    vvi graph(n);

    AddEdge(graph, 1, 3);
    AddEdge(graph, 3, 1);
    AddEdge(graph, 1, 6);
    AddEdge(graph, 6, 1);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 2, 1);
    AddEdge(graph, 3, 4);
    AddEdge(graph, 4, 3);
    AddEdge(graph, 6, 8);
    AddEdge(graph, 8, 6);
    AddEdge(graph, 2, 7);
    AddEdge(graph, 7, 2);
    AddEdge(graph, 2, 5);
    AddEdge(graph, 5, 2);
    AddEdge(graph, 4, 9);
    AddEdge(graph, 9, 4);
    AddEdge(graph, 4, 10);
    AddEdge(graph, 10, 4);

    cout << EdgesToRemove(graph, 0) << endl;
}

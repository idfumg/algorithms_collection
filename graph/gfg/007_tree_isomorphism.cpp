#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

struct Tree {
    int value;
    vector<Tree*> nodes;
    Tree(int value) : value(value), nodes() {}
};

Tree* MakeRoot(Graph graph, Tree* root, Tree* parent) {
    for (int adj : graph[root->value]) {
        if (parent and parent->value == adj) continue;
        Tree* child = MakeRoot(graph, new Tree(adj), root);
        root->nodes.push_back(child);
    }
    return root;
}

Tree* RootTree(Graph graph, int node) {
    Tree* root = new Tree(node);
    return MakeRoot(graph, root, nullptr);
}

string EncodeTree(Tree* root) {
    if (not root) return "";
    vector<string> encodings;
    for (Tree* node : root->nodes) {
        encodings.push_back(EncodeTree(node));
    }
    sort(encodings.begin(), encodings.end());
    string ans;
    for (const string& encoding : encodings) {
        ans += encoding;
    }
    return "(" + ans + ")";
}

vi FindTreeCenters(Graph graph) {
    int n = graph.size();

    vi degree(n);
    for (int at = 0; at < n; ++at) {
        degree[at] = graph[at].size();
    }

    deque<int> leaves;
    for (int at = 0; at < n; ++at) {
        if (degree[at] <= 1) {
            leaves.push_back(at);
            degree[at] = 0;
        }
    }

    int total = leaves.size();
    while (not leaves.empty() and total < n) {
        int at = leaves.front(); leaves.pop_front();
        for (int adj : graph[at]) {
            if (--degree[adj] == 1) {
                leaves.push_back(adj);
            }
        }
        total += 1;
    }

    vi centers;
    for (int at = 0; at < n; ++at) {
        if (degree[at] > 0) {
            centers.push_back(at);
        }
    }
    return centers;
}

bool TreesAreIsomorphic(Graph graph1, Graph graph2) {
    const auto centers1 = FindTreeCenters(graph1);
    const auto centers2 = FindTreeCenters(graph2);
    if (centers1.empty()) return false;
    const auto root1 = RootTree(graph1, centers1[0]);
    const auto encode1 = EncodeTree(root1);
    for (const auto& center : centers2) {
        const auto root2 = RootTree(graph2, center);
        const auto encode2 = EncodeTree(root2);
        if (encode1 == encode2) {
            return true;
        }
    }
    return false;
}

int main() { TimeMeasure _;
    Graph tree1(5);
    AddEdge(tree1, 2, 0);
    AddEdge(tree1, 3, 4);
    AddEdge(tree1, 2, 1);
    AddEdge(tree1, 2, 3);

    Graph tree2(5);
    AddEdge(tree2, 1, 0);
    AddEdge(tree2, 2, 4);
    AddEdge(tree2, 1, 3);
    AddEdge(tree2, 1, 2);

    if (!TreesAreIsomorphic(tree1, tree2)) {
        cout << "Oops, these tree should be isomorphic!" << endl;
    }

    Graph tree3(10);
    AddEdge(tree3, 0, 2);
    AddEdge(tree3, 0, 1);
    AddEdge(tree3, 0, 3);
    AddEdge(tree3, 2, 6);
    AddEdge(tree3, 2, 7);
    AddEdge(tree3, 1, 4);
    AddEdge(tree3, 1, 5);
    AddEdge(tree3, 5, 9);
    AddEdge(tree3, 3, 8);

    Tree* root3 = RootTree(tree3, 0);

    if (EncodeTree(root3) != "(((())())(()())(()))") {
        cout << ("Tree encoding is wrong: " + EncodeTree(root3)) << endl;
    }
}

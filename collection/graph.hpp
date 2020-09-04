#include <vector>

struct Edge {
    int from;
    int to;
    int cost;
};

class Graph {
private:
    std::vector<std::vector<Edge>> m_graph;

public:
    Graph(const int n) {
        m_graph.resize(n);
    }

    void addDirectedEdge(const int from, const int to, const int cost = 0) {
        m_graph.at(from).push_back({from, to, cost});
    }

    void addUndirectedEdge(const int from, const int to, const int cost = 0) {
        addDirectedEdge(from, to, cost);
        addDirectedEdge(to, from, cost);
    }

    decltype(auto) edges(const int at) const noexcept {
        return m_graph.at(at);
    }

    decltype(auto) edges() const noexcept {
        return m_graph;
    }

    std::size_t size() const noexcept {
        return m_graph.size();
    }

    decltype(m_graph.cbegin()) begin() const noexcept {
        return m_graph.cbegin();
    }

    decltype(m_graph.cend()) end() const noexcept {
        return m_graph.cend();
    }

    decltype(m_graph.begin()) begin() noexcept {
        return m_graph.begin();
    }

    decltype(m_graph.end()) end() noexcept {
        return m_graph.end();
    }
};

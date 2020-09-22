#include <vector>
#include <iostream>

struct Edge {
    int from;
    int to;
    int cost;
};

class Graph {
private:
    std::vector<std::vector<Edge>> m_graph;
    int start = 0;

public:
    Graph(const int n, const int start_ = 0) : m_graph(n + start_), start(start_) {

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

    void transpose() noexcept {
        std::vector<std::vector<Edge>> temp(m_graph.size());
        for (const auto& allEdges : edges()) {
            for (const auto& edge : allEdges) {
                temp.at(edge.to).push_back({edge.to, edge.from, edge.cost});
            }
        }
        m_graph = temp;
    }

    void display() const noexcept {
        for (int i = 0; i < static_cast<int>(m_graph.size()); ++i) {
            if (not edges(i).empty()) {
                std::cout << i << ": ";
                for (const auto& edge : edges(i)) {
                    std::cout << edge.to << ' ';
                }
                std::cout << '\n';
            }
        }
    }
};

namespace std {

std::size_t size(const Graph& graph) noexcept {
    return graph.size();
}

} // namespace std

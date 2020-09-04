#define IS_TEST 1

#if IS_TEST == 1
#include "../headers.hpp"
#else
#include <bits/stdc++.h>
#endif

// https://codeforces.com/contest/59/problem/E

using namespace std;

struct Vertex final {
    int x{-1};
    int y{-1};

    bool operator==(const Vertex& vertex) const noexcept {
        return x == vertex.x and y == vertex.y;
    }
};

namespace std {

template<>
struct hash<Vertex> {
    size_t operator()(const Vertex& v) const noexcept {
        uint64_t h = 0;

        h <<= 32;
        h ^= hash<int32_t>()(v.x);
        h = hash<int64_t>()(h);

        h <<= 32;
        h ^= hash<int32_t>()(v.y);
        h = hash<int64_t>()(h);

        return h;
    }
};

} // namespace std

void bfs(
    const vector<Vertex>& sources,
    const int final_city,
    const unordered_map<Vertex, vector<Vertex>>& G)
{
    unordered_map<Vertex, Vertex> p;
    vector<vector<bool>> visited(final_city + 1, vector<bool>(final_city + 1));
    queue<Vertex> q;

    for (const auto& vertex : sources) {
        if (vertex.y == final_city) {
            printf("1\n%d %d\n", vertex.x, vertex.y);
            return;
        }
        q.push({vertex});
        visited[vertex.x][vertex.y] = true;
    }

    while (not q.empty()) {
        const Vertex v = q.front();
        q.pop();

        if (G.count(v)) {
            for (const auto& vertex : G.at(v)) {
                if (visited[vertex.x][vertex.y]) {
                    continue;
                }
                visited[vertex.x][vertex.y] = true;
                q.push(vertex);
                p[vertex] = v;

                if (vertex.y == final_city) {
                    vector<Vertex> res;
                    for (Vertex v = vertex; v.x != -1; v = p[v]) {
                        res.push_back(v);
                    }
                    printf("%lu\n", res.size());
                    for (auto it = res.crbegin(); it != res.crend(); ++it) {
                        if (it == res.crbegin()) {
                            printf("%d %d ", it->x, it->y);
                        }
                        else {
                            printf("%d ", it->y);
                        }
                    }
                    printf("\n");
                    return;
                }
            }
        }
    }

    printf("-1\n");
}

void solve(istream& ss) {
    int cities_num, roads_num, forbidden_num;
    ss >> cities_num >> roads_num >> forbidden_num;
    const int final_city = cities_num;

    vector<vector<int>> cities(cities_num + 1);
    int from, to;
    for (int i = 0; i < roads_num; ++i) {
        ss >> from >> to;
        cities[from].push_back(to);
        cities[to].push_back(from);
    }

    vector<tuple<int, int, int>> forbids(forbidden_num + 1);
    int first, second, third;
    for (int i = 0; i < forbidden_num; ++i) {
        ss >> first >> second >> third;
        forbids[i] = {first, second, third};
    }
    sort(forbids.begin(), forbids.end());

    unordered_map<Vertex, vector<Vertex>> G;
    vector<Vertex> S;
    G.reserve(32768);
    G.max_load_factor(0.25);
    for (int i = 0; i < cities.size(); ++i) {
        for (int j : cities.at(i)) {
            if (i == 1) {
                S.push_back({i, j});
            }
            for (int k : cities.at(j)) {
                if (k != 1 and j != 1) {
                    const auto t = make_tuple(i, j, k);
                    if (not binary_search(forbids.begin(), forbids.end(), t)) {
                        G[{i, j}].push_back({j, k});
                    }
                }
            }
        }
    }

    bfs(S, final_city, G);
}

void test() {
        {
        const char data[] = R"(4 4 1
1 2
2 3
3 4
1 3
1 3 4)";
        istringstream ss(data);
        solve(ss);
    }
    {
        const char data[] = R"(4 4 1
1 2
2 3
3 4
1 3
1 4 3)";
        istringstream ss(data);
        solve(ss);
    }

    {
        const char data[] = R"(3 1 0
1 2)";
        istringstream ss(data);
        solve(ss);
    }

    {
        const char data[] = R"(4 4 2
1 2
2 3
3 4
1 3
1 2 3
1 3 4)";
        istringstream ss(data);
        solve(ss);
    }
    {
        const char data[] = R"(2 1 0
1 2)";
        istringstream ss(data);
        solve(ss);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#if IS_TEST == 1
    test();
#else
    solve(cin);
#endif

    return 0;
}

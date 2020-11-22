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
using pi = pair<int, int>;

[[maybe_unused]] static const auto ___x = [](){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::boolalpha);};

static const vvi directions = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

bool IsValid(
    const vector<vector<char>>& arr,
    const int i,
    const int j)
{
    const int m = arr.size();
    const int n = arr[0].size();
    return i >= 0 and j >= 0 and i < m and j < n and arr[i][j] != '#';
}

struct Item {
    int i;
    int j;
    int w;
    bool operator<(const Item& rhs) const { return w > rhs.w; }
};

int dijkstra(
    const vector<vector<char>>& arr,
    vector<vector<pi>>& positions,
    const pi& from,
    const pi& to)
{
    queue<Item> queue;
    queue.push({from.first, from.second, 0});

    const int m = arr.size();
    const int n = arr[0].size();

    vvi dist(m, vi(n, INF));
    dist[from.first][from.second] = 0;

    vvb visited(m, vb(n, false));

    while (not queue.empty()) {
        const Item at = queue.front(); queue.pop();

        if (at.i == to.first and at.j == to.second) {
            break;
        }

        const int i = at.i;
        const int j = at.j;

        visited[i][j] = true;

        if (arr[i][j] != '.' and arr[i][j] != 'S') {
            for (const auto& position : positions.at(arr[i][j] - 'a')) {
                const int x = position.first;
                const int y = position.second;
                if (not visited[x][y]) {
                    int cost = dist[i][j] + 1;
                    if (cost < dist[x][y]) {
                        dist[x][y] = min(dist[x][y], cost);
                        if (pi{x, y} == to) {
                            break;
                        }
                        queue.push({x, y, cost});
                    }
                }
            }
            positions.at(arr[i][j] - 'a').clear();
        }

        for (const auto& direction : directions) {
            const int x = i + direction[0];
            const int y = j + direction[1];
            if (IsValid(arr, x, y) and not visited[x][y]) {
                int cost = dist[i][j] + 1;
                if (cost < dist[x][y]) {
                    dist[x][y] = min(dist[x][y], cost);
                    if (pi{x, y} == to) {
                        break;
                    }
                    queue.push({x, y, cost});
                }
            }
        }
    }

    return dist[to.first][to.second] == INF ? -1 : dist[to.first][to.second];
}

int main() {
    int m, n;
    cin >> m >> n;

    int starti = 0, startj = 0;
    int stopi = 0, stopj = 0;

    vector<vector<char>> arr(m, vector<char>(n));
    vector<vector<pi>> positions(27);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                starti = i;
                startj = j;
            }
            else if (arr[i][j] == 'G') {
                stopi = i;
                stopj = j;
            }
            else if (arr[i][j] != '#' and arr[i][j] != '.') {
                positions[arr[i][j] - 'a'].push_back({i, j});
            }
        }
    }

    cout << dijkstra(arr, positions, {starti, startj}, {stopi, stopj}) << endl;
}

#include "../../template.hpp"

struct Job {
    char id;
    int deadline;
    int profit;
    bool operator<(const Job& rhs) const { return profit > rhs.profit; }
};

using Jobs = vector<Job>;

int Find(vi& parent, int i) {
    if (parent[i] == -1) return i;
    return parent[i] = Find(parent, parent[i]);
}

void Union(vi& parent, int node, int root) {
    parent[node] = root;
}

void JobScheduling(Jobs jobs) {
    int n = 0;
    for (const auto& job : jobs) {
        n = max(n, job.deadline);
    }
    vi parent(n + 1, -1);
    sort(jobs.begin(), jobs.end());
    int total = 0;
    for (const auto& job : jobs) {
        if (int root = Find(parent, job.deadline); root > 0) {
            Union(parent, root, Find(parent, root - 1));
            total += job.profit;
        }
    }
    cout << total << endl;
}

int main() { TimeMeasure _; __x();
    {
        Jobs jobs = {
            {'a', 2, 100},
            {'b', 1, 19},
            {'c', 2, 27},
            {'d', 1, 25},
            {'e', 3, 15},
        };
        JobScheduling(jobs); // 142
    }
    {
        Jobs jobs = {
            {'a', 5, 200},
            {'b', 3, 180},
            {'c', 3, 190},
            {'d', 2, 300},
            {'e', 4, 120},
            {'f', 2, 100},
        };
        JobScheduling(jobs); // 990
    }
}

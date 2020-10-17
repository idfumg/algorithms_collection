#include "../../template.hpp"

struct Job {
    char id;
    int deadline;
    int profit;
    bool operator<(const Job& rhs) const { return profit > rhs.profit; }
};

using Jobs = vector<Job>;

int GetMaximumDeadlineSlotsCount(Jobs& jobs) {
    int res = -INF;
    for (Job& job : jobs) {
        res = max(res, job.deadline);
    }
    return res;
}

int Find(vi& parent, int i) {
    if (parent[i] == -1) return i;
    return parent[i] = Find(parent, parent[i]);
}

void Union(vi& parent, int i, int j) {
    parent[j] = i;
}

void JobScheduling(Jobs& jobs) {
    int n = GetMaximumDeadlineSlotsCount(jobs), total = 0;
    vi parent(n + 1, -1);
    sort(jobs);
    for (Job& job : jobs) {
        int slot = Find(parent, job.deadline);
        if (slot > 0) {
            Union(parent, Find(parent, slot - 1), slot);
            cout << job.id << ' ';
            total += job.profit;
        }
    }
    cout << ':' << ' ' << total << '\n';
}

int main() { TimeMeasure _;
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

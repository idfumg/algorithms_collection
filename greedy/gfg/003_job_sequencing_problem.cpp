#include "../../template.hpp"

struct Job {
    char id;
    int deadline;
    int profit;
    bool operator<(const Job& rhs) const { return profit > rhs.profit; }
};

using Jobs = vector<Job>;

void JobScheduling(Jobs& jobs) {
    int n = jobs.size();
    vb slot(n);
    vi result(n, -1);
    sort(jobs);

    for (int i = 0; i < n; ++i) {
        for (int j = min(jobs[i].deadline, n) - 1; j >= 0; --j) {
            if (not slot[j]) {
                slot[j] = true;
                result[j] = i;
                break;
            }
        }
    }

    int total = 0;
    for (int i = 0; i < n; ++i) {
        if (slot[i]) {
            cout << jobs[result[i]].id << ' ';
            total += jobs[result[i]].profit;
        }
    }
    cout << ':' << ' ' << total << '\n';
}

int GetMaxDeadline(Jobs& jobs) {
    int n = jobs.size(), ans = -INF;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, jobs[i].deadline);
    }
    return ans;
}

void JobScheduling2(Jobs& jobs) {
    sort(jobs);
    int maxdeadline = GetMaxDeadline(jobs);
    vi slot(maxdeadline + 1, 0);
    for (Job& job : jobs) {
        for (int i = job.deadline; i > 0; --i) {
            if (not slot[i]) {
                slot[i] = job.profit;
                break;
            }
        }
    }
    cout << accumulate(slot.begin(), slot.end(), 0) << '\n';
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
        JobScheduling2(jobs); // 142
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
        JobScheduling2(jobs); // 990
    }
}

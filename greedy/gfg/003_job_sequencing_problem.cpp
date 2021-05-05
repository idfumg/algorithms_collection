#include "../../template.hpp"

struct Job {
    char id;
    int deadline;
    int profit;
};

using Jobs = vector<Job>;

void JobScheduling(Jobs jobs) {
    int n = 0;
    for (const auto& job : jobs) {
        n = max(n, job.deadline);
    }
    vi deadline(n + 1, 0);
    sort(jobs.begin(), jobs.end(), [](auto a, auto b){return a.profit > b.profit;});
    for (const auto& job : jobs) {
        for (int idx = job.deadline; idx > 0; --idx) {
            if (deadline[idx] == 0) {
                deadline[idx] = job.profit;
                break;
            }
        }
    }
    cout << reduce(deadline.begin(), deadline.end(), 0) << endl;
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
        JobScheduling(jobs); // 134
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

#include "../../template.hpp"

struct Job {
    char id;
    int deadline;
    int profit;
};

using Jobs = vector<Job>;

void JobScheduling(Jobs jobs) {
    sort(jobs.begin(), jobs.end(), [](Job a, Job b){return a.profit > b.profit;});
    int maxdeadline = 1;
    for (Job job : jobs) {
        if (job.deadline > maxdeadline) {
            maxdeadline = job.deadline;
        }
    }
    vi slots(maxdeadline + 1, 0);
    for (Job job : jobs) {
        int idx = job.deadline;
        while (slots[idx] != 0 and idx != 0) {
            --idx;
        }
        if (idx > 0) {
            slots[idx] = job.profit;
        }
    }
    int total = 0;
    for (int profit : slots) {
        if (profit > 0) {
            total += profit;
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

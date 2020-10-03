#include "../template.hpp"

struct Job {
    int start;
    int stop;
};

void MaxNumberOfActivities(vi& start, vi& finish) {
    int n = start.size();
    vector<Job> jobs;
    for (int i = 0; i < n; ++i) {
        jobs.push_back({start[i], finish[i]});
    }
    sort(jobs.begin(), jobs.end(), [](Job a, Job b){return a.stop < b.start;});
    int i = 0;
    cout << i << ' ';
    for (int j = 1; j < n; ++j) {
        if (jobs[j].start >= jobs[i].stop) {
            cout << j << ' ';
            i = j;
        }
    }
}

int main() { TimeMeasure _;
    vi start =  {1, 3, 0, 5, 8, 5};
    vi finish = {2, 4, 6, 7, 9, 9};
    MaxNumberOfActivities(start, finish);
}

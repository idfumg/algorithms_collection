#include "../../template.hpp"

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
    sort(jobs.begin(), jobs.end(), [](Job a, Job b){return a.stop < b.stop;});
    int i = 0;
    cout << i << ' ';
    for (int j = 1; j < n; ++j) {
        if (jobs[j].start >= jobs[i].stop) {
            cout << j << ' ';
            i = j;
        }
    }
    cout << '\n';
}

void MaxNumberOfActivities2(vi& start, vi& finish) {
    int n = start.size();
    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j){return finish[i] < finish[j];});
    int last = 0;
    cout << last << ' ';
    for (int i = 1; i < n; ++i) {
        if (finish[idx[last]] <= start[idx[i]]) {
            cout << i << ' ';
            last = i;
        }
    }
    cout << '\n';
}

void MaxNumberOfActivities3(vi start, vi finish) {
    int n = start.size();
    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j){return finish[i] < finish[j];});

    int last = idx[0];
    cout << last << ' ';
    for (int i = 1; i < n; ++i) {
        int j = idx[i];
        if (start[j] >= finish[last]) {
            last = j;
            cout << last << ' ';
        }
    }
    cout << '\n';
}

int main() { TimeMeasure _;
    vi start =  {3, 8, 0, 5, 5, 1};
    vi finish = {4, 9, 6, 7, 9, 2};
    // MaxNumberOfActivities(start, finish); // 0 1 3 4
    // MaxNumberOfActivities2(start, finish); // 0 1 3 4
    MaxNumberOfActivities3(start, finish); // 5 0 3 1
}

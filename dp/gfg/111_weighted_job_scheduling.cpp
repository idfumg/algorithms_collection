#include "../../template.hpp"

struct Job {
    int start;
    int stop;
    int profit;
};

int rec(vector<Job>& jobs, int n, int prevstart) {
    if (n == 0) return 0;
    if (jobs[n - 1].stop <= prevstart) {
        return max(rec(jobs, n - 1, prevstart),
                   rec(jobs, n - 1, jobs[n - 1].start) + jobs[n - 1].weight);
    }
    return rec(jobs, n - 1, prevstart);
}

// Straightforward recursive algorithm.
// Choose job which is appropriate regarding to prev one.
int rec(vector<Job>& jobs) {
    sort(jobs);
    return rec(jobs, jobs.size(), INF);
}

// Recursive algorithm with greedy approach.
int rec(vector<Job>& jobs, int n) {
    if (n < 0) return 0;
    const auto a = rec(jobs, n - 1);
    int nonconflict = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (jobs[n].start >= jobs[i].stop) {
            nonconflict = i;
            break;
        }
    }
    const auto b = rec(jobs, nonconflict) + jobs[n].profit;
    return max(a, b);
}

int rec(vector<Job> jobs) { // Recursive with Greedy
    sort(jobs.begin(), jobs.end(), [](auto a, auto b){return a.stop < b.stop;});
    return rec(jobs, jobs.size() - 1);
}

int tab(vector<Job> jobs) { // with Greedy
    sort(jobs.begin(), jobs.end(), [](auto a, auto b){return a.stop < b.stop;});
    const int n = jobs.size();
    vi dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        int nonconflict = n - 1;
        for (int j = i - 1; j > 0; --j) {
            if (jobs[i - 1].start >= jobs[j - 1].stop) {
                nonconflict = j;
                break;
            }
        }
        const auto a = dp[i - 1];
        const auto b = (nonconflict>0 ? dp[nonconflict] : 0) + jobs[i - 1].profit;
        dp[i] = max(a, b);
    }
    return dp[n];
}

int tab2(vector<Job> jobs) { // with LIS
    sort(jobs.begin(), jobs.end(), [](auto a, auto b){return a.stop < b.stop;});
    int n = jobs.size(), maxi = -INF, maxipos = 0;
    vi dp(n), prev(n, -1);
    dp[0] = jobs[0].profit;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (jobs[i].start >= jobs[j].stop) {
                if (dp[j] + jobs[i].profit > dp[i]) {
                    prev[i] = j;
                }
                dp[i] = max(dp[i], dp[j] + jobs[i].profit);
                if (maxi < dp[i]) {
                    maxi = dp[i];
                    maxipos = i;
                }
            }
        }
    }
    vector<int> seq;
    for (int at = maxipos; at != -1; at = prev[at]) {
        seq.push_back(jobs[at].profit);
    }
    reverse(seq);
    cout << "Selected jobs profits: " << seq << '\n';
    return maxi;
}

int binary_search(const vector<Job>& jobs, const int idx) {
    int low = 0, high = idx - 1;
    while (low <= high) {
        const int mid = (high + low) / 2;
        if (jobs[mid].stop <= jobs[idx].start) {
            if (mid + 1 != idx && jobs[mid + 1].stop <= jobs[idx].start) {
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int tab3(vector<Job> jobs) { // with binary search
    sort(jobs.begin(), jobs.end(), [](auto a, auto b){return a.stop < b.stop;});
    const int n = jobs.size();
    vi dp(n);
    dp[0] = jobs[0].profit;
    for (int i = 1; i < n; ++i) {
        const auto idx = binary_search(jobs, i);
        dp[i] = max(dp[i - 1], (idx == -1 ? 0 : dp[idx]) + jobs[i].profit);
    }
    return dp[n - 1];
}

int main() { TimeMeasure _; __x();
    vector<Job> jobs = {
        {1, 2, 50},
        {3, 5, 20},
        {6, 19, 100},
        {2, 100, 200}
    };

    cout << rec(jobs) << endl;
    cout << tab(jobs) << endl;
    cout << tab2(jobs) << endl;
    cout << tab3(jobs) << endl;
}

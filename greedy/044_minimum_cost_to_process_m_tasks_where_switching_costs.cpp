#include "../template.hpp"

bool Assign(
    vi& assigned,
    const unordered_map<int, int>& frequency,
    const unordered_map<int, di>& position,
    const int param)
{
    int minidx = INF, minfrequency = INF, maxpos = -INF, n = assigned.size();

    for (int i = 0; i < n; ++i) {
        int& task = assigned[i];

        if (task == param) {
            return false;
        }

        if (task == -1) {
            minidx = i;
            minfrequency = -INF;
            maxpos = INF;
        }
        else if (frequency.at(task) <= minfrequency) {
            if (frequency.at(task) == 0 or maxpos <= position.at(task).front()) {
                minfrequency = frequency.at(task);
                maxpos = position.at(task).front();
                minidx = i;
            }
        }
    }
    assigned[minidx] = param;
    return true;
}

void MinCostToProcessTasks(const int cores, const vi& tasks) {
    const int n = tasks.size();
    int cost = 0;
    vi assigned(cores, -1);
    unordered_map<int, int> frequency;
    unordered_map<int, di> position;

    for (int i = 0; i < n; ++i) {
        ++frequency[tasks[i]];
        position[tasks[i]].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        if (Assign(assigned, frequency, position, tasks[i])) {
            ++cost;
        }
        --frequency[tasks[i]];
        position[tasks[i]].pop_front();
    }

    cout << cost << '\n';
}

int main() { TimeMeasure _; __x();
    MinCostToProcessTasks(3, {1,2,1,3,4,1}); // 4
    MinCostToProcessTasks(2, {1,2,1,3,2,1}); // 4
    MinCostToProcessTasks(3, {7,11,17,10,7,10,2,9,2,18,8,10,20,10,3,20,
                              17,17,17,1,15,10,8,3,3,18,13,2,10,10,11}); // 18
}

#include "../../template.hpp"

struct RecordRaw {
    string arr;
    string dep;
    int platform;
};

struct Record {
    int arr;
    int dep;
    int platform;
    bool operator<(const Record& rhs) const {
        if (platform == rhs.platform) return dep < rhs.dep;
        return platform < rhs.platform;
    }
};

int TimeToNumber(const string& value) {
    int res = 0, n = value.size();
    if (n == 0) return 0;
    res = value[0] - '0';
    for (int i = 1; i < n; ++i) {
        if (not isdigit(value[i])) continue;
        res = res * 10 + value[i] - '0';
    }
    return res;
}

vector<Record> TransformToNumbersAndSort(const vector<RecordRaw>& rawRecords) {
    vector<Record> records;
    for (const auto& rawRecord : rawRecords) {
        int arr = TimeToNumber(rawRecord.arr);
        int dep = TimeToNumber(rawRecord.dep);
        records.push_back({arr, dep, rawRecord.platform});
    }
    sort(records);
    return records;
}

int MaxTrainsWhichCanHaveStoppage(const vector<RecordRaw>& rawRecords) {
    int count = 1, last = 0, n = rawRecords.size();
    if (n < 2) return count;
    const auto records = TransformToNumbersAndSort(rawRecords);
    for (int i = 1; i < n; ++i) {
        if (records[i].platform != records[last].platform) {
            last = i;
            ++count;
            continue;
        }
        if (records[i].arr < records[last].dep) {
            continue;
        }
        ++count;
        last = i;
    }
    return count;
}

int main() { TimeMeasure _;
    static const vector<RecordRaw> records1 = {
        {"10:00", "10:30", 1},
        {"10:10", "10:30", 1},
        {"10:00", "10:20", 2},
        {"10:30", "12:30", 2},
        {"12:00", "12:30", 3},
        {"09:00", "10:05", 1},
    };
    static const vector<RecordRaw> records2 = {
        {"12:00", "12:20", 1},
        {"10:00", "10:30", 1},
        {"11:10", "11:30", 1},
    };
    cout << MaxTrainsWhichCanHaveStoppage(records1) << '\n'; // 5
    cout << MaxTrainsWhichCanHaveStoppage(records2) << '\n'; // 3
}

//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

bool IsAValidDate(const int year, const int month, const int day) {
    return year == 2019 and month <= 4 and day <= 30;
}

void PrintIsAValidDate(const string& year, const string& month, const string& day) {
    if (IsAValidDate(stoi(year), stoi(month), stoi(day))) {
        cout << "Heisei" << '\n';
    }
    else {
        cout << "TBD" << '\n';
    }
}

int main() {
    string year;
    string month;
    string day;

    getline(cin, year, '/');
    getline(cin, month, '/');
    getline(cin, day);

    PrintIsAValidDate(year, month, day);
}

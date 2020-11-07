//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

char GetCorrewspondingLetter(const char b) {
    switch (b) {
    case 'A': return 'T';
    case 'T': return 'A';
    case 'C': return 'G';
    case 'G': return 'C';
    }
    return ' ';
}

void PrintCorrespondingLetter(const char b) {
    cout << GetCorrewspondingLetter(b) << '\n';
}

int main() {
    char b;
    cin >> b;

    PrintCorrespondingLetter(b);
}

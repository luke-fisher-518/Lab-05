#include <iostream>
#include <vector>
#include "StringData.h"
using namespace std;

int linear_search(vector<string> list, const string& element) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == element) {return i;}
    }
    return -1;
}

int binary_search(vector<string> list, const string& element) {
    int lo = 0;
    int hi = list.size() - 1;
    int mid;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (list[mid] == element) {return mid;}
        else if (list[mid] < element) {lo = mid + 1;}
        else {hi = mid - 1;}
    }
    return -1;
}

int main() {
    vector<string> string_data = getStringData();
    vector<string> tests = {"not_here", "mzzzz", "aaaaa"};
    long long start, end;
    for (string& str : tests) {
        cout << "Testing: " << str << "\n";
        start = systemTimeNanoseconds();
        linear_search(string_data, str);
        end = systemTimeNanoseconds();
        cout << "Linear search time: " << (end - start) / 1000.0 << "\n";
        start = systemTimeNanoseconds();
        binary_search(string_data, str);
        end = systemTimeNanoseconds();
        cout << "Binary search time: " << (end - start) / 1000.0 << "\n";
    }
    return 0;
}
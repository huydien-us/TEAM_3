#pragma once
#include <iostream>

#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;

struct Record {
    long long comparison;
    double time; 
};


Record getRecord(const vector<long long>& a, vector<long long> (*sortFunction)(vector<long long>&, long long&)) {
    Record record;
    record.comparison = 0;
    record.time = 0;

    vector<long long> b = a;

    auto start = high_resolution_clock::now();
    sortFunction(b, record.comparison);
    auto stop = high_resolution_clock::now();

    duration<double, std::milli> duration = stop - start;
    record.time = duration.count();

    return record;
}
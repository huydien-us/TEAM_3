#include<iostream>
#include <vector>
using namespace std;

vector<long long> insertionSort(vector<long long>& v) {
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        long long key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
    return v;
}

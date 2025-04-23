#pragma once
#include "header.h"
vector <int> SelectionSort(vector<int> arr) {
    vector <int> newarr = arr;
    int n = newarr.size();

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;

        for (int j = i + 1; j < n; ++j) {
            if (newarr[j] < newarr[min_idx]) {
                min_idx = j;
            }
        }

        swap(newarr[i], newarr[min_idx]);
    }
    return newarr;
}
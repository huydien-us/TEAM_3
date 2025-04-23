#pragma once
#include "header.h"
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort_re(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        QuickSort_re(arr, low, pi - 1);
        QuickSort_re(arr, pi + 1, high);
    }
}

vector<int>QuickSort(vector<int>arr) {
    vector <int> newarr = arr;
    int n = newarr.size();

    QuickSort_re(newarr,0,n-1);
    return newarr;
}

#pragma once
#include<vector>
#include <iostream>
using namespace std;

vector<long long> bubbleSort(vector<long long>& v, long long& comparison) {
    int n = v.size();

    // Outer loop that corresponds to the number of
    // elements to be sorted
    for (int i = 0; i < n - 1; i++) {

        // Last i elements are already
        // in place
        for (int j = 0; j < n - i - 1; j++) {
          
          	// Comparing adjacent elements
            if (v[j] > v[j + 1])
            {
                ++comparison;
                swap(v[j], v[j + 1]);
            }
              
        }
    }
    return v;
}
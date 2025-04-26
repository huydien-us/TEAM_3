#pragma once
#include<vector>
#include <iostream>
using namespace std;
vector<long long> CocktailSort(vector<long long>&a, long long& comparison)
{
    int n = a.size();
    bool swapped = true;
    int start = 0;
    int end = n - 1;
 
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            comparison++;
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
 
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            comparison++;
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
    return a;
}

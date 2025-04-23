#pragma once
#include<vector>
#include <iostream>
using namespace std;

// A binary search based function
// to find the position
// where item should be inserted
// in a[low..high]
int binarySearch(vector<long long>a, int item,
				int low, int high, long long& comparison)
{
	if (high <= low)
    {
		return (item > a[low]) ? (low + 1) : low;
    }

	int mid = (low + high) / 2;

    comparison++;
	if (item == a[mid])
    {
		return mid + 1;
    }

    comparison++;
	if (item > a[mid])
    {
		return binarySearch(a, item, mid + 1, high, comparison);
    }

    comparison++;
	return binarySearch(a, item, low, mid - 1, comparison);
}

vector<long long> Binary_insetion_sort(vector<long long>&a, long long& comparison)
{
    int n = a.size();
    int i, loc, j, k, selected;
 
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
 
        // find location where selected should be inserted
        loc = binarySearch(a, selected, 0, j, comparison);
        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
    return a;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> flashSort(vector<long long>& inputArray) {
    int n = inputArray.size();
    if (n <= 1) return inputArray;

    int m = int(0.45 * n);  
    vector<int> L(m, 0);    

    
    long long minVal = inputArray[0], maxVal = inputArray[0];
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (inputArray[i] < minVal) minVal = inputArray[i];
        if (inputArray[i] > maxVal) {
            maxVal = inputArray[i];
            maxIdx = i;
        }
    }

    if (minVal == maxVal) return inputArray; 

    
    auto getClass = [&](long long val) {
        return int((m - 1) * (val - minVal) / (maxVal - minVal));
    };

    for (int i = 0; i < n; i++)
        L[getClass(inputArray[i])]++;

    
    for (int i = 1; i < m; i++)
        L[i] += L[i - 1];

    
    swap(inputArray[maxIdx], inputArray[0]);
    int count = 0, i = 0, k = m - 1;
    while (count < n - 1) {
        while (i >= L[k]) k = getClass(inputArray[i]);
        long long evicted = inputArray[i];
        while (i != L[k]) {
            k = getClass(evicted);
            long long tmp = inputArray[--L[k]];
            inputArray[L[k]] = evicted;
            evicted = tmp;
            count++;
        }
        i++;
    }

    
    for (int i = 1; i < n; i++) {
        long long key = inputArray[i];
        int j = i - 1;
        while (j >= 0 && inputArray[j] > key) {
            inputArray[j + 1] = inputArray[j];
            j--;
        }
        inputArray[j + 1] = key;
    }

    return inputArray;
}

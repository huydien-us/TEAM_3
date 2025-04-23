#include<iostream>
#include<vector>
using namespace std;

long long getMax(vector<long long>& v) {
    long long mx = v[0];
    for (int i = 1; i < v.size(); i++)
        if (v[i] > mx)
            mx = v[i];
    return mx;
}

void countSort(vector<long long>& v, long long exp) {
    int n = v.size();
    vector<long long> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(v[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        v[i] = output[i];
}

vector<long long> radixsort(vector<long long>& v) {
    long long m = getMax(v);

    for (long long exp = 1; m / exp > 0; exp *= 10)
        countSort(v, exp);
    return v;
}

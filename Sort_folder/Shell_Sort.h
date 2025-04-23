#include <iostream>
#include <vector>
using namespace std;
vector<long long> shellSort(vector<long long>& v)
{
    int n = v.size();
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            long long temp = v[i];
            int j;            
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap)
                v[j] = v[j - gap];
            v[j] = temp;
        }
    }
    return v;
}

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void maxify(vector<int> &arr, int n, int i)
    {
        int largest = i;
        int left = (2 * i + 1);
        int right = (2 * i + 2);
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        swap(arr[largest], arr[i]);
        if (i != largest)
        {
            maxify(arr, n, largest);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int n)
    {
        for (int i = (n - 1) / 2; i >= 0; i--)
        {
            maxify(arr, n, i);
        }
        return;
    }
};
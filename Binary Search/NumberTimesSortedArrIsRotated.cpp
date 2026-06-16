// number of times  a sorted array is rotated=index of the minimum element in array
// same implementation of find minimum element in rotated sorted array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        int n = arr.size();
        int low = 0, high = n - 1, ind = -1;
        int ans = INT_MAX;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[low] <= arr[mid])     //sorted half
            {
                if (ans > arr[low])
                {
                    ans = arr[low];
                    ind = low;
                }

                low = mid + 1;
            }
            else
            {
                if (ans > arr[mid])
                {
                    ans = arr[mid];
                    ind = mid;
                }

                high = mid - 1;
            }
        }

        return ind;
    }
};

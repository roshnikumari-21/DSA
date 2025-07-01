// Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
// Output: 6

#include <bits/stdc++.h>
using namespace std;

// brute--->O(n^2) two looops

// better solution----->hashing... ..works for both positives and negative number
//tc=O(NlogN) or O(N^2)->if using unordered map in worst case
//sc=O(N)


class Solution
{
public:
    int lenOfLongSubarr(int arr[], int N, int K)
    {
        map<int, int> mp;   //{presum,index}
        int res = 0;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
            if (sum == K)
            {
                res =max(i+1,res); 
            }
            else if (mp.find(sum - K) != mp.end())
            {
                res = max(res, i - mp[sum - K]);
            }
            if (mp.find(sum) == mp.end())   //the sum not exist previously then only insert it
            {
                mp[sum] = i;    //store index
            }
        }
        return res;
    }
};

//optimal--->using two pointer
//tc=O(2N)
//only works for non-negative numberss

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();

    while (right < n) {
        while (left <= right && sum > k) {    //trim length when excess
            sum -= a[left];
            left++;
        }

        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

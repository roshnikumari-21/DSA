
#include <bits/stdc++.h>
using namespace std;

//if two distinct number there will be min of 1 bit different


class Solution
{
public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)
    {
        long long xori = 0;
        for (int i = 0; i < n; i++)
        {
            xori ^= arr[i];      //xor of all elements
        }

        long long val = ((xori) & (xori - 1)) ^ xori;  //This extracts the rightmost set bit from xori.
        vector<long long> v1, v2;            //two buckets
        for (int i = 0; i < n; i++)             //divide all numbers into these 2 buckets..
        {
            if ((val & arr[i]) != 0)
                v1.push_back(arr[i]);
            else
                v2.push_back(arr[i]);
        }
        long long a = 0, b = 0; 
        for (int i = 0; i < v1.size(); i++)       //find xor of these 2 buckets individually
        {
            a ^= v1[i];
        }

        for (int i = 0; i < v2.size(); i++)
        {
            b ^= v2[i];
        }

        long long aa = max(a, b);
        long long bb = min(a, b);
        return {aa, bb};
    }
};

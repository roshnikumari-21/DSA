// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// Input: n = 3, k = 3
// Output: "213"

// brute---> to generate all the permu and sort and return the answer

// optimal_______tc=O(n^2)_____________
//sc=O(n)


#include <bits/stdc++.h>    //dekh lena
using namespace std;


class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> nums;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;    // (n-1)! nikal loo..
            nums.push_back(i);
        }
        nums.push_back(n);     //nums=[1,2...n]
        string s = "";
        k = k - 1;                    //for 0 based indexing
        while (true)    //O(N)
        {  
            int ind=k/fact;
            s = s + to_string(nums[ind]);
            nums.erase(nums.begin()+ ind);   //O(N)
            if (nums.size() == 0)
                break;
            else
            {
                k = k % fact;       //dhyan do....bacha hua
                fact = fact / nums.size();
            }
        }
        return s;
    }
};
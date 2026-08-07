// You have two baskets, and each basket can only hold a single type of fruit,
// but you can put as many fruits of that type as you want in that basket.

// You want to pick as many fruits as possible, starting from any tree and moving to the right.
// Once you pick a fruit from a tree, you must pick one from every subsequent tree until
// you can’t pick anymore (i.e., you encounter a third fruit type).
// Return the maximum number of fruits you can pick.

// fruits = [1,2,3,2,2]
// Output: 4

// max length subarray with atmost 2 numbers

// brute____________________________________________________

//tc= O(n^2)   sc=O(1)
#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    int n = fruits.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        set<int> st;
        for (int j = i; j < n; j++)
        {
            st.insert(fruits[j]);
            if (st.size() <= 2)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }

    return maxLen;
}

// optimal______________________________________________________________________________
//tc=O(n)   sc=O(1)


int totalFruit(vector<int> &fruits)
{
    int l = 0, r = 0, maxLen = 0;
    unordered_map<int, int> mpp;
    int k = 2; // Only two types of fruits allowed

    while (r < fruits.size())
    {
        mpp[fruits[r]]++;

        while (mpp.size() > k)
        {
            mpp[fruits[l]]--;
            if (mpp[fruits[l]] == 0)
            {
                mpp.erase(fruits[l]);
            }
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
        r++;
    }

    return maxLen;
}
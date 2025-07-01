// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.

// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

//give a child as minimum as possible-->greedy


#include <bits/stdc++.h>
using namespace std;

// brute solution

// tc=O(3n)     //sc=O(2n)

//think from left,and from right


class Solution
{
public:
    int candy(vector<int> &rat)
    {
        int n = rat.size();
        int ans = 0;
        vector<int> left(n, 0), right(n, 0);
        left[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (rat[i] > rat[i - 1])
                left[i] = left[i - 1] + 1;
            else
                left[i] = 1;
        }
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (rat[i] > rat[i + 1])
                right[i] = right[i + 1] + 1;
            else
                right[i] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            ans += max(left[i], right[i]);
        }
        return ans;
    }
};

//   little optimised___________________________________________________________________________________
// tc=O(2n)   sc=O(N)

//i do  not need the right array    

class Solution
{
public:
    int candy(vector<int> &rat)
    {
        int n = rat.size();
        int ans = 0;
        vector<int> left(n, 0);
        left[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (rat[i] > rat[i - 1])
                left[i] = left[i - 1] + 1;
            else
                left[i] = 1;
        }
        int  right = 1;
        ans += max(1, left[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            if (rat[i] > rat[i + 1])
                right = right + 1;
            else
                right = 1;
            ans += max(left[i], right);
            
        }

        return ans;
    }
};

// best solution______________________________________________________________________________
// using slope concept
// flat --->1
// incr. or decr. slope --> 1 2 3 4....

//valid for any array

// tc=O(N) sc=O(1)

class Solution
{
public:
    int candy(vector<int> &rat)
    {
        int n = rat.size();
        int ans = 1;
        int i = 1;
        int peak, down;
        while (i < n)
        {
            if (rat[i] == rat[i - 1])
            {
                ans++;   //flat surfaces
                i++;
                continue;
            }
            peak = 1;
            while (i < n && rat[i] > rat[i - 1])  //increasing slope
            {
                peak++;
                ans += peak;
                i++;
            }
            down = 1;
            while (i < n && rat[i] < rat[i - 1])   //decreasing slope
            {
                ans += down;
                down++;

                i++;
            }
            if (down > peak)
                ans += (down - peak);
        }
        return ans;
    }
};
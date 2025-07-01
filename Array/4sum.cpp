// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// brute
// use 4 loops i,j,k,l and find sum-->store it in set<vector>>
// tc=O(N^4) sc=O(n)

// a better approach____________________________________________________
//  use 3 loops for 3 num and hash set for 4th one....then store them
// tc=O(N^3log(N))
// sc=O(n)+O(quads)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int tar)
    {
        int n = nums.size();
        set<vector<int>> st; // so that dup ans is not stored
        vector<int> temp;    // storing temp 4 nums to sort it..
        set<int> hash;       // storing nums between j and k
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                hash.clear();
                for (int k = j + 1; k < n; k++)
                {
                    int val = tar - (nums[i] + nums[j] + nums[k]);
                    if (hash.find(val) != hash.end())
                    {
                        temp = {nums[i], nums[j], nums[k], val};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hash.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};

// most optimal approach_______tc=O(n^3 + nlogn)_________________________________________________________

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int tar)
    {

        int n = nums.size();
        sort(nums.begin(), nums.end());    //O(nlogn)
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)            //O(n)
        {
            if (i != 0 && nums[i] == nums[i - 1])   continue;
                
            for (int j = i + 1; j < n; j++)            //O(n)
            { 
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1, l = n - 1;
                while (k < l)      //O(n)
                {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == tar)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k < n && nums[k] == nums[k - 1])
                            k++;
                        while (l >= 0 && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < tar)
                    {
                        k++;
                    }
                    else
                        l--;
                }
            }
        }

        return ans;
    }
};
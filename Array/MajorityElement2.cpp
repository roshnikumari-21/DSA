//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Input: nums = [3,2,3]
// Output: [3]

//at max there can be 2 elements in array
//suppose k elements are there who are possible answers...
// k * (n/3) < n
// => k < 3
// => Maximum value of k = 2


#include <bits/stdc++.h>
using namespace std;


//tc=O(NlogN)

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            map<int,int>mp;
            vector<int>ans;
            int n=nums.size();
            for(int i=0; i<n; i++){
                mp[nums[i]]++;
                if(mp[nums[i]]>n/3)  ans.push_back(nums[i]);
            }
            
            return ans;
        }
    };


//tc=O(2N)_________sc=O(1)_________________optimal_____________________________


#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v) {
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;

    // First pass: find potential candidates
    for (int i = 0; i < v.size(); i++) {     //O(n)
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        } 
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        } 
        else if (v[i] == el1) {
            cnt1++;
        } 
        else if (v[i] == el2) {
            cnt2++;
        } 
        else {
            cnt1--;
            cnt2--;
        }
    }


    
    // Second pass: verify the candidates  ...manual check
    vector<int> ls;
    cnt1 = cnt2 = 0;

    for (int i = 0; i < v.size(); i++) {           //O(n)
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = (int)(v.size() / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini && el2 != el1) ls.push_back(el2);

    sort(ls.begin(), ls.end());
    return ls;
}




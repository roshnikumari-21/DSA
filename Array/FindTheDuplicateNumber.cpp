#include <bits/stdc++.h>
using namespace std;


//brute______________________________
//sort the array, tc=O(nlogn)

//better________________by using hash map___________


//most optimal__________linked list cycle method---->starting point of loop
//tc=O(n)_____________sc=O(1)


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int slow=nums[0];
        int fast=nums[0];

        do{                      //dhyan dena....do while
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};


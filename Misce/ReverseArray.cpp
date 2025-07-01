#include <bits/stdc++.h>
using namespace std;

//pta nhi  but yes doing it...

vector<int> reverseArray(int n, vector<int> &nums)
{
    for(int i=0;i<nums.size()/2; i++){
        swap(nums[i],nums[n-i-1]);
    }

    return nums;

}

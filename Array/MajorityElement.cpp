#include <bits/stdc++.h>
using namespace std;


//brute using hashing_______map or unordered_map
//tc=O(nlogn)+O(N)______sc=O(N)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=n/2;
        return nums[mid];

        
    }
};

//Moor's voting algorithm
//tc=O(n)+ O(n)

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {
    int cnt = 0;
    int el;

    // First pass to find potential candidate
    for (int i = 0; i < v.size(); i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        } else if (v[i] == el) {
            cnt++;
        } else {
            cnt--;
        }
    }

    // Second pass to confirm the candidate...only if quest dont confirm that majority element exist..
    int cnt1 = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (v.size() / 2)) {
        return el;
    }

    return -1;
}

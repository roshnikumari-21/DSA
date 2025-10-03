#include <bits/stdc++.h>
using namespace std;

//better___________________
//tc=O(N*log(k))


//heap me largest k and usse bade elements hi rhenge

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap

        for (int &num : nums) {
            pq.push(num);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top(); // O(n * log k)
    }
};



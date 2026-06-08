// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]


#include <bits/stdc++.h>
using namespace std;

//brute force __________________tc=O(2N)+nlogn________


vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());  // Sort based on starting time

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        int start = arr[i][0];
        int end = arr[i][1];

        // Skip if current interval is already covered
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            } else {
                break;
            }
        }

        ans.push_back({start, end});
    }

    return ans;
}


//_________________________________________________________________

//tc= O(NlogN + N)
//sc= O(N)

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& arr) {
            vector<vector<int>> ans;
            sort(arr.begin(), arr.end());    // Sort based on starting time
            int n = arr.size();
    
            for (int i = 0; i < n; i++) {
                if (ans.size() == 0 || arr[i][0] > ans.back()[1]) {   //no overlap
                    ans.push_back(arr[i]);
                }
    
                else {
                    ans.back()[1] = max(ans.back()[1], arr[i][1]);    //overlap
                }
            }
            return ans;
        }
    };
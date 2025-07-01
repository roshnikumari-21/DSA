// Input: children = [1,2], cookies = [1,2,3]
// Output: 2

// Input: children = [1,2,3], cookies = [1,1]
// Output: 1


//tc=O(nlogn + mlogm)

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(g.begin(),g.end());    //O(nlogn)
            sort(s.begin(),s.end());      //O(mlogm)
            int n=g.size();
            int m=s.size();
            int j=0,ans=0;
    
            for(int i=0; i<n; i++){
                while(j<m && g[i]>s[j]) {j++;}
                if(j>=m) break;
                ans++;            
                j++;
    
            }
    
            return ans;
        }
    };
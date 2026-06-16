#include <bits/stdc++.h>
using namespace std;


//brute______________O(N)_________________

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        
        for(int i=0; i<n; i++){
            if(arr[i]<=k)  k++;
            else break;
        }
        return k;
    }
};



    //optimal________O(log(N))___________________________________

    //find out the indexes between which my ans will be lying
    // 1 based numberiring

    class Solution {
        public:
            int findKthPositive(vector<int>& arr, int k) {
                int low = 0, high = arr.size() - 1;
                
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    int missing = arr[mid] - (mid + 1);
                    
                    if (missing < k) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                
                // The kth missing number is at position: low + k
                return low + k;     //note--->this is actuallly a derivation...
            }
        };
        

        //derivation....
        // ans=arr[high]+more
        //more=k-missing
        //missing=arr[high]-(high+1)
        //hence ans=low+k  ....as low=(high+1)..
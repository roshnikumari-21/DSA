//leader---->everything on the right should be smaller

//brute____________O(N^2)_______________________



#include <bits/stdc++.h>
using namespace std;


vector<int> findLeaders(vector<int> &a) {
    int n = a.size();
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        bool leader = true;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {  
                leader = false;    //i can't be a leader
                break;
            }
        }
        if (leader == true)
            ans.push_back(a[i]);
    }
    return ans;
}


//optimal_____________O(N)_______________________________


vector<int> superiorElements(vector<int> &a) {
    vector<int> ans;
    int maxi = INT_MIN;
    int n = a.size();
    
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > maxi) {
            ans.push_back(a[i]);
        }        
        maxi = max(maxi, a[i]);
    }

    
    sort(ans.begin(), ans.end());
    return ans;
}
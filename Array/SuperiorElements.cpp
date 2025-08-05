
// An element is called a Superior Element if it is greater than all the elements present to its right.
// You must return an array all Superior Elements in the array ‘a’.

#include <bits/stdc++.h>
using namespace std;


vector<int> superiorElements(vector<int> &a)
{
    vector<int> ans;
    int n = a.size();
    int maxi = a[n - 1];
    ans.push_back(a[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > maxi)
        {
            ans.push_back(a[i]);
        }
        maxi = max(maxi, a[i]);
    }

    return ans;
}
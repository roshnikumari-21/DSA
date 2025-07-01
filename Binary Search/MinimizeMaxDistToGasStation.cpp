// You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions
//  of ‘n’ gas stations on the X-axis.
// Let 'dist' be the maximum value of the distance between adjacent gas stations after
//  adding 'k' new gas stations.

// Find the minimum value of dist.

// return the answer in long double and double

// brute______________tc=O(n*k)+O(n)_____________
#include <bits/stdc++.h>
using namespace std;

double minimiseMaxDistance(vector<int> &arr, int k)
{

    int n = arr.size();

    vector<double> howmany(n - 1, 0);
    for (double i = 1; i <= k; i++)
    {
        double maxdis = -1, maxind = -1;
        for (double j = 0; j < (n - 1); j++) // for the gaps btw stations initially
        {
            double dist = arr[j + 1] - arr[j];
            double seclen = dist / (howmany[j] + 1);
            if (maxdis < seclen) // finding the max-dist b/w two stations and its index
            {
                maxdis = seclen;
                maxind = j;
            }
        }
        howmany[maxind]++;
    }

    double ans = 0;
    for (double j = 0; j < (n - 1); j++)
    {
        ans = max(ans, ((double)(arr[j + 1] - arr[j])) / (howmany[j] + 1));
    }

    return ans;
}

// using priority queue__________________tc=O(nlogn+klogn)_______sc=O(n-1)->in pq_________________________
// pq.top()-->O(1)
// pq.push()--->O(n)

#include <bits/stdc++.h>

double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<pair<double, int>> pq; // section_len,index
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }

    vector<int> howmany(n - 1, 0);

    // iterate through k (no. of gas stations to be placed).....
    for (double i = 1; i <= k; i++)
    {
        auto it = pq.top();
        pq.pop();
        int ind = it.second;
        howmany[ind]++;
        double remdis = arr[ind + 1] - arr[ind];
        double secdis = (remdis / (double)(howmany[ind] + 1));
        pq.push({secdis, ind});
    }

    return pq.top().first;
}


//after this there may be some interviewres who is even not happy with this solution too...so now lets focus
//on reducing the space complextiy

//Using binary Search

//a different pattern of binary search is there

//42:40 of strivers video....completering it later on...


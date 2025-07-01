// Your task is to find out the minimal value of the maximum amount of time
//  for which Ayush studies in a day, in order to complete all the 'M' chapters
//  in no more than 'N' days.


//extremely hard

//Total time: O(m * log(sum))
//sc=O(1)


#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
#define ll long long

ll check(ll mid, vector<int> &time, int m)
{
    ll k = 0, sum = 0;
    for (int i = 0; i < m; i++)    //O(1)
    {
        if (sum + time[i] > mid)
        {
            k++;
            sum = time[i];
        }
        else
        {
            sum += time[i];
        }
    }

    if (sum > 0)
        k++;
    return k;
}


long long ayushGivesNinjatest(int n, int m, vector<int> time)
{

    ll sum = 0;
    for (int i = 0; i < m; i++)
        sum += time[i];
    ll maxi = *max_element(time.begin(), time.end());
    ll st = maxi, end = sum, mid, ans = -1;

    while (st <= end)
    {
        mid = st + (end - st) / 2;
        ll val = check(mid, time, m);
        if (val <= n)
        {
            ans = mid;
            end = mid - 1;
        }
        else
            st = mid + 1;
    }

    return ans;
}
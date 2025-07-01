#include <bits/stdc++.h>
using namespace std;


//tc=O(root(n)*log(n))
//using this approach for a large prime number the complexity is stiilll O(n)---->explain this to interviewer

int countPrimes(int n)
{

    int ans = 0;

    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            ans++;
            while (n % i == 0)      
            {
                n /= i;   //log(n) for dividing
            }
        }
    }

    return ans;
}


//more optimised appoarch________tc=O(root(n)*log(n))_______________

int countPrimes(int n)
{

    int ans = 0;

    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            ans++;
            while (n % i == 0)
            {
                n /= i;   //log(n) for dividing
            }
        }
    }

    if(n!=1) ans++;

    return ans;
}
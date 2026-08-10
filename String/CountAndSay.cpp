#include <bits/stdc++.h>
using namespace std;


//tc= O(2^n) sc=O(n)

//u can do the recursion version also
class Solution
{
public:
    string countAndSay(int n)
    {
        string s = "1";
        n--;
        while (n--)
        {
            string ans = "";
            int m = s.size();
            for (int i = 0; i < m; i++)
            {
                int cnt = 1;
                if (i + 1 < m && s[i] == s[i + 1])
                {
                    while (i + 1 < m && s[i] == s[i + 1])
                    {
                        cnt++;
                        i++;
                    }
                }
                ans += to_string(cnt);
                ans += s[i];
            }
            s = ans;
        }
        return s;
    }
};
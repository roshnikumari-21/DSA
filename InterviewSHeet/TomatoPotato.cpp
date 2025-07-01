// Arrange them such that no two same vegetables are adjacent.

// The maximum frequency should be less than or equal to ceil(total / 2)

// Rearrange String so that no two adjacent characters are the same
// Reorganize

// using heap
// store freq
// max heap ({freq,char })
// if any character coming more than (n+1)/2 times ....not possible to rearrasnge

// eg: aaabbbccd
// do do element ko pop krte jaooo and add it to ans

#include <bits/stdc++.h>
using namespace std;




class Solution
{
public:
    typedef pair<int, char> P;

    string reorganizeString(string s)
    {
        int n = s.length();
        vector<int> count(26, 0);

        for (char ch : s)
        {
            count[ch - 'a']++;
            // Early exit if any character count exceeds half the length of the string
            if (count[ch - 'a'] > (n + 1) / 2)
            {
                return "";
            }
        }

        // Max-heap
        priority_queue<P> pq;

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (count[ch - 'a'] > 0)
            {
                pq.push({count[ch - 'a'], ch});
            }
        }

        string result = "";

        // Process the characters
        while (pq.size() >= 2)
        {
            auto P1 = pq.top();
            pq.pop();
            auto P2 = pq.top();
            pq.pop();

            result.push_back(P1.second);
            result.push_back(P2.second);
            P1.first--;
            P2.first--;

            if (P1.first > 0)
            {
                pq.push(P1);
            }
            if (P2.first > 0)
            {
                pq.push(P2);
            }
        }

        // If there is one character left
        if (!pq.empty())
        {
            result.push_back(pq.top().second);
        }

        return result;
    }
};

int main()
{
    Solution solution;
    string input = "aaabb";
    string output = solution.reorganizeString(input);
    cout << "Reorganized String: " << output << endl;
    return 0;
}

//output will be ababa
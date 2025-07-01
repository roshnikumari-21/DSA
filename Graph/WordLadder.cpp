// extremelly hard

// Given two words, beginWord and endWord, and a dictionary wordList,
//  return the number of words in the shortest transformation sequence
//   from beginWord to endWord, or 0 if no such sequence exists.

//using bfs traversal

#include <bits/stdc++.h>
using namespace std;

// tc=O(N*wordlength*26*log(N))

class Solution
{
public:
    int ladderLength(string beg, string end, vector<string> &wordl)
    {
        int n = wordl.size();
        set<string> st;
        for (auto i : wordl)
        {
            st.insert(i);
        }
        int len = 0;

        queue<pair<string, int>> q;
        q.push({beg, 1}); // word,level
        st.erase(beg);
        while (!q.empty())
        {
            string s = q.front().first;
            len = q.front().second;
            q.pop();

            if (s == end)
                return len;
            for (int i = 0; i < s.size(); i++)
            {
                char ori = s[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    s[i] = ch;
                    if (st.find(s) != st.end())  //word mil gya set me
                    {
                        st.erase(s);
                        q.push({s, len + 1});
                    }
                }
                s[i] = ori;
            }
        }

        return 0;
    }
};
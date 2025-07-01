#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beg, string end,
                                       vector<string> &wordl)
    {
        vector<vector<string>> ans;

        unordered_set<string> st(wordl.begin(), wordl.end());
        if (st.count(end) == 0) // if end word not exist , return empty ans..
            return ans;
            
        vector<string> used_level; // to store used word
        queue<vector<string>> q;
        q.push({beg});
        used_level.push_back(beg);
        int level = 0;

        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            // erase all words which have been previously used
            if (vec.size() > level)
            {
                level++;
                for (auto it : used_level)
                {
                    st.erase(it);
                }
            }
            string word = vec.back();

            if (word == end)
            { // reached end word
                if (ans.size() == 0)
                    ans.push_back(vec);
                else if (vec.size() == ans[0].size()) // for storing multiple answwers
                    ans.push_back(vec);
            }

            for (int i = 0; i < word.size(); i++)
            {
                char ori = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word) > 0)
                    {
                        vec.push_back(word);
                        q.push(vec);
                        used_level.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = ori;
            }
        }
        return ans;
    }
};
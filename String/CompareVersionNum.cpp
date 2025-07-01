// Given two version strings, version1 and version2, compare them. A version string consists
// of revisions separated by dots '.'. The value of the revision is its integer conversion
//  ignoring leading zeros.

// To compare version strings, compare their revision values in left-to-right order.
//  If one of the version strings has fewer revisions, treat the missing revision values as 0.

#include <bits/stdc++.h>
using namespace std;

//using stringstream__________________________________________________

//tc=O(M+N)
//sc=O(M+N)


class Solution
{
public:

vector<string> getTokens(string version) {
    stringstream ss(version);
    string token = "";
    vector<string> tokens;

    while(getline(ss, token, '.')) {  //delimetr
        tokens.push_back(token);
    }
    return tokens;
}

int compareVersion(string version1, string version2) {
    // Space:
    vector<string> v1 = getTokens(version1); // (0m)
    vector<string> v2 = getTokens(version2); // (0n)

    int m = v1.size();
    int n = v2.size();
    int i = 0;

    while(i < m || i < n) {
        int a = i < m ? stoi(v1[i]) : 0;
        int b = i < n ? stoi(v2[i]) : 0;
        if(a < b) {
            return -1;
        } else if(a > b) {
            return 1;
        } else {
            i++;
        }
    }
    return 0; // equal versions
}
};

//_____________________________________________________________________________________________________________

//tc and sc are same




class Solution
{
public:
    int compareVersion(string ver1, string ver2)
    {

        ver1.insert(0, 1, '.');   //adding . at start of both strings for making parsing easier
        ver2.insert(0, 1, '.');
        int n = ver1.size();
        int m = ver2.size();

        vector<int> first, second;
        string a = "";

        for (int i = 0; i < n; i++)
        {
            if (ver1[i] == '.')
            {
                i++;
                while (i < n && ver1[i] != '.')
                {
                    a += ver1[i];
                    i++;
                }
                int num = stoi(a);
                first.push_back(num);
                a = "";
                i--;
            }
        }
        a = "";
        for (int i = 0; i < m; i++)
        {
            if (ver2[i] == '.')
            {
                i++;
                while (i < m && ver2[i] != '.')
                {
                    a += ver2[i];
                    i++;
                }
                int num = stoi(a);
                second.push_back(num);
                a = "";
                i--;
            }
        }

        int fs = first.size();
        int ss = second.size();
        if (fs < ss)
        {
            while (first.size() != second.size())
                first.push_back(0);
        }
        else
        {
            while (first.size() != second.size())
                second.push_back(0);
        }

        for (int i = 0; i < first.size(); i++)
        {
            if (first[i] > second[i])
                return 1;
            else if (first[i] < second[i])
                return -1;
        }
        return 0;
    }
};
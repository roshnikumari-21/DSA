// Given an integer array nums, return the maximum result of nums[i] XOR nums[j],
// where 0 <= i <= j < n.

// same approach , insert one array into trie...
// then try with all elements of array2

// tc=O(n*32)  and O(m*32)  for both arrays

#include <bits/stdc++.h>
using namespace std;

class Trie
{
private:
    struct Node
    {
        Node *links[2];
        bool containskey(int bit)
        {
            // if(links[bit]==NULL) return false;
            // else return true;
            return (links[bit] != NULL);
        }

        Node *get(int bit)
        {
            return links[bit];
        }

        void put(int bit, Node *node)
        { // create a node and put the bit
            links[bit] = node;
        }
    };
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }


    void insert(int num)
    { // start inserting from 31st bit
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        { // insert all 32 bits
            int bit = ((1 << i) & num);
            if (bit == 0)
                bit = 0;
            else
                bit = 1;
            if (!node->containskey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }


    int getMax(int num)
    {
        Node *node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--)
        { // start from leftmost bit
            int bit = ((1 << i) & num);
            if (bit == 0)
                bit = 0;
            else
                bit = 1;
            if (node->containskey(1 - bit))
            {
                maxi = maxi | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxi;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int n = nums.size();

        Trie trie;
        for (auto it : nums)
        {
            trie.insert(it);
        }
        int maxi = 0;
        for (auto it : nums)
        {
            maxi = max(maxi, trie.getMax(it));
        }

        return maxi;
    }
};
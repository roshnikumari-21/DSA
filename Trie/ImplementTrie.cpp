#include <bits/stdc++.h>
using namespace std;

// tc=O(len)

class Trie
{
private:
    struct Node
    {
        Node *links[26]; // array of size 26
        bool flag = false;

        bool containsKey(char ch)
        {
            return (links[ch - 'a'] != NULL);
        }

        void put(char ch, Node *node)
        {
            links[ch - 'a'] = node;
        }

        Node *get(char ch)
        {
            return links[ch - 'a'];
        }

        void setEnd()
        {
            flag = true;
        }

        bool isEnd()
        {
            return flag;
        }
    };

    Node *root;

public:
    /** Initialize your data structure here. */
    Trie() // constructor
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */

    void insert(string word) // tc=O(n)
    {
        Node *node = root; // dummy pointer pointing to root...
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // move to the reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) // tc=O(n)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) // tc=O(m)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
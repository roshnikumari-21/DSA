#include <bits/stdc++.h>
using namespace std;


class Trie
{

private:
    struct Node
    {
        Node *links[26];
        int cntEnd = 0;
        int cntPre = 0;
        

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

        int getEnd()
        {
            return cntEnd;
        }

        int getPre()
        {
            return cntPre;
        }

        void incEnd()
        {
            cntEnd++;
        }

        void incPre()
        {
            cntPre++;
        }

        void decEnd()
        {
            cntEnd--;
        }

        void decPre()
        {
            cntPre--;
        }
    };

    Node *root;

public:
    Trie()
    {
        
        root = new Node();
    }

    void insert(string &word)
    {
        
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // move to the reference trie
            node = node->get(word[i]);
            node->incPre();
        }

        node->incEnd();
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getPre();
    }

    void erase(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->decPre();
            }
            // else return 0;
        }
        node->decEnd();
    }
};

//using doubly linked list  and map of <key,Node*>
//tc=O(1)
//Use unordered_map instead of map for true O(1) performance.
//sc=O(capacity)

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    public:
       class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key,int _val){   //constructor
            key=_key;
            val=_val;
        }
       };

       node* head=new node(-1,-1);
       node* tail=new node(-1,-1);
       int cap;
       map<int,node*>mp;      //key,node address
        LRUCache(int capacity) {
            cap=capacity;
            head->next=tail;
            tail->prev=head;
        }

        void addnode(node* nwnode){
            node* temp=head->next;
            nwnode->next=temp;
            nwnode->prev=head;
            head->next=nwnode;
            temp->prev=nwnode;
        }
        
        void deletenode(node* dlnode){
            node* delprev=dlnode->prev;
            node* delnext=dlnode->next;
            delprev->next=delnext;
            delnext->prev=delprev;
        }
        int get(int key) {
            if(mp.find(key)!=mp.end()){
                node* resnode=mp[key];
                int res=resnode->val;
                mp.erase(key);
                deletenode(resnode);
                addnode(resnode);
                mp[key]=head->next;
                return res;
            }
            return -1;            
        }
        
        void put(int key, int value) {
            if(mp.find(key)!=mp.end()){   //agar pehle se hai...
                node* temp=mp[key];
                mp.erase(key);
                deletenode(temp);
            }
            if(mp.size()==cap){
                mp.erase(tail->prev->key);
                deletenode(tail->prev);
            }
            addnode(new node(key,value));
            mp[key]=head->next;
        }
    };
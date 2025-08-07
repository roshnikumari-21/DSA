//MIK

// Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals 
// between two tasks with the same label.

// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8

//greedy + priority queue
//using heap to find the most freq. task and schedule it earlier

//tc=O(nlogk)__________sc=O(k)


#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            int m = tasks.size();
            map<char, int> mp;
            for (int i = 0; i < m; i++) {
                mp[tasks[i]]++;
            }
    
            priority_queue<int> pq;
            for (auto it : mp) {
                pq.push(it.second);
            }
    
            int ans=0;
            while (!pq.empty()) {
                vector<int> temp;
                for (int i = 1; i <= n + 1; i++) {
                    if (!pq.empty()) {
                        int freq = pq.top();
                        pq.pop();
                        freq--;
                        temp.push_back(freq);
                    }
                }
    
                for(auto it: temp){
                    if(it>0) pq.push(it);
                }
                if(pq.empty()) ans+=(temp.size());   //for last scheduling if temp has all elem =0 ,add those.
                else ans+=(n+1);   //else always, (n+1)
            }
            return ans;
        }
    };

//______________________________________________________________________________________
//greedy approach
//tc=O(n)

class Solution {
    public:
        int leastInterval(vector<char>& tas, int n) {
            int m=tas.size();
            vector<int>mp(26,0);
            for(int i=0; i<m; i++){
                mp[tas[i]-'A']++;
                
            }
            sort(mp.begin(),mp.end());
            int hole=mp[25]-1;      //maximum freq -1
            int idleslot=(hole*n);
    
            for(int i=24; i>=0; i--){
                idleslot-=min(mp[i],hole);
            }
    
            if(idleslot>0){
                return m+idleslot;
            }
            else return m;
    
            
    
        }
    };


   // Sorting a fixed-size array takes O(26 log 26) ≈ O(1) 
#include <bits/stdc++.h>
using namespace std;


//tc=O(N∗M∗4^l) 


class Solution {
    public:
      int dirx[4]={1,0,-1,0};
      int diry[4]={0,1,0,-1};

        bool backtrack(vector<vector<char>>& v, const string& word, int i, int j, int ind, int n, int m) {
            if (ind == word.size()) return true;  // All characters matched
            if (i < 0 || j < 0 || i >= n || j >= m || v[i][j] != word[ind]) return false;  // Out of bounds or mismatch
    
            // Temporarily mark the current cell as visited
            char temp = v[i][j];
            v[i][j] = '*';
    
            // Explore all four directions          
            for (int d = 0; d < 4; ++d) {
                int ni = i + dirx[d];
                int nj = j + diry[d];
                if (backtrack(v, word, ni, nj, ind + 1, n, m)) {
                    return true;
                }
            }
    
            // Restore the original value of the cell
            v[i][j] = temp;
            return false;
        }
    
        bool exist(vector<vector<char>>& v, string word) {
            int n = v.size(), m = v[0].size();
    
            // Early exit: Check if `word` contains characters not present in `v`
            unordered_map<char, int> charCount;
            for (const auto& row : v) {
                for (char ch : row) {
                    charCount[ch]++;
                }
            }
            for (char ch : word) {
                if (charCount[ch]-- <= 0) return false;  //early return false
            }
    
            // Start backtracking from each cell
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (v[i][j] == word[0] && backtrack(v, word, i, j, 0, n, m)) {
                        return true;
                    }
                }
            }
            return false;
        }
    };
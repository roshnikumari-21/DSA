#include <bits/stdc++.h>
using namespace std;



// Category	Complexity
// Time	O(9^M)    (M = empty cells)
// Space	O(M) (recursion depth)

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c;

                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;    //if there was no empty space to be filled
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c)  //check for col
                return false;
            if (board[row][i] == c)    //check for row
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
};

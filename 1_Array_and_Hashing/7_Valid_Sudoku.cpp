/*
https://leetcode.com/problems/valid-sudoku/
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Example 1:
    Input: board = 
    [["5","3",".",".","7",".",".",".","."]
    ,["6",".",".","1","9","5",".",".","."]
    ,[".","9","8",".",".",".",".","6","."]
    ,["8",".",".",".","6",".",".",".","3"]
    ,["4",".",".","8",".","3",".",".","1"]
    ,["7",".",".",".","2",".",".",".","6"]
    ,[".","6",".",".",".",".","2","8","."]
    ,[".",".",".","4","1","9",".",".","5"]
    ,[".",".",".",".","8",".",".","7","9"]]
    Output: true
*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Easiest approach: Loop and check duplicate
Complexity analysis:
    - Time complexity: O(n^2)
    - Space complexity: O(n)
*/
class Solution {
public:
    bool containsDuplicateNumber(vector<char>& nums) {
        unordered_map<char, int> freq;
        for (auto num:nums) {
            if (freq[num] && num != '.') return true;
            freq[num]++;
        }
        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            // check rows
            if (containsDuplicateNumber(board[i])) return false;
            // check columns
            vector<char> column_i;
            for (int j = 0; j < 9; j++) column_i.push_back(board[j][i]);
            if (containsDuplicateNumber(column_i)) return false;
            // check sub-box
            int start_row = (i / 3) * 3, start_column = (i % 3) * 3;
            vector<char> sub_box;
            for (int i = start_row; i < start_row + 3; i++)
                for (int j = start_column; j < start_column + 3; j++)
                    sub_box.push_back(board[i][j]);
            if (containsDuplicateNumber(sub_box)) return false;
        }
        
        return true;
    }
};
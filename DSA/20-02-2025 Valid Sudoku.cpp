/*
Ques - https://neetcode.io/problems/valid-sudoku
*/
/*
You are given a a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:
Each row must contain the digits 1-9 without duplicates.
Each column must contain the digits 1-9 without duplicates.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
Return true if the Sudoku board is valid, otherwise return false

Note: A board does not need to be full or be solvable to be valid.

Example 1:
Input: board = 
[["1","2",".",".","3",".",".",".","."],
 ["4",".",".","5",".",".",".",".","."],
 [".","9","8",".",".",".",".",".","3"],
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:
Input: board = 
[["1","2",".",".","3",".",".",".","."],
 ["4",".",".","5",".",".",".",".","."],
 [".","9","1",".",".",".",".",".","3"],
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: There are two 1's in the top-left 3x3 sub-box.

Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
*/
/*
Approach - we will check for the sukodu validation in first roe 
         - we will traverse the first row and check if there's 1 - 9 with no repetion
         - we will check similarly for column
         - for the nested square : we can eembed it in the for loop only
         - We'll need to validate 3 rules:
                - each row has unique digits 1-9
                - each column has unique digits 1-9
                - each 3x3 box has unique digits 1-9
*/
#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    // check each row
    for (int i = 0; i < 9; i++) {
        unordered_set<char> s;
        for (int j = 0; j < 9; j++) {
            char ch = board[i][j];
            if (ch == '.') continue;
            if (s.count(ch)) return false; // Duplicate in row
            s.insert(ch);
        }
    }
    // check each column
    for (int j = 0; j < 9; j++) {
        unordered_set<char> s;
        for (int i = 0; i < 9; i++) {
            char ch = board[i][j];
            if (ch == '.') continue;
            if (s.count(ch)) return false; // Duplicate in column
            s.insert(ch);
        }
    }
    // check each 3x3 sub-box
    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            unordered_set<char> s;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char ch = board[row + i][col + j];
                    if (ch == '.') continue;
                    if (s.count(ch)) return false; // Duplicate in 3x3 box
                    s.insert(ch);
                }
            }
        }
    }
    return true;
}

// Time Complexity : O(81 iterations) = O(1)
// Space Complexity : O(1)
/*
Solution 2 - avoided repetion and did all 3 loops in one paas.
*/
#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    // create 9 sets for rows, columns, and boxes
    unordered_set<char> rows[9];
    unordered_set<char> cols[9];
    unordered_set<char> boxes[9];

    // traverse the board once
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char ch = board[i][j];
            if (ch == '.') continue;

            // calculate box index
            int boxIndex = (i / 3) * 3 + (j / 3);

            // check for duplicates
            if (rows[i].count(ch) > 0) return false;
            if (cols[j].count(ch) > 0) return false;
            if (boxes[boxIndex].count(ch) > 0) return false;

            // add to sets
            rows[i].insert(ch);
            cols[j].insert(ch);
            boxes[boxIndex].insert(ch);
        }
    }

    return true;
}
// since this is a fixed problem - time comp will always be O(1)
// and space as well
// but this wont work in N x N board as it'll have O(N^2) time complexity.

// generalized for N X N
#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    int N = board.size();
    int boxSize = sqrt(N);

    vector<unordered_set<char>> rows(N);
    vector<unordered_set<char>> cols(N);
    vector<unordered_set<char>> boxes(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ch = board[i][j];
            if (ch == '.') continue;

            int boxIndex = (i / boxSize) * boxSize + (j / boxSize);

            if (rows[i].count(ch) || cols[j].count(ch) || boxes[boxIndex].count(ch))
                return false;

            rows[i].insert(ch);
            cols[j].insert(ch);
            boxes[boxIndex].insert(ch);
        }
    }

    return true;
}

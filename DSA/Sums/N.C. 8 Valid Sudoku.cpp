/*
Given a Sudoku - return : if valid "true" else "false"
A Sudoku is valid if - Each row must contain the digits 1-9 without duplicates.
                     - Each column must contain the digits 1-9 without duplicates.
                     - Each of the nine 3 x 3 sub-boxes of the grid must contain 
                       the digits 1-9 without duplicates.

      Constraints - board.length == 9
                  - board[i].length == 9
                  - board[i][j] is a digit 1-9 or '.'
*/
/*
Approach - for every "." we can check if the number from 1 to 9 
           will ever exists in three constraints checks
         - also well need to store the "guessed" value for future checks
*/

#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<char>>& board) {
    // ROW CHECK
    for (int row = 0; row < 9; row++) {
        vector<bool> seen(10, false);
        for (int col = 0; col < 9; col++) {
            char c = board[row][col];
            if (c == '.') continue;
            int num = c - '0';
            // detect duplicate in current row/column/3x3 box
            if (seen[num]) return false; // if number already seen in this 
                                        // row/col/box → duplicate → invalid
            seen[num] = true; // mark number as seen
        }
    }
    // COLUMN CHECK
    for (int col = 0; col < 9; col++) {
        vector<bool> seen(10, false);
        for (int row = 0; row < 9; row++) {
            char c = board[row][col];
            if (c == '.') // '.' means no number, so nothing to validate here 
              continue;
            int num = c - '0'; // convert char digit to number
                              // ASCII trick: '5' - '0' = 5
                             // char digit → int value
                            // convert digit character ('1'–'9') to integer 1–9
            if (seen[num]) return false;
            seen[num] = true;
        }
    }
    // 3x3 BOX CHECK
    for (int boxRow = 0; boxRow < 9; boxRow += 3) {
        for (int boxCol = 0; boxCol < 9; boxCol += 3) {
            vector<bool> seen(10, false);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char c = board[boxRow + i][boxCol + j]; // + i and + j is for row and col 
                                                            // traversal inside the 3x3 box.
                  if (c == '.') continue; 
                    int num = c - '0';
                    if (seen[num]) return false;
                    seen[num] = true;
                }
            }
        }
    }
    return true;
}

// Time Complexity: O(1)
// Space Complexity: O(1)

/*
Why O(1)?
The Sudoku board size is fixed (9×9).
We do: - Row checks: 9 × 9
       - Column checks: 9 × 9
       - Box checks: 9 boxes × 9 cells
Total operations ≈ constant (~243 checks) — does not grow with input size.
So even though loops exist, the input size never changes → constant time.
Space -> seen[10] is used repeatedly but always fixed size.
No extra space grows with input.
*/

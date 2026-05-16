// https://leetcode.com/problems/set-matrix-zeroes/description/

Ques - Given an m x n integer matrix matrix, 
       if an element is 0, 
       set its entire row and column to 0's.

You must do it in place.

/*
 an in-place algorithm is an algorithm that 
 operates directly on the input data structure 
 without requiring extra space proportional 
 to the input size. 
 In other words, it modifies the input in place, 
 without creating a separate copy of the data structure
*/

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1



void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool firstRowZero = false;
    bool firstColZero = false;
    for (int j = 0; j < cols; j++) {
        if (matrix[0][j] == 0) firstRowZero = true;
    }
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) firstColZero = true;
    }
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (firstRowZero) {
        for (int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }
    if (firstColZero) {
        for (int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
}

Time Complexity: O(m × n) 
                 We make a constant number of passes 
                 through the matrix: once to check first row/column, 
                 once to mark, once to zero inner cells, and potentially
                 once each for first row/column.

Space Complexity: O(1) 
                  We only use two boolean variables. 
                  The first row and column of the matrix itself serve as our markers, 
                  requiring no additional space proportional to input size.

  
Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

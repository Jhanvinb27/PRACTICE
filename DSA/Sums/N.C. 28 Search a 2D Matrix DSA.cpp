/*
Ques - Write an efficient algorithm that searches for a value target 
     - in an m x n integer matrix.
     - The matrix has the following properties:
            - Each row is sorted in ascending order
            - The first integer of each row is greater than the last integer of the previous row
     - Return true if target exists, else false
*/

/*
Example 1 - Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
          - Output: true

Example 2 - Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
          - Output: false
*/

/*
Observation -
- Entire matrix behaves like a sorted array
- Because:
        - rows are sorted
        - next row starts after previous row ends
- So we can apply binary search
- Key trick: treat 2D matrix as 1D array :contentReference[oaicite:0]{index=0}
*/

/*
Approach 1 - Brute Force
           - Traverse entire matrix
           - Compare each element with target

Algorithm -
          - for each row:
                - for each column:
                        - if matrix[i][j] == target:
                                - return true
          - return false
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == target)
                    return true;
            }
        }

        return false;
    }
};

// Time : O(m * n)
// Space : O(1)

/*
Approach 2 - Optimal (Binary Search on 1D)
           - Treat matrix as a flattened sorted array
           - Apply binary search

Intuition -
- Convert 1D index → 2D index:
        - row = mid / n
        - col = mid % n
- This allows binary search without extra space :contentReference[oaicite:1]{index=1}
*/

/*
Algorithm -
          - m = rows, n = cols
          - left = 0, right = m*n - 1
          - while left <= right:
                - mid = left + (right - left)/2
                - row = mid / n
                - col = mid % n
                - if matrix[row][col] == target:
                        - return true
                - else if matrix[row][col] < target:
                        - left = mid + 1
                - else:
                        - right = mid - 1
          - return false
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = m * n - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};

// Time : O(log(m * n))
// Space : O(1)
// treat the 2D matrix as a sorted 1D array and apply binary search.

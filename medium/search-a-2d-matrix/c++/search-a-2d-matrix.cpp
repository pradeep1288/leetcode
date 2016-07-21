// O(m+n)
class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // empty matrix
        if (matrix.size() == 0  || matrix[0].size() == 0)
            return false;
        int row = matrix.size()-1;
        int n = matrix[0].size();
        int col =0;
        while (row>=0 && col<n) {
            if (matrix[row][col] == target)
                return true;
            else if (target < matrix[row][col])
                row--;
            else 
                col++;
        }
        return false;
    }
};

// O(log(m+n))
class Solution {
public:
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        
        return binarySearchMatrix(matrix, 0, matrix.size()-1, 0, matrix[0].size()-1, target);
        
     }
     
     bool binarySearchMatrix(vector<vector<int>> &matrix, int rowStart, int rowEnd, int colStart, int colEnd, int target) {
         if (rowStart>rowEnd || colStart>colEnd)
            return false;
         
         int rowMid = rowStart+(rowEnd-rowStart)/2;
         int colMid = colStart+(colEnd-colStart)/2;
         
         if (target == matrix[rowMid][colMid]) 
            return true;
         else if (target < matrix[rowMid][colMid])
            return (binarySearchMatrix(matrix, rowStart, rowMid-1, colStart, colMid-1, target) ||
                    binarySearchMatrix(matrix, rowStart, rowMid-1, colMid, colEnd, target) ||
                    binarySearchMatrix(matrix, rowMid, rowEnd, colStart, colMid-1, target));
         else 
            return (binarySearchMatrix(matrix, rowMid+1, rowEnd, colStart, colMid-1, target) ||
                    binarySearchMatrix(matrix, rowMid+1, rowEnd, colMid, colEnd, target) ||
                    binarySearchMatrix(matrix, rowMid, rowEnd, colMid+1, colEnd, target));
         
     }
};

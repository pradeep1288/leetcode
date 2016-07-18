class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int uniquePaths[m][n];
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) 
            return 0;
            
        uniquePaths[0][0] = 1;
        
        for (int i=1; i<m;i++) {
            if (obstacleGrid[i][0] != 1) 
                uniquePaths[i][0] = uniquePaths[i-1][0];
            else 
                uniquePaths[i][0] = 0;    
        }
        
        for (int j=1; j<n;j++) {
            if (obstacleGrid[0][j] != 1) 
                uniquePaths[0][j] = uniquePaths[0][j-1];
            else 
                uniquePaths[0][j] = 0;    
        }   
        
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                if (obstacleGrid[i][j] != 1) {
                    uniquePaths[i][j] = uniquePaths[i-1][j] + uniquePaths[i][j-1]; 
                } else {
                    uniquePaths[i][j] = 0;
                }
            }
        }
        return uniquePaths[m-1][n-1];
    }
};

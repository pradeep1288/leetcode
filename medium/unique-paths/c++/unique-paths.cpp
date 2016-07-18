class Solution {
public:
    int uniquePaths(int m, int n) {
        int numPaths[m][n];
        
        for (int i=0; i<m; i++)
            numPaths[i][0] = 1;
        for (int j=0;j<n;j++)
            numPaths[0][j] = 1;
        
        for (int i=1; i<m;i++)
            for(int j=1; j<n;j++)
                numPaths[i][j] = numPaths[i-1][j] + numPaths[i][j-1];
        
        return numPaths[m-1][n-1];
    }
};

// times out if you dfs recursively.
class Solution1 {
public:
    void dfs(vector<vector<char>>& grid, int row, int col, int &numEnemies, int x, int y) {
        if (row<0 || col<0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 'W')
            return;
        
        if (grid[row][col] == 'E')
            numEnemies++;
        dfs(grid,row+x,col+y,numEnemies,x,y);
    }
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int numEnemies = 0;
        int maxEnemies = 0;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (grid[i][j] == '0') {
                    dfs(grid,i,j,numEnemies,0,1);
                    dfs(grid,i,j,numEnemies,0,-1);
                    dfs(grid,i,j,numEnemies,1,0);
                    dfs(grid,i,j,numEnemies,-1,0);
                    if(maxEnemies < numEnemies)
                        maxEnemies = numEnemies;
                    numEnemies = 0;
                }
            }
        }
        return maxEnemies;
    }
};

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int row = grid.size();
        if (!row)
            return 0;
        int col = grid[0].size();
        int result = 0, row_count=0, col_count[col];
        
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (!j || grid[i][j-1] == 'W') {
                    row_count = 0;
                    for (int k=j; k<col && grid[i][k] != 'W';k++) {
                        if (grid[i][k] == 'E')
                            row_count++;
                    }
                }
                
                if (!i || grid[i-1][j] == 'W') {
                    col_count[j] = 0;
                    for (int k=i; k<row && grid[k][j] != 'W';k++) {
                        if (grid[k][j] == 'E')
                            col_count[j]++;
                    }
                }
                
                if (grid[i][j] == '0')
                    result = max(result, row_count + col_count[j]);
            }
        }
        return result;
        
    }
    
};

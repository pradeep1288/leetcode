class Solution {
private:
    int _rowSize;
    int _colSize;
public:
    bool isSafe(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        return (row >=0 && col >=0 && row <_rowSize && col<_colSize && grid[row][col] == '1' && !visited[row][col]);
    }
    
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        visited[row][col] = true;

        vector<pair<int,int>> directions = {{0,1},{0,-1}, {1,0}, {-1,0}};
        
        for (vector<pair<int,int>>::iterator it = directions.begin(); it != directions.end(); it++) {
            if (isSafe(grid, visited, row+it->first, col+it->second))
                DFS(grid, visited, row+it->first, col+it->second);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0)
            return 0;
        _rowSize = grid.size();
        _colSize = grid[0].size();
        vector<vector<bool>> visited(_rowSize, vector<bool>(_colSize, false));
        int count = 0;

        for (int i=0;i<grid.size();i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if ( grid[i][j] == '1'  && !visited[i][j]) {
                    DFS(grid, visited, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
};

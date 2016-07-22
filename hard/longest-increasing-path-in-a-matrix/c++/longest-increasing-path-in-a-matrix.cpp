// This solution times out..
class Solution1 {
public:
    Solution1() {
        _longestPathLen = 0;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        // maintains the nodes we have already seen
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<int> currentPath;
        for(int i=0;i<matrix.size();i++) {
            for (int j=0;j<matrix[0].size();j++) {
                // search for the longest path from every node.
                searchLongestIncreasingPath(matrix, visited, i, j, currentPath);
            }
        }
        
        return _longestPathLen;
    }
    
    void searchLongestIncreasingPath(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int row, int col, vector<int> currentPath) {
        
        // base case
        if (row<0 || col<0 || col >= matrix[0].size() || row >= matrix.size())
            return;
        

        // have we seen the node already ? OR if the next element is smaller than the last element in the path.
        if (visited[row][col])
            return;
        
        if (currentPath.size() != 0) {
            // Ok, we have a increasing element in the matrix.
            if (currentPath.back() < matrix[row][col]) 
                currentPath.push_back(matrix[row][col]);
            else 
                return;
        } else {
            // the first element in the path
            currentPath.push_back(matrix[row][col]);
        }
        visited[row][col] = true;

        // update the longest path found so far.
        if (currentPath.size() > _longestPathLen)
            _longestPathLen = currentPath.size();
        
        // traverse all the directions: up,down,left,right.
        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        
        for (vector<pair<int,int>>::iterator it=directions.begin();it != directions.end(); it++) {
            searchLongestIncreasingPath(matrix, visited, row+it->first, col+it->second, currentPath);
        }
        // unset the visited matrix for the next run.
        visited[row][col] = false;
    }
    
private:
    int _longestPathLen;
};


class Solution {
public:
    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dis) {
        if (dis[x][y]) return dis[x][y];
        
        
        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        
        for (vector<pair<int,int>>::iterator it=directions.begin();it != directions.end(); it++) {
            int nx = x + it->first;
            int ny = y + it->second;
            if (nx >= 0 && ny >= 0 && nx < matrix.size() && ny < matrix[0].size() && matrix[nx][ny] > matrix[x][y]) {
                dis[x][y] = max(dis[x][y], dfs(nx, ny, matrix, dis));
            }
        }
        return ++dis[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (!matrix.size()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dis(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs( i, j, matrix, dis));
            }
        }
        return ans;
    }
};

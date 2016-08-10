class Solution1 {
public:
    // dfs - Runtime error on large board 250x250
    void dfs(vector<vector<char>> &board, int r, int c) {
        if (r<0||r>board.size()-1||c<0||c>board[0].size()-1||board[r][c]!='O')
            return;
        board[r][c]='Y';
        dfs(board, r-1, c);
        dfs(board, r+1, c);
        dfs(board, r, c-1);
        dfs(board, r, c+1);
    }
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board.size()<3 || board[0].size()<3)
            return;
        int r=board.size();
        int c=board[0].size();
        // dfs from boundary to inside
        for (int i=0; i<c; i++) {
            if (board[0][i]=='O')
                dfs(board, 0, i);   // first row
            if (board[r-1][i]=='O')
                dfs(board, r-1, i); // last row
        }
        for (int i=0; i<r; i++) {
            if (board[i][0]=='O')
                dfs(board, i, 0);   // first col
            if (board[i][c-1]=='0')
                dfs(board, i, c-1); // last col
        }
        // scan entire matrix and set values
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j]=='O')
                    board[i][j]='X';
                else if (board[i][j]=='Y')
                    board[i][j]='O';
            }
        }
    }
};

class Solution {
public:
    
    bool isSafe(vector<vector<char>>& board, int row, int col) {
        return (row >= 0 && col >= 0 && row < board.size() && col < board[0].size() && (board[row][col] == 'O'));
    }
    
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board.size()<3 || board[0].size()<3)
            return;
        int r=board.size();
        int c=board[0].size();
        // queues to store row and col indices
        queue<pair<int,int>> q;
        
        // start from boundary
        for (int i=0; i<c; i++) {
            if (board[0][i]=='O') 
                q.push(make_pair(0,i));
            if (board[r-1][i]=='O') 
                q.push(make_pair(r-1,i)); 
        }
        for (int i=0; i<r; i++) {
            if (board[i][0]=='O') 
                q.push(make_pair(i,0));
            if (board[i][c-1]=='O') 
                q.push(make_pair(i,c-1));
        }
        
        vector<pair<int, int>> directions = {{0,-1},{0,1},{1,0},{-1,0}};
        // BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            board[row][col]='Y';
            for (vector<pair<int,int>>::iterator it=directions.begin(); it != directions.end(); it++) {
                if (isSafe(board, row+it->first, col+it->second)) {
                    q.push(make_pair(row+it->first, col+it->second));
                }
            }
        }
 
        // scan entire matrix and set values
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j]=='O') board[i][j]='X';
                else if (board[i][j]=='Y') board[i][j]='O';
            }
        }
    }
};

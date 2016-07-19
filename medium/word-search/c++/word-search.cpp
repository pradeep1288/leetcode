class Solution {
private:
    bool _found;
public:
    Solution() {
        _found = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        string curStr;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i=0;i<board.size();i++) {
            for (int j=0;j<board[0].size();j++) {
                if (_found)
                    return true;
		// lets do DFS only if the first character matches
                if (board[i][j] == word[0]) 
                    findWordDFS(board, visited, i, j, curStr, word);
            }
        }
        return _found;
    }
    
    void findWordDFS(vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c, string curStr, string word) {
        // boundary condition
        if (r<0 || c<0 || r>=board.size() || c>=board[0].size())
            return;
	// if the current string we are looking at is not the prefix of thw word, then just return
        if (word.substr(0, curStr.size()) != curStr)
            return;
	// if we have alredy visited the node
        if (curStr.size() > word.size() || visited[r][c])
            return;
    
        curStr.push_back(board[r][c]);
	// we have found the word, no more search to do.
        if (curStr == word) {
            _found = true;
            return;
        }
        visited[r][c] = true;
        
        vector<pair<int,int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        for (vector<pair<int,int>>::iterator it = direction.begin(); it != direction.end(); it++) {
            if (_found)
                return;
            findWordDFS(board, visited, r+it->first, c+it->second, curStr, word);
        }
        visited[r][c] = false;
    }
};

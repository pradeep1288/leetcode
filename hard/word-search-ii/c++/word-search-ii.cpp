ass TrieNode {
public:
    TrieNode() {
        is_string = false;
    }

public:
    bool is_string;
    unordered_map<char, TrieNode*> leaves;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        for (string::iterator it = word.begin();it<word.end(); it++) {
            if (!cur->leaves.count(*it)) {
                cur->leaves[*it] = new TrieNode();
            }
            cur = cur->leaves[*it];
        }
        cur->is_string = true;
    }

public:
    TrieNode* root;
};

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        string cur;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        Trie trie;
        for (int i =0; i<words.size();i++) {
            trie.insert(words[i]);
        }
        
        for (int i =0; i<board.size();i++) {
            for (int j =0; j<board[0].size();j++) {
                findWordsDFS(board,visited,i,j,trie.root,cur);
            }
        }
        return vector<string>(result.begin(), result.end());
        
    }
    
    void findWordsDFS(vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c, TrieNode* curNode, string currentStr) {
        if (!curNode || r<0 || r >= board.size() || c<0 || c>=board[0].size())
            return;


        if (!curNode->leaves[board[r][c]] || visited[r][c])
            return;
        
        TrieNode* next = curNode->leaves[board[r][c]];
        currentStr.push_back(board[r][c]);


        if (next->is_string)
            result.insert(currentStr);
        visited[r][c] = true;

        vector<pair<int,int>> direction = {{0,1}, {0,-1},{1,0},{-1,0}};
        
        for (vector<pair<int,int>>::iterator it = direction.begin();it<direction.end();it++) {
            findWordsDFS(board,visited,r+it->first,c+it->second,next,currentStr);
        }
        visited[r][c] = false;
    }
private:
    unordered_set<string> result;
};

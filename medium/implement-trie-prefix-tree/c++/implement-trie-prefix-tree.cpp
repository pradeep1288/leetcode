/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        is_string = false;
    }
    
    void setIsString(bool val) {
        is_string = val;
    }
public:
    bool is_string;
    map<char, TrieNode*> leaves;
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
        cur->setIsString(true);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = childSearch(word);
        if (cur) {
            return cur->is_string;
        }
        else
            return false;
    }
    
    TrieNode* childSearch(string word) {
        TrieNode *cur = root;
        for(string::iterator it = word.begin(); it<word.end(); it++) {
            if (cur->leaves.count(*it))
                cur = cur->leaves[*it];
            else 
                return NULL;
        }
        return cur;
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if (childSearch(prefix))
            return true;
        else
            return false;
    }

private:
    TrieNode* root;
};

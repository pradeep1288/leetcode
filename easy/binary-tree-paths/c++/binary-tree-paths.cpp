/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        // If we are passed a empty tree, just return empty vector
        if (root == NULL)
            return result;
        
        // use a stack to maintain the node and path upto that point.
        // Basically do a DFS until every leaf node.
        stack<pair<TreeNode*,string>> nodes;
        nodes.push(make_pair(root,to_string(root->val)));
        while(!nodes.empty()) {
            auto temp = nodes.top();
            nodes.pop();
            if (!temp.first->right && !temp.first->left) {
                result.push_back(temp.second);
            }
            if (temp.first->right) { 
                nodes.push(make_pair(temp.first->right, temp.second + "->" + to_string(temp.first->right->val)));
            }
            if (temp.first->left) {
                nodes.push(make_pair(temp.first->left, temp.second + "->" + to_string(temp.first->left->val)));
            }
        }
        return result;
    }
};

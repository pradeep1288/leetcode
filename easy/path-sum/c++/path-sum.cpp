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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        
        stack<pair<TreeNode*, int>> nodes;
        nodes.push(make_pair(root, root->val));
        
        while(!nodes.empty()) {
            auto temp = nodes.top();
            nodes.pop();
            if (temp.first->right) {
                nodes.push(make_pair(temp.first->right, temp.second+temp.first->right->val));
            }
            if (temp.first->left) {
                nodes.push(make_pair(temp.first->left, temp.second+temp.first->left->val));
            }
            if (!temp.first->right && !temp.first->left && temp.second == sum) {
                return true;
            }
        }
        return false;
    }
    
};

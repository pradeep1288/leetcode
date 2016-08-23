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
    int longestConsecutive(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        return longestConsecutivePath(root, 0, root->val+1);
        
    }
    
    int longestConsecutivePath(TreeNode* root, int currentLength, int parent) {
        if (root == NULL) {
            return currentLength;
        }
        
        if (root->val == parent) {
            currentLength += 1;
        } else {
            currentLength = 1;
        }
        
        int left = longestConsecutivePath(root->left, currentLength, root->val+1);
        int right = longestConsecutivePath(root->right, currentLength, root->val+1);
        
        return max(currentLength, max(left, right));
    }
};

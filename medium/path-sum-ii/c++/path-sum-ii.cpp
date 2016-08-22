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
    struct path {
        int sum;
        vector<int> pathSoFar;
    };
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> allPaths;
        if (root == NULL)
            return allPaths;
        
        stack<pair<TreeNode*, path>> nodes;
        pair<TreeNode*, path> temp;
        temp.first = root;
        temp.second.sum = root->val;
        temp.second.pathSoFar.push_back(root->val);
        nodes.push(temp);

        while(!nodes.empty()) {
            auto temp = nodes.top();
            nodes.pop();
            if (temp.first->right) {
                path tempPath;
                tempPath.sum = temp.first->right->val + temp.second.sum;
                tempPath.pathSoFar = temp.second.pathSoFar;
                tempPath.pathSoFar.push_back(temp.first->right->val);
                nodes.push(make_pair(temp.first->right, tempPath));
            }
            if (temp.first->left) {
                path tempPath;
                tempPath.sum = temp.first->left->val + temp.second.sum;
                tempPath.pathSoFar = temp.second.pathSoFar;
                tempPath.pathSoFar.push_back(temp.first->left->val);
                nodes.push(make_pair(temp.first->left, tempPath));
            }
            if (!temp.first->right && !temp.first->left && temp.second.sum == sum) {
                allPaths.push_back(temp.second.pathSoFar);
            }
        }
        return allPaths;
    }    
};

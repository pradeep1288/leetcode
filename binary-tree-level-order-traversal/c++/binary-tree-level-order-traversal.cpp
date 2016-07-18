/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // Do a BFS through the tree and you will get the level order traveral of the tree.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> treeNodes;
        vector<vector<int>> result;
        
        if (root == NULL)
            return result;

        treeNodes.push(root);
        
        while(!treeNodes.empty()) {
            vector<int> levelNodes;
            int size = treeNodes.size();
            
            // parse all the nodes at the level
            for(int i =0; i<size; i++) {
                levelNodes.push_back(treeNodes.front()->val);
                
                if (treeNodes.front()->left != NULL)
                    treeNodes.push(treeNodes.front()->left);
                if (treeNodes.front()->right != NULL)
                    treeNodes.push(treeNodes.front()->right);
                treeNodes.pop();
            }
            result.push_back(levelNodes);
        }
        return result;
    }
};

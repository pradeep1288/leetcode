class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        // if the root is NULL, return
        if (root == NULL)
            return result;
        queue<TreeNode*> levelNodes;

        // every even level, L-R and every odd level R-L
        int level = 0;
        
        levelNodes.push(root);
        
        while(!levelNodes.empty()) {
            vector<int> tempResult;
            int size = levelNodes.size();
            //left to right.
            for (int i=0; i<size; i++) {
                tempResult.push_back(levelNodes.front()->val);
                if (levelNodes.front()->left)
                    levelNodes.push(levelNodes.front()->left);
                if (levelNodes.front()->right)
                    levelNodes.push(levelNodes.front()->right);
                levelNodes.pop();
            }
            if (level % 2 != 0)
               reverse(tempResult.begin(), tempResult.end());
            level++;
            result.push_back(tempResult);
        }
        return result;
        
    }
};

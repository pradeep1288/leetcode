/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;

        map<UndirectedGraphNode*, UndirectedGraphNode*> oldNew;
        queue<UndirectedGraphNode*> children;
    
        children.push(node);
        
        while(!children.empty()) {
            UndirectedGraphNode *temp = children.front();
            if (!oldNew[temp]) {
                oldNew[temp] = new UndirectedGraphNode(temp->label);
            }
            for (int i=0; i<temp->neighbors.size(); i++) {
                if (!oldNew[temp->neighbors[i]]) {
                    oldNew[temp->neighbors[i]] = new UndirectedGraphNode(temp->neighbors[i]->label);
                    children.push(temp->neighbors[i]);
                }
                oldNew[temp]->neighbors.push_back(oldNew[temp->neighbors[i]]);
            }
            children.pop();
        }
        return oldNew[node];
    }
};
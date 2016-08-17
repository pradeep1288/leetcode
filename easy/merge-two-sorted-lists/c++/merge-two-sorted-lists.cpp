/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // base cases
        if (!l1 && !l2)
            return NULL;
            
        priority_queue<ListNode*, vector<ListNode*>, Comp> priQ;
        ListNode node(0); 
        ListNode *res = &node;
        if (l1 != NULL)
            priQ.push(l1); 
        if (l2 != NULL)
            priQ.push(l2);
        
        while(!priQ.empty()) {
            ListNode* temp = priQ.top();
            priQ.pop();
            
            res->next = temp;
            res = temp;
            
            if(temp->next)
                priQ.push(temp->next);
        }
        
        return node.next;
    }
private:
    struct Comp {
      bool operator() (const ListNode* a, const ListNode* b) {
          return (a->val > b->val);
      }  
    };
};

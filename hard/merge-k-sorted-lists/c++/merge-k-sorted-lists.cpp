// optimal solution using priority queues.
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if (lists.size() == 0)
            return NULL;
        
        priority_queue<ListNode*, vector<ListNode*>, Comp> priQ;
        ListNode tempNode(0);
        ListNode* res = &tempNode;
        
        for (int i=0; i< lists.size(); i++) {
            if (lists[i])
                priQ.push(lists[i]);
        }
        
        while(!priQ.empty()) {
            ListNode *temp = priQ.top();
            priQ.pop();
            res->next = temp;
            res = temp;
            
            if (temp->next)
                priQ.push(temp->next);
            
        }
        return tempNode.next;
    }

private:
    struct Comp {
        bool operator()(const ListNode* a, const ListNode* b) {
            return (a->val > b->val);
        }
    };
};


// brute force
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        ListNode* tmp = NULL;
        ListNode* tmpResult = NULL;
        ListNode* newNode = NULL;
        ListNode* result = NULL;
        for (int i = 0; i < lists.size(); ++i) {
            tmp = lists[i];
            if (NULL == tmp) {
                continue;
            }
            if (NULL == result) {
                result = new ListNode(tmp->val);
                tmp = tmp->next;
            } else {
                if (result->val > tmp->val) {
                    newNode = new ListNode(tmp->val);
                    newNode->next = result;
                    result = newNode;
                    tmp = tmp->next;
                }
            }
            tmpResult = result;
            while (tmp != NULL) {
                while (NULL != tmpResult->next && tmpResult->next->val < tmp->val) {
                    tmpResult = tmpResult->next;
                }
                if (NULL == tmpResult->next) {
                    newNode = new ListNode(tmp->val);
                    tmpResult->next = newNode;
                } else {
                    newNode = new ListNode(tmp->val);
                    newNode->next = tmpResult->next;
                    tmpResult->next = newNode;
                }
                tmp = tmp->next;
            }
        }
        return result;
    }
};

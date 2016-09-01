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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0)
            return head;
        
        ListNode* cur = head;
        ListNode* prev = NULL;
        int numEntries = 0;
        
        while (cur != NULL) {
            numEntries++;
            prev = cur;
            cur = cur->next;
        }
        ListNode* last = prev;
        
        if (k % numEntries == 0)
            return head;
        
        int lastEntry = numEntries - (k % numEntries);
        cur = head;
        while (lastEntry > 0) {
            prev = cur;
            cur = cur->next;
            lastEntry--;
        }
        
        ListNode* result = cur;
        last->next = head;
        prev->next = NULL;
        return result;
    }
};

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        
        int carry = 0;
        ListNode* p = l1;
        ListNode* q = p;
        while(p != NULL & l2 != NULL) {
            if(p->val + l2->val + carry >= 10){
                p->val = (p->val + l2->val + carry) % 10;
                carry = 1;
            }
            else {
                p->val = p->val + l2->val + carry;
                carry = 0;
            }
            q = p;
            p = p->next;
            l2 = l2->next;
        }
        
        if (l2 != NULL) {
            p = q;
            p->next = l2;
            p = p->next;
        }
        
        while(p != NULL){
            if(p->val + carry >= 10){
                p->val = (p->val + carry) % 10;
                carry = 1;
            }
            else {
                p->val = p->val + carry;
                carry = 0;
            }
            q = p;
            p = p->next;
        }
        
        if(carry == 1) {
            ListNode* n = new ListNode(0);
            n->val = 1;
            p = q;
            p->next = n;
        }
        
        return l1;
    }
};

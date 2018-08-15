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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *pre_p; 
        ListNode *p, *q;
        p = head;
        q = p->next;
        head = q;
        pre_p = q;
        do{
            p->next = q->next;
            q->next = p;
            
            
            pre_p = p;
            p = p->next;
            
            if(p != NULL){
                q = p->next;
                if(q != NULL) pre_p->next = q;
                //else   pre_p->next = p;
            }        
        }while(p != NULL && q != NULL);
        
        return head;
    }
};
// solution 2
ListNode* swapPairs(ListNode* head) {
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
}

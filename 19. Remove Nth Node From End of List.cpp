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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1, *p2, *q;
        p1 = head; p2=head; q=head;
        for(int i = 1; i <= n-1; ++i){
            p2 = p2->next;
        }
        bool flag = true;
        while(p2->next != NULL){
            p2 = p2->next;
            p1 = p1->next;
            if(flag){
                flag = false;
                continue;
            }
            q = q->next;
        }
        if(q == p1)
            return head->next;
        q->next = p1->next;
        return head;
    }
};

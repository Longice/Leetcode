/*****by czk ****/
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
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *p1, *p2, *p3, *p4;
        p1 = l1;
        p2 = l2;
        p3 = p1->next;
        p4 = p2->next;
        
        while(p1 != NULL && p2 != NULL)
        {
            if(p1->val < p2->val)
            {
                if(p3 != NULL && p3->val >= p2->val){
                    p2->next = p3;
                    p1->next = p2;
                    p1 = p1->next;
                    p2 = p4;
                    if(p2 != NULL) p4 = p2->next;
                }else if(p3 != NULL && p3->val < p2->val){
                    p1 = p3;
                    p3 = p1->next;
                }else{
                    p1->next = p2;
                    break;
                }
            }
            else if(p1->val > p2->val)
            {
                if(p4 != NULL && p4->val >= p1->val){
                    p1->next = p4;
                    p2->next = p1;
                    p2 = p2->next;
                    p1 = p3;
                    if(p1 != NULL) p3 = p1->next;
                }else if(p4 != NULL && p4->val < p1->val){
                    p2 = p4;
                    p4 = p2->next;
                }else{
                    p2->next = p1;
                    break;
                }
            }
            else
            {
                if(l1->val <= l2->val) {      // 结果链接到l1上
                    p1->next = p2;
                    p1 = p2;
                    p1->next = p3;
                    p2 = p4;
                    if(p2 != NULL) p4 = p2->next;
                };
                if(l1->val > l2->val) {        // 结果链接在l2上
                    p2->next = p1;
                    p2 = p1;
                    p2->next = p4;
                    p1 = p3;
                    if(p1 != NULL) p3 = p1->next;
                }
            }
        }
        if(l1->val <= l2->val) return l1;
        else return l2;
    }
};

/*** other's solution ***/
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

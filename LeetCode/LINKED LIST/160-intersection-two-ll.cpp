/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//initial approach was using nested loops

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        struct ListNode *c1 = headA , *c2 = headB;
        int skipA = 0 , skipB =0 , val = 0;
        while(c1 != NULL ){
            c2 = headB;
            while(c2 != NULL){
                if(c1 == c2){
                    val = c1->val;
                    return c1;
                }
                skipB++;
                c2 = c2->next;
            }
            skipA++;
            c1 = c1->next;
        }
        return NULL;
    }
};

//but learned switching pointers
//which makes both the pointers to take equal steps
//if it has an intersection it will reach till the intersected node or at null

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        struct ListNode *c1 = headA , *c2 = headB;
        while(c1!=c2){
            c1 = (c1 == NULL)?headB:c1->next;
            c2 = (c2== NULL)?headA:c2->next;
        }
        return c1;
    }
};
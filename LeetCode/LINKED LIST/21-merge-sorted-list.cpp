/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*my approach is to make a tail pointer to which we connect the nodes in order 
for that we need one dummy node for reference
after that we will compare 
both the list node val
whichever is small we add that node to tail and increment only that list not the other one
but we need to increment tail no matter what 

after one of the list becomes empty
we select the other node and directly connect it to the tail

Complexity:
Time :O(n+m);
space :O(1);

run time:100%
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        struct ListNode dummy(0);
        struct ListNode *tail = &dummy;

        struct ListNode *l1 = list1 , *l2 = list2;

        while(l1 != NULL && l2 != NULL){
            if(l1->val<=l2->val){
                tail->next = l1;
                l1 = l1->next;
            }else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        } 

        tail->next = (l1 != NULL)? l1:l2;

        return dummy.next;
        
    }
};
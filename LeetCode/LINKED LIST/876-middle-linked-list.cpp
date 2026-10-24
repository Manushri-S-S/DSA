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

 /*approach
 first i traversed the whole list and found the number of nodes present
 then to get the middle i halved it 
 and moved the pointer to the middle node
 
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0 , mid = 0; 
        struct ListNode * current = head;

        while(current != 0){
            count = count+1;
            current = current->next;
        }

        mid = (count/2);

        current = head ;

        for(int i = 0;i<mid;i++){
            current = current -> next;
        }

        return current;
    }
};
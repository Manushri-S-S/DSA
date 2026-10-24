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
 /*my approach
 here we need to remove all the elements where its node val equals to 
 the given val

 im using current to check the node value and prev to keep tracking the
 previous node of current because this a singly LL

 to delete the current node if it satisfies the condition
 i used a temp pointer which holds the current 
 and we can move prev and current
 so that it continues to traverse till the end
 while we can delete the temp 
 */
class Solution {
public:
    
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }

        struct ListNode *current = head , *prev = NULL , *temp;

        while(current!= NULL){
            if(current->val == val){
                if(current == head){
                    temp = current;
                    head = head->next;
                    current = current->next;
                    delete (temp);
                    continue;
                }
                prev->next = current->next;
                temp = current;
                current = current->next;
                delete (temp); 
                continue;
            }
            prev = current;
            current = current->next;


        }
            
        
        return head;
    }
};

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
/*my approach is 
first i converted linked list to array to access the elements easier
then started iteration from the last and used shift operators to get decimal base value */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        struct ListNode * current = head;
        vector<int> ans;
        int sum=0;
        if(head == NULL){
            return 0;
        }
        while(current != NULL){
            ans.push_back(current->val);
            current = current->next;
        }
        int n = ans.size();
        for(int i =n-1;i>=0;i--){
            sum = sum + (ans[i]<<n-i-1);
        }
        return sum;
    }
};
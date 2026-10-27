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
first we find the unique element and over write it in the next node

after traversing till the end
we have unique numbers in the beginning and last unique number till the end
we need to seperate the unique numbers and delete the rest of the list

complexity
time:O(n)
space:O(1)

runtime 100%
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* current = head->next;
        ListNode* prev = head;
        int key = head->val;

        while (current != nullptr) {
            if (current->val != key) {
                prev->next->val = current->val;
                prev = prev->next;
                key = current->val;
            }
            current = current->next;
        }

        ListNode* temp = prev->next;
        prev->next = nullptr;

        while (temp != nullptr) {
            ListNode* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        return head;
    }
};
#include <iostream>
using namespace std;

struct ListNode {
    int data;
    struct ListNode * next;

    ListNode(int val){
        data = val;
        next = NULL;
    }
};

int main (){
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(1);

    ListNode * ans = new ListNode(0);
    ListNode * current = ans;
    int sum = 0 , carry =0;
    while(l1 != NULL || l2 != NULL|| carry !=0 ){
        int x = (l1!=NULL)?l1->data:0;
        int y = (l2!=NULL)?l2->data:0;
        
        sum =  x + y + carry ;
        int dig = sum % 10;
        carry = sum/10;

        current->next = new ListNode(dig);

        if(l1 != NULL)
            l1 = l1->next;
        if(l2 != NULL)
            l2 = l2->next;
        current = current->next;
    }

    current = ans->next;
    while(current != NULL){
        cout<<current->data<<"  ";
        current = current->next;
    }
   
    
    return 0;
    
    
}
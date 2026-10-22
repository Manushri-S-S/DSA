#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode * next;
    ListNode(int x){
        val = x;
        next=NULL;
    }
};

int main (){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    struct ListNode * slow =head , * fast=head , * prev=NULL , * current , *nextnode=NULL;

    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast=fast->next->next;
    }

    //slow will be at the middle of linked list
    //my approach is to cut the linked list to equal parts then reverse the second part
    //and compare the 2 list to check palindrome
    current=slow;
    while(current!=NULL){
        nextnode = current->next;
        current->next=prev;
        prev = current;
        current=nextnode;
    }
    //prev will be at last node 
    //that is first node of reversed half linked list

    struct ListNode *l1 = head, *l2 = prev;

    while(l1!=NULL&&l2!=NULL){
        if(l1->val!= l2->val){
            cout<<"not palindrome";
            return 0;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    cout<<"plaindrome";

    return 0;
}
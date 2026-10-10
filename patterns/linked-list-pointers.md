
TWO POINTERS
this is mainly used when distance is coming to picture

1.switching pointers:
    used to make 2 pointers move the same distance 
    like lets say
    p1 has n unique element before shared path
    p2 has m unique element before shared path

    we are making both the pointers travel m+n distance to reach the shared path

    code:
    in two linked list to find the intersection node
    p1 = headA; p2 = headB;
    p1 = (p1==NULL) ? headB : p1->next;
    p2 = (p2==NULL) ? headA : p2->next;

2.slow and fast pointer:
    
    in linked list we make one pointer at one speed and other at different speed

    lets say one pointer moves one step at a time while the other 2 steps at a time
    so when pointer 2 reaches null the first pointer will be at middle of the linked list
    this approach is used when we need to have m:n ratio distance
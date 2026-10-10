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
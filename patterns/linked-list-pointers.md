
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
    this approach is used when we need to have m:n ratio 
    

    # Linked List Patterns

## 1. Cycle Detection — Floyd's Slow and Fast Pointers

**Problem:** [LeetCode 141 — Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

### Problem Recognition
- A linked list might contain a cycle.
- Normal traversal might continue indefinitely.
- We need to determine whether a node is reachable again by following `next` pointers.

### Pattern: Slow and Fast Pointers

Maintain two pointers:
- `slow` moves one node at a time.
- `fast` moves two nodes at a time.

If a cycle exists, both pointers eventually meet inside the cycle.

If `fast` reaches `nullptr`, the list has no cycle.

### C++ Implementation

```cpp
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
```

### Why Does It Work?

Once both pointers are inside a cycle, `fast` gains one node on `slow` per iteration. Because the cycle is finite, the relative gap eventually becomes zero, and the pointers meet.

**Important:** Compare node addresses (`slow == fast`), not node values (`slow->val == fast->val`). Different nodes can contain the same value.

### Complexity
- Time: `O(n)`
- Auxiliary space: `O(1)`

### Alternative Approach: Visited Set

Maintain a set of node addresses.

1. Visit each node.
2. If its address is already in the set, a cycle exists.
3. Otherwise, insert its address and move to `next`.
4. If `nullptr` is reached, no cycle exists.

Complexity: `O(n)` expected time and `O(n)` auxiliary space.

### Common Mistakes
- Dereferencing `fast->next` before checking that `fast` is non-null.
- Moving `fast` two steps without checking that `fast->next` exists.
- Comparing node values instead of node addresses.
- Resetting a pointer to the other pointer instead of moving it according to the algorithm.
- Forgetting that an empty list and a single-node list without a self-loop have no cycle.

### Derivation Notes

My initial thought was to store visited node addresses and detect a repeated address. This is a valid approach, but it uses extra memory.

The slow-fast technique avoids storing visited nodes.

**Learning gap to practise:** Recognizing when a known technique applies to a new problem, rather than only remembering its implementation.

### Revision Checklist

- [ ] Explain the algorithm without looking at the code.
- [ ] Implement it from a blank editor.
- [ ] Test an empty list, a single node, a two-node acyclic list, a self-loop, and a cycle beginning in the middle.
- [ ] Explain why the loop condition prevents invalid pointer access.
- [ ] State the time and auxiliary-space complexity.
- [ ] Revisit the problem tomorrow and again in a few days.

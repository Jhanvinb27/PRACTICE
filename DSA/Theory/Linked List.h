// 💕 LINKED LIST

// 💗 Definition:
A linked list is a collection of elements (nodes) where each node stores data and a pointer to the next node.
Unlike arrays, elements are not stored continuously in memory; they are connected using links.

// 💗 Intuition:
Think of it like a chain of people holding hands — you cannot jump to the 5th person directly,
you must go one by one.

// 💗 Real-World (SD-1 Level):
In backend systems (e.g., transaction processing):

- Maintain list of recent user actions (login, payment, update)
- Frequent insertions and deletions

Why Linked List:
- Easy insert/delete (no shifting)
- Dynamic size

// 💗 Core Concepts:
- Node (data + pointer)
- Head pointer
- Traversal
- Dynamic memory

// 💗 Operations / Patterns:
1. Traversal
2. Insertion (head, middle, tail)
3. Deletion
4. Reversal
5. Fast & Slow pointers

// 💗 Coding Example:
Problem: Reverse a linked list

Reason:
- Tests pointer manipulation
- Very common interview problem

// 💗 Alternatives + Trade-offs:

Alternative: Array

Why Linked List is better:
- Insert/Delete → O(1)
- No shifting required

Why Array is worse:
- Insert/Delete → O(n)
- Elements must shift

Why Linked List is slower:
- Access index i → O(n)

Reason:
- No direct indexing
- Must traverse node by node

Why not cache-friendly:
- Nodes are scattered in memory
- CPU cannot efficiently prefetch

When Array is better:
- Frequent index-based access
- Example: retrieving kth element

// 💗 Time & Space Complexity:
Operation         Linked List       Array
-----------------------------------------
Access           O(n)              O(1)
Insert (middle)  O(1)              O(n)
Delete (middle)  O(1)              O(n)

// Why Linked List insert/delete is O(1)?
Only pointer changes, no shifting.

// Why Array insert/delete is O(n)?
Elements must be shifted.

// 💗 Visualization:
Linked List = nodes scattered in memory, connected like a chain
node → node → node → node

// 💗 Edge Cases:
- Empty list
- Single node
- Deleting head/tail
- Cycles in list

// 💗 Mistakes to Avoid:
- Losing reference to head
- Incorrect pointer updates
- Not handling NULL cases

// 💗 Interview Tips:
- Draw diagram while explaining
- Clearly track prev, curr, next
- Handle edge cases first

// 💗 Quick Revision:
- Pointer manipulation
- No random access
- Fast & Slow pointer
- Dynamic structure

// 💕 DOUBLY LINKED LIST

// 💗 Definition:
A doubly linked list is a list where each node stores data, a pointer to the next node,
and a pointer to the previous node.
This allows traversal in both directions (forward and backward).

// 💗 Intuition:
Like a train where each coach is connected from both sides — you can move forward or backward easily.

// 💗 Real-World (SD-1 Level):
Used in systems like browser/app navigation:

- Move forward
- Move backward

Why Doubly Linked List:
- Backward movement is needed
- Efficient insert/delete at current position

// 💗 Core Concepts:
- Node (data + next + prev)
- Bidirectional traversal
- Head & tail pointers

// 💗 Operations / Patterns:
1. Forward traversal
2. Backward traversal
3. Insertion
4. Deletion
5. Two-pointer movement

// 💗 Coding Example:
Problem: Design browser history (back & forward)

Reason:
- Need efficient movement in both directions

// 💗 Alternatives + Trade-offs:

Alternative: Singly Linked List

Why Doubly is better:
- Backward traversal → O(1)

Why Singly fails:
- No previous pointer
- Going back → O(n)

Alternative: Array

Why not Array:
- Insert/Delete → O(n)
- Shifting required

When alternatives are better:
- Only forward traversal → Singly LL (less memory)
- Frequent random access → Array

// 💗 Time & Space Complexity:
Operation         Doubly LL        Singly LL        Array
---------------------------------------------------------
Access           O(n)             O(n)             O(1)
Insert/Delete    O(1)             O(1)             O(n)
Backward Move    O(1)             O(n)             O(1)

// Why DLL uses more space?
Extra pointer (prev) per node.

// 💗 Visualization:
node ↔ node ↔ node ↔ node

// 💗 Edge Cases:
- Empty list
- Single node
- Head/tail updates
- Removing last node

// 💗 Mistakes to Avoid:
- Not updating both next and prev
- Breaking links incorrectly
- Null pointer issues

// 💗 Interview Tips:
- Always track prev, curr
- Update both directions carefully
- Draw diagram while explaining

// 💗 Quick Revision:
- Bidirectional
- Extra space
- O(1) insert/delete
- Used for navigation

// 💕 CIRCULAR LINKED LIST

// 💗 Definition:
A circular linked list is a linked list where the last node points back to the first node,
forming a loop. There is no NULL pointer at the end.

// 💗 Intuition:
Like a circle of people holding hands — no start, no end, continuous looping.

// 💗 Real-World (SD-1 Level):
Used in systems like round-robin scheduling:

- Tasks processed one after another
- After last → go back to first

Why Circular Linked List:
- Continuous cycle
- Efficient rotation

// 💗 Core Concepts:
- No NULL pointer
- Loop structure
- Continuous traversal

// 💗 Operations / Patterns:
1. Circular traversal
2. Insertion
3. Deletion
4. Cycle detection

// 💗 Coding Example:
Problem: Josephus Problem

Reason:
- Natural circular traversal

// 💗 Alternatives + Trade-offs:

Alternative: Array

Why Circular LL is better:
- No need to reset index
- Rotation is natural

Why Array is not ideal:
- Requires modulo (i % n)
- Insert/Delete → O(n)

Alternative: Singly Linked List

Why Circular is better:
- No NULL checks
- Continuous traversal

When alternatives are better:
- No circular behavior → normal LL
- Random access needed → Array

// 💗 Time & Space Complexity:
Operation         Circular LL      Array
----------------------------------------
Access           O(n)             O(1)
Insert/Delete    O(1)             O(n)
Traversal        O(n)             O(n)

// Same as linked list, but traversal can loop infinitely if not careful.

// 💗 Visualization:
node → node → node → (back to first node)

// 💗 Edge Cases:
- Single node pointing to itself
- Infinite loops
- Correct stopping condition

// 💗 Mistakes to Avoid:
- Infinite traversal
- Losing head reference
- Incorrect loop termination

// 💗 Interview Tips:
- Always define stopping condition
- Use do-while for traversal
- Think in cycles

// 💗 Quick Revision:
- No NULL
- Circular traversal
- Used in scheduling
- Watch infinite loops

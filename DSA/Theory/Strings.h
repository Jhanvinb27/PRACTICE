// 💕 STRINGS

// 💗 Definition:
A string is a sequence of characters stored in a specific order.
It is stored in contiguous memory (like a char array) and is often immutable in many languages (Java, Python).

// 💗 Intuition:
Strings represent ordered textual data where position matters.
They are optimized for reading, comparing, and pattern-based operations.

// 💗 Real-World (SD-1 Level):
In systems like Oracle ORMB, strings are used in:

- Customer IDs, invoice IDs, transaction logs
- Parsing and validating input data (pattern matching)

Example:
Invoice ID: INV2026XXXX
Extract → year (2026), sequence number

Why Strings:
- Order of characters matters
- Easy to scan, compare, validate patterns

// 💗 Core Concepts:
- Index-based access
- Immutability
- Character-level operations

// 💗 Operations / Patterns:
1. Traversal
2. Substring
3. Pattern matching
4. Two pointers
5. Sliding window

// 💗 Coding Example:
Problem: Check if a string is a palindrome

Reason:
- Character-by-character comparison
- Direct index access simplifies logic

// 💗 Alternatives + Trade-offs:

Alternative 1: Character Array
Why String is preferred:
- Built-in functions (substring, compare, find)
- Cleaner and safer abstraction

Why NOT Char Array:
- Manual handling required
- More error-prone
- No high-level operations

Alternative 2: StringBuilder / StringBuffer
Why String is NOT always good:
- Immutable → every modification creates a new object
- Expensive for repeated updates

Example:
Building logs → repeated concatenation → O(n²)

Why StringBuilder:
- Mutable → modifies same memory
- Faster concatenation

When to Use:
- Heavy modification → StringBuilder
- Read-heavy → String
- Low-level → Char Array

// 💗 Time & Space Complexity:
Operation         String        Char Array     StringBuilder
------------------------------------------------------------
Access           O(1)           O(1)           O(1)
Modify           O(n)           O(1)           O(1)
Concatenation    O(n)           O(n)           O(1) amortized

Why String modify is O(n)?
Because it is immutable → creates a new copy.

Why StringBuilder is faster?
Because it modifies the same memory.

// 💗 Visualization:
String        = Written with ink (rewrite required)
StringBuilder = Written with pencil (editable)

// 💗 Edge Cases:
- Empty string
- Single character
- Very large strings
- Repeated characters

// 💗 Mistakes to Avoid:
- Using String for heavy concatenation
- Ignoring immutability cost
- Index errors

// 💗 Interview Tips:
- Start brute force → optimize
- Mention sliding window / two pointers
- Explain immutability clearly

// 💗 Quick Revision:
- Immutable vs Mutable
- Sliding Window
- Pattern Matching
- StringBuilder


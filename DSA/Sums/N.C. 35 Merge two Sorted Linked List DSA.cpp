// DSA Questions, approach, learnings
/*
Ques - https://leetcode.com/problems/merge-two-sorted-lists/

Merge Two Sorted Linked Lists

You are given the heads of two sorted linked lists head1 and head2.

Merge the two lists into one sorted linked list and return the head of the merged list.

The new list should be made by splicing together the nodes of the first two lists.

Example 1:
Input:
head1 = [1,2,4], head2 = [1,3,4]
Output:
[1,1,2,3,4,4]

Example 2:
Input:
head1 = [], head2 = []
Output:
[]

Constraints:
0 <= number of nodes in both lists <= 50
-100 <= Node.val <= 100
Both lists are sorted in non-decreasing order
*/

/*
Approach:
  - We are NOT using dummy node here
  - We use RECURSION

  - Key Idea:
      At every step:
        - Compare head1 and head2
        - Smaller node becomes the head of merged list
        - Its next pointer is decided by a recursive call

  - Think like this:
      "I will choose the smaller node as head,
       and trust recursion to merge the rest"

  - Base Case:
      If one list becomes empty:
        return the other list (already sorted)

  - Recursive Case:
      If head1 is smaller:
          head1->next = merge(head1->next, head2)
          return head1
      Else:
          head2->next = merge(head1, head2->next)
          return head2
*/

/*
Let's code it:
*/

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {

        // Base Case: If one list is empty, return the other
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }

        // If head1 is smaller or equal
        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }

        // If head2 is smaller
        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }
};

/*
Complexity Analysis:

Time Complexity:
  O(n + m)
  Every node is visited exactly once via recursion

Space Complexity:
  O(n + m)
  Due to recursion stack (call stack depth)
*/

/*
Key Learnings:
  - This is a classic divide-and-conquer / recursion pattern
  - Instead of building list manually, we "delegate work" to recursion
  - Each call decides ONE node and reduces the problem size
  - Base case is extremely important to stop recursion
  - Compared to iterative:
        Iterative → O(1) space
        Recursive → O(n+m) space (stack)
*/
// wrote entirely with hand originally bc udd gaya also suggested 
//that we should use binary search (try using) hehe but aaray nahi ll tha

/*
Ques - Given the beginning of a singly linked list head, reverse the list, and return the new beginning of the list.
*/
/*
Approach - Step 1: Initialize pointers
                        prev = NULL
                        curr = head
                        next = NULL

                        prev → reversed part
                        curr → current node
                        next → to not lose remaining list
          Step 2: Traverse the list
                        While curr != NULL, do:
                        Save next node
                        next = curr->next
                           So we don’t lose the rest of the list
                  Reverse the link
                           curr->next = prev
                  This is the main reversal step
                  We flip the direction of the pointer

                  Move prev forward
                            prev = curr
                            prev grows the reversed list

                  Move curr forward
                            curr = next
                                continue traversal

          Step 3: Repeat until end
                            When curr == NULL, loop ends
                  At this point:
                            prev is the new head of reversed list

          Step 4:Return result 
                                return prev
*/
class Solution{
public:    
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL, *curr = head;
        while (curr != NULL) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

// Time: O(n) // traversal
// Space : O(1) //ony pointers used

/*
Approach - Reverse a Linked List (Using Stack)
                Instead of reversing pointers, we reverse the VALUES of the nodes
                using a stack (LIFO property).

                We first push all node values into a stack,
                then overwrite the linked list in reverse order.
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        stack<int> st;
        ListNode* temp = head;

        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (!st.empty()) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
};

// Time: O(n)
// Space: O(n)

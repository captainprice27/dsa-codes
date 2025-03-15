https://leetcode.com/problems/reverse-linked-list/description/

```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) 
        {
            ListNode* next = curr->next; // Save next node
            curr->next = prev;           // Reverse the link
            prev = curr;                 // Move prev forward
            curr = next;                 // Move curr forward
        }
        
        return prev; // New head
    }
};
```

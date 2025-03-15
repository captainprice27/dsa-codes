https://leetcode.com/problems/sort-list/description/


Intuition
Problem: Sort a singly linked list in O(n log n) time, ideally with O(1) space (though recursive Merge Sort uses O(log n) stack space).
Key Insight: Merge Sort is ideal because:
It naturally divides the list into halves (no need for array-like indexing).
Merging two sorted linked lists is straightforward with O(1) extra space per merge.
Approach:
Divide: Split the list into two halves using the fast-slow pointer technique to find the middle.
Conquer: Recursively sort each half.
Merge: Merge the two sorted halves into one sorted list.
Why Merge Sort?: It’s stable, efficient (O(n log n)), and works well with linked lists since we don’t need random access.
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
    ListNode* sortList(ListNode* head) {
        // Base case: empty or single node
        if (head == nullptr || head->next == nullptr) return head;
        
        // Step 1: Find middle using fast-slow pointers
        ListNode* slow = head;
        ListNode* fast = head->next; // Start fast one step ahead
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Split the list
        ListNode* secondHalf = slow->next;
        slow->next = nullptr; // Break the link
        
        // Step 2: Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(secondHalf);
        
        // Step 3: Merge the sorted halves
        return merge(left, right);
    }
    
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify merging
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        // Merge by comparing values
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        // Attach remaining nodes
        if (l1 != nullptr) curr->next = l1;
        if (l2 != nullptr) curr->next = l2;
        
        return dummy.next;
    }
};
```

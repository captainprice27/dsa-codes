https://leetcode.com/problems/palindrome-linked-list/description/

**THIS APPROACH-1 CODE CONTAINS CONCEPTS OF REVERSING A LIST , FINDING MIDDLE OF LIST AND PALINDROME LINNKED-LIST TOGETHER ...**

>The time complexity of the provided solution is O(n), where n is the number of nodes in the linked list. This is because we traverse the list a constant number of times: once to find the middle, once to reverse the second half, and once to compare the two halves.

>The space complexity is O(1), as we are using a constant amount of extra space regardless of the input size. We only use a few pointers to keep track of the current nodes during the traversal and reversal, without utilizing any additional data structures that scale with the size of the input.
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // Empty or single node is palindrome
        
        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Step 3: Compare first and second halves
        ListNode* p1 = head;    // First half
        ListNode* p2 = prev;    // Second half (new head after reversal)
        while (p2 != nullptr) { // Second half is shorter or equal length
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return true;
    }
};
```

**THIS CODE USES O(N) EXTRA SPACE BY STORING IN AN ARRAY**

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
    bool isPalindrome(ListNode* head)
  {
        // Step 1: Convert linked list to array
        vector<int> arr;
        ListNode* curr = head;
        while (curr != nullptr)
        {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        
        // Step 2: Check palindrome using two pointers
        int left = 0;
        int right = arr.size() - 1;
        while (left < right)
        {
            if (arr[left] != arr[right]) return false;
            left++;
            right--;
        }
        
        return true;
    }
};
```

https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/




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
    ListNode* deleteMiddle(ListNode* head) {
        // Base case: empty or single node
        if (head == nullptr || head->next == nullptr) return nullptr;
        
        // Dummy node to handle head deletion
        ListNode dummy(0, head);
        ListNode* slow = &dummy;
        ListNode* fast = head;
        
        // Move pointers: slow stops before middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Delete middle node
        slow->next = slow->next->next;
        
        return dummy.next;
    }
};

```

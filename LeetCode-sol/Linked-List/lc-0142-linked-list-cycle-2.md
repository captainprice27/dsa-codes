https://leetcode.com/problems/linked-list-cycle-ii/

**YOU HAVE TO FIND THE CYCLE STARTING POINT , THUS DETETING THE CYCLE IN THE PROCESS**
**HENCE NORMAL CYCLE DETECTION CODE IS NOT GIVEN SINCE IT IS ALREADY HERE**

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) // cycle found ********
            {
                // Step 2: Find cycle start
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Cycle start
            }
        }

        return nullptr; // No cycle
    }
};

```

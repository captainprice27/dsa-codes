link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/    
 

discussion : https://leetcode.com/problems/kth-smallest-element-in-a-bst/solutions/3469071/i-bet-you-will-understand-brute-better-optimal-beginner-friendly-c/

>The time complexity of this solution is O(N), where N is the number of nodes in the binary tree. This is because we are performing an in-order traversal of the binary tree, which visits each node exactly once.

>The space complexity of this solution is O(H), where H is the height of the binary tree. This is because the recursive function call stack will have a maximum depth equal to the height of the tree.
>
>
```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        // Initialize counter to track number of nodes visited
        int count = 0;
        // Variable to store the result
        int result = -1;
        
        // Helper function to perform in-order traversal
        function<void(TreeNode*)> inOrder = [&](TreeNode* node) 
        {
            if (node == nullptr || count >= k) return; // Base case
            
            // Traverse the left subtree
            inOrder(node->left);
            
            // Increment the counter when visiting a node
            count++;
            
            // If count equals k, we've found the kth smallest element
            if (count == k) 
            {
                result = node->val;
                return;
            }
            
            // Traverse the right subtree
            inOrder(node->right);
        };
        
        // Start in-order traversal from the root
        inOrder(root);
        
        return result; // Return the kth smallest value
    }
};
```

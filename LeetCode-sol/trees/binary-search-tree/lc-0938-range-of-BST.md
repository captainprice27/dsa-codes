link : https://leetcode.com/problems/range-sum-of-bst/description/

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
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        if (!root) return 0; // Base case: if the node is NULL, return 0
        
        int sum = 0;
        
        if (root->val >= low && root->val <= high) 
        {
            sum += root->val; 
            // Add root's value if it is within the range
        }
        
        if (root->val > low) 
        {
            sum += rangeSumBST(root->left, low, high); 
            // Recursively process the left subtree
        }
        
        if (root->val < high) 
        {
            sum += rangeSumBST(root->right, low, high); 
            // Recursively process the right subtree
        }
        
        return sum;
    }
};
```

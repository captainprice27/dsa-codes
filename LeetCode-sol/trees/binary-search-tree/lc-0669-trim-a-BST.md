link : https://leetcode.com/problems/trim-a-binary-search-tree/description/


>The time complexity of this solution is O(n), where n is the number of nodes in the binary search tree. This is because we are visiting each node in the tree exactly once.

>The space complexity is also O(n) in the worst-case scenario, where the binary search tree is skewed and the recursion stack reaches a depth of n. This is because the space used by the recursion stack is proportional to the height of the tree, which can be n in the worst case.


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


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        if (!root) return NULL;
        
        if (root->val < low) 
        {
            // The entire left subtree is out of range
            return trimBST(root->right, low, high);
        }
        
        if (root->val > high) 
        {
            // The entire right subtree is out of range
            return trimBST(root->left, low, high);
        }
        
        // Node value is within range, trim both subtrees
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
    }
};
```

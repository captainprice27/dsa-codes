link : https://leetcode.com/problems/insert-into-a-binary-search-tree/

>The time complexity of this solution is O(log N) in the average case and O(N) in the worst case, where N is the number of nodes in the binary search tree. This is because in the average case, the algorithm will traverse the tree in a balanced manner, reducing the search space by half at each step. However, in the worst case scenario where the tree is skewed, the algorithm will have to traverse all N nodes.

>The space complexity of this solution is O(log N) in the average case and O(N) in the worst case due to the recursive calls made to insert the new node into the binary search tree. In the average case, the recursion stack will have a height of log N, while in the worst case it can be as high as N if the tree is skewed.


```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        // If the tree is empty, return a new node
        if (root == nullptr) 
        {
            return new TreeNode(val);
        }

        // Otherwise, recur down the tree
        if (val < root->val) 
        {
            root->left = insertIntoBST(root->left, val);
        } 
        else if (val > root->val) 
        {
            root->right = insertIntoBST(root->right, val);
        }

        // Return the (unchanged) node pointer
        return root;
    }
};

```

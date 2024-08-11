link : https://leetcode.com/problems/delete-node-in-a-bst/description/


>The time complexity of this solution is O(log n) on average, where n is the number of nodes in the binary search tree. This is because in the worst case scenario, we may have to traverse the height of the tree to find the node to delete, which is O(log n) for a balanced binary search tree. 

>The space complexity is also O(log n) on average due to the recursive calls made to delete the node. In the worst case scenario, the space complexity could be O(n) if the binary search tree is skewed and the recursion stack reaches a depth of n.

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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (root == nullptr) 
        {
            return root;
        }
        if (key > root->val) 
        {
            root->right = deleteNode(root->right, key);
        } 
        else if (key < root->val) 
        {
            root->left = deleteNode(root->left, key);
        } 
        else 
        {
            if (root->left == nullptr) 
            {
                return root->right;
            } 
            else if (root->right == nullptr) 
            {
                return root->left;
            }
            TreeNode* temp = root->right;
            
            while (temp->left != nullptr) 
            {
                temp = temp->left;
            }
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};

```

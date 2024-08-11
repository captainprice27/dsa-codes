link : https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/

> The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. This is because we are traversing each node of the tree once to find the second minimum value.

>The space complexity of this solution is O(h), where h is the height of the binary tree. This is because the recursive calls will be stored on the call stack up to the height of the tree.
Calculate


```cpp
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        // Base case: If root is null or it doesn't have two children, return -1
        if (!root || !root->left || !root->right) return -1;
        
        int leftVal = root->left->val;
        int rightVal = root->right->val;
        
        // If left child's value equals root's value, find second minimum in left subtree
        if (leftVal == root->val) {
            leftVal = findSecondMinimumValue(root->left);
        }
        
        // If right child's value equals root's value, find second minimum in right subtree
        if (rightVal == root->val) {
            rightVal = findSecondMinimumValue(root->right);
        }
        
        // If both values are valid, return the smaller one
        if (leftVal != -1 && rightVal != -1) {
            return min(leftVal, rightVal);
        }
        
        // If only one of them is valid, return that one
        return (leftVal != -1) ? leftVal : rightVal;
    }
};

```

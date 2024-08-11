link : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/   

discussion : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/solutions/532977/Java-Solution-with-DP-and-DFS-with-critical-cases-handled-and-well-explained-solution/   

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
    int maxSumBST(TreeNode* root) 
    {
        maxSum = 0;
        if (root == NULL) 
        {
            return 0;
        }
        
        helper(root);
        return maxSum;
    }

private:
    int maxSum; // Variable to store the maximum sum of any BST subtree

    // Helper function to return: {sum, isBST, min, max}
    vector<int> helper(TreeNode* node) 
    {
        if (node == NULL) 
        {
            return {0, 1, INT_MAX, INT_MIN}; // {sum, isBST, min, max}
        }

        vector<int> left = helper(node->left);
        vector<int> right = helper(node->right);

        vector<int> ans(4);
        if (left[1] == 1 && right[1] == 1 &&
            (node->left == NULL || node->val > left[3]) &&
            (node->right == NULL || node->val < right[2])) 
            {

            // Current node forms a valid BST
            ans[1] = 1;                              // isBST
            ans[0] = left[0] + right[0] + node->val; // sum
            ans[2] = min(node->val, left[2]);        // min
            ans[3] = max(node->val, right[3]);       // max

            // Update the maximum sum found
            maxSum = max(maxSum, ans[0]);
        } 
        else 
        {
            // Current node does not form a valid BST
            ans[1] = 0; // not a BST
        }

        return ans;
    }
};

```

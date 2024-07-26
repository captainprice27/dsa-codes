link : https://leetcode.com/problems/binary-tree-preorder-traversal/description/ 

### recursive approach

>The time complexity of the preorderTraversal function is O(n), where n is the number of nodes in the binary tree. This is because we visit each node exactly once during the traversal.

>The space complexity of the preorderTraversal function is also O(n) in the worst case. This is because we are using a recursive approach to traverse the tree, which will result in a recursive call stack that can go as deep as the height of the tree. In the worst case scenario where the tree is skewed (i.e., each node has only one child), the height of the tree can be equal to the number of nodes in the tree, leading to O(n) space complexity.

```cpp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void preorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr)
        {
            return;
        }
        result.push_back(node->val);        // Visit root
        preorder(node->left, result);       // Visit left subtree
        preorder(node->right, result);      // Visit right subtree
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> result;
        preorder(root, result);
        return result;
    }
};

```

### iterative approach 

> The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. This is because we visit each node exactly once in a preorder traversal.

>The space complexity is also O(n) in the worst case, where n is the number of nodes in the binary tree. This is because in the worst case scenario, the stack can hold all the nodes of the binary tree.
Calculate

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) 
        {
            return result;
        }

        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) 
        {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            result.push_back(node->val);

            if (node->right) 
            {
                nodeStack.push(node->right); // Right child pushed first
            }
            if (node->left) 
            {
                nodeStack.push(node->left); // Left child pushed second
            }
        }

        return result;
    }
};

```

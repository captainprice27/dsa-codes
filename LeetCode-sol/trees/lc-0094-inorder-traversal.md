link : https://leetcode.com/problems/binary-tree-inorder-traversal/description/

### recursive traversal

>The time complexity of the inorderTraversal function is O(n), where n is the number of nodes in the binary tree. This is because we are visiting each node exactly once in the inorder traversal.

>The space complexity of the inorderTraversal function is also O(n) in the worst case. This is because we are using a recursive approach to perform the inorder traversal, which will consume space on the call stack proportional to the height of the binary tree. In the worst case, the height of the binary tree can be equal to the number of nodes in the tree, leading to O(n) space complexity.

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
    void inorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, result);        // Visit left subtree
        result.push_back(node->val);        // Visit root
        inorder(node->right, result);       // Visit right subtree
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};

```

### iterative approach 

> The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. This is because we visit each node exactly once during the inorder traversal.

> The space complexity is also O(n) in the worst case, where n is the number of nodes in the binary tree. This is because in the worst case scenario, the stack can hold all the nodes of the binary tree if the tree is skewed.

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        TreeNode* current = root;

        while (current != nullptr || !nodeStack.empty()) {
            while (current != nullptr) {
                nodeStack.push(current);
                current = current->left; // Go to the leftmost node
            }
            current = nodeStack.top();
            nodeStack.pop();
            result.push_back(current->val); // Visit the node
            current = current->right; // Visit the right subtree
        }

        return result;
    }
};


```

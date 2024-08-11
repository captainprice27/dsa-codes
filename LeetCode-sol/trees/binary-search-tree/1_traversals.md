### below are definitions and code of binary search tree traversal codes ...

>The time complexity for all three traversal methods (inorder, preorder, postorder) is O(n), where n is the number of nodes in the binary tree. This is because each node is visited exactly once during the traversal process.

>The space complexity for all three traversal methods is also O(n) in the worst case, where n is the number of nodes in the binary tree. This is because the recursive calls for each node in the tree are stored on the call stack, which can potentially reach a depth of n in the worst case scenario (for a skewed tree).

```cpp

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}




void preorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    result.push_back(root->val);
    preorderTraversal(root->left, result);
    preorderTraversal(root->right, result);
}




void postorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    postorderTraversal(root->left, result);
    postorderTraversal(root->right, result);
    result.push_back(root->val);
}

```



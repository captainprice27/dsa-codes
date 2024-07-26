link : https://leetcode.com/problems/binary-tree-postorder-traversal/description/  

### recursive 

>The time complexity of the postorderTraversal function is O(n), where n is the number of nodes in the binary tree. This is because we visit each node exactly once during the traversal process.

>The space complexity is also O(n) in the worst case scenario, where the binary tree is skewed and each node only has one child. This is because the recursive calls will be stored in the call stack, which can grow up to O(n) in this case.


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
    void postorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        postorder(node->left, result);        // Visit left subtree
        postorder(node->right, result);       // Visit right subtree
        result.push_back(node->val);          // Visit root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};


```

#### irerative

>The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. This is because we visit each node exactly once during the traversal process.

>The space complexity is also O(n) in the worst case, where n is the number of nodes in the binary tree. This is because we use a stack to keep track of nodes during the traversal, and in the worst case scenario, the stack can contain all nodes of the binary tree.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        stack<TreeNode*> nodeStack;
        TreeNode* lastVisited = nullptr;
        TreeNode* current = root;

        while (!nodeStack.empty() || current != nullptr) {
            if (current != nullptr) {
                nodeStack.push(current);
                current = current->left; // Move to left child
            } else {
                TreeNode* peekNode = nodeStack.top();
                if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                    current = peekNode->right; // Move to right child
                } else {
                    result.push_back(peekNode->val);
                    lastVisited = nodeStack.top();
                    nodeStack.pop();
                }
            }
        }

        return result;
    }
};

```

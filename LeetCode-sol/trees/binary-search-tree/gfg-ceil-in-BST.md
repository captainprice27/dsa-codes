link : https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

> The time complexity of the findCeil function is O(h), where h is the height of the binary search tree. This is because in the worst case scenario, we may have to traverse the entire height of the tree to find the ceil value. 

>The space complexity is O(1) because we are using a constant amount of extra space for the variables and not using any additional data structures that grow with the input size.

```cpp
/ Solution class containing the findCeil function

    int findCeil(Node* root, int input) 
    {
        int ceil = -1; // Initialize ceil as -1
        
         if (root == NULL) return -1;

        while (root) 
        {
            if (root->data == input) 
            {
                ceil = root->data; // If the node's value is exactly X
                return ceil ; 
            }
            
            if (root->data < input) 
            {
                root = root->right; // Move to right subtree
            } 
            else  // root->data > input 
            {
                ceil = root->data; // Update ceil to current node
                root = root->left; 
                // Move to left subtree to check whether smaller
                // element than curr root exists or not
            }
        }

        return ceil;
    }
```

### nearest smaller element in an array

>The time complexity of this algorithm is O(n) where n is the number of elements in the input array. This is because we are iterating through the array once from right to left, and for each element, we are performing constant time operations (pushing, popping, and checking the top of the stack).

>The space complexity of this algorithm is O(n) as well. This is because we are using a stack to store indices, and in the worst case scenario, the stack can contain all n elements of the input array.

```cpp
vector<int> nextGreaterElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n, -1); // To store the result
    stack<int> s; // Stack to store indices

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; --i) {
        // Pop elements that are not greater than the current element
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }

        // If stack is not empty, the top of the stack is the next greater element
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }

        // Push the current index onto the stack
        s.push(i);
    }

    return result;
}

```

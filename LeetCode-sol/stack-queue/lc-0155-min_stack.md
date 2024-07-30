
link : https://leetcode.com/problems/min-stack/description/

>The time complexity for the push, pop, top, and getMin operations in the MinStack class is O(1). This is because each operation involves only constant time operations such as pushing, popping, or accessing elements from the top of the stacks.

>The space complexity of the MinStack class is O(n), where n is the number of elements stored in the stack. This is because we are using two stacks to store the elements - mainStack and minStack. The space used by these stacks will grow linearly with the number of elements stored in the stack.
Calculate
>
```cpp
class MinStack 
{
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack() 
    {
        minStack.push(INT_MAX);
    }

    void push(int val) 
    {
        mainStack.push(val);
        minStack.push(min(val, minStack.top()));
    }

    void pop() 
    {
        mainStack.pop();
        minStack.pop();
    }

    int top() 
    { 
        return mainStack.top(); 
    }

    int getMin() 
    { 
        return minStack.top(); 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

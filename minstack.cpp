/*
https://leetcode.com/problems/min-stack/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

*/

class MinStack {
private:
    std::stack <int> stack;
    std::stack <int> minstack;
public:
    /** initialize your data structure here. */
    
    MinStack() 
    {
        
    }
    
    void push(int x) 
    {
        if(stack.empty())
        {
           stack.push(x); 
           minstack.push(x);
        }
        else
        {
            stack.push(x);
            minstack.push(min(x,minstack.top()));
            
        }
    }
    
    void pop() 
    {
       stack.pop();
       minstack.pop();
    }
    
    int top() 
    {
      return stack.top();    
    }
    
    int getMin() {
      return minstack.top();   
    }
};
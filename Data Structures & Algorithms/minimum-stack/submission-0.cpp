
class MinStack {
private:
    std::stack<int> stack;
    std::stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push(val);
        if(!minStack.empty())
            val = min(minStack.top(), val) ;
        minStack.push(val);
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

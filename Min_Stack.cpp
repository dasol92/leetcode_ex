// Problem from https://leetcode.com/problems/min-stack/

#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> all_stack, only_min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (only_min.empty() || x <= only_min.top()) {
            only_min.push(x);            
        }
        all_stack.push(x);        
    }
    
    void pop() {        
        if (all_stack.top() == only_min.top()) {
            only_min.pop();
        }
        all_stack.pop();
    }
    
    int top() {
        return all_stack.top();  
    }
    
    int getMin() {
        return only_min.top();        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
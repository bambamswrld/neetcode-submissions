#include <algorithm>
class MinStack {
private:
    std::stack<int> stk;
    std::stack<int> tmp;
    int minVal;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        val = std::min(val, tmp.empty() ? val : tmp.top());
        tmp.push(val);
    }
    
    void pop() {
        stk.pop();
        tmp.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return tmp.top();
    }
};

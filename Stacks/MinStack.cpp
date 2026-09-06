class MinStack {
public:
    stack<int> st;
    stack<int> min;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(min.size()==0 || value < min.top()) min.push(value);
        else min.push(min.top());
    }
    
    void pop() {
        st.pop();
        min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};

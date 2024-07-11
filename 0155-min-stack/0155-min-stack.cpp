class MinStack {
    stack<int> st;
    int mini;
public:
    MinStack() {
        while(st.empty() == false){
            st.pop();
        }

        mini = INT_MAX; // assign mini the highest int value
    }
    
    void push(int val) {
        if(st.empty()){ // if stack is empty push the element and also assign that value to mini
            mini = val;
            st.push(val);
        }else{
            if(val < mini){ // if val is minimum of previous val then modify tthe value and push in to stack
                st.push(2 * val * 1LL - mini);
                mini = val; // but assign mini a original value only
            }else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long element = st.top(); // top element of the stack
        st.pop();

        if(element < mini){ // if element is smaller then mini then again convert that midify value into original value
            mini = 2 * mini - element;
        }
    }
    
    int top() {
        if(st.empty()) return -1;

        long long element = st.top();

        if(element < mini){ // if element is smaller then mini return mini
            return mini;
        }

        return element; // otherwise retuen element

    }
    
    int getMin() {
        return mini;
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
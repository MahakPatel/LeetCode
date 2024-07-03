class MyStack {
public:

// +++++++++++ Using Two Queues  +++++++++++++++
    queue<int> que1;
    queue<int> que2;

    MyStack() {}
    
    void push(int x) {
        que2.push(x);

        while(!que1.empty()){
            que2.push(que1.front());
            que1.pop();
        }

        swap(que1, que2);
    }
    
    int pop() {
        int result = que1.front();
        que1.pop();

        return result;
    }
    
    int top() {
        return que1.front();
    }
    
    bool empty() {
        return que1.empty();
    }


// ++++++++++++ Using One Queues +++++++++++++++++
    // MyStack() { }
    // queue<int> q;

    // void push(int x) {

    //     int s = q.size();
    //     q.push(x);

    //     for (int i = 0; i < s; i++) {
    //         q.push(q.front());
    //         q.pop();
    //     }
    // }

    // int pop() {
    //     int n = q.front();
    //     q.pop();

    //     return n;
    // }

    // int top() { 
    //    return q.front(); 
    // }

    // bool empty() {
    //     return q.empty();
    // }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
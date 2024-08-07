class MyQueue {
    stack<int> st1;
    stack<int> st2;
public:
    
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty()){
            int ele=st2.top();
            st2.pop();
            return ele;
        }
           else{
               while(!st1.empty()){
                   st2.push(st1.top());
                   st1.pop();
               }
               int ele=st2.top();
               st2.pop();
               return ele;
           }
    }
    
    int peek() {
        if(empty()) return 0;
        if(!st2.empty()){
            return st2.top();
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
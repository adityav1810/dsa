class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        
//         if q1 is empty means stack is empty
        if(q1.empty()){
            return -1;
        }
//         pop all elements except for last element from q1 and push into q1

        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int n = q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return n;
        
        
    }
    
    int top() {
        if(q1.empty()){
            return -1;
        }
//         pop all elements except for last element from q1 and push into q1

        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int n = q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        q1.push(n);
        return n;
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
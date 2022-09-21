

void insertAtBottom(stack<int>&st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int num = st.top();
    st.pop();
    insertAtBottom(st,x);
    st.push(num);

}

void solve(stack<int> &st){
     if(st.empty()){
        return;
    }
    int num = st.top();
    st.pop();
    solve(st);
    insertAtBottom(st,num);
}
void reverseStack(stack<int> &st) {
    // Write your code here
 
     solve(st);
    
}
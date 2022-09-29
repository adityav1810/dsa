#include<iostream>
#include<stack>
#include<queue>

using namespace std;




void printStack(stack<int>s){
    if (s.empty()){
        return;
    }
    int x = s.top();
    cout<<x<<" ";

    s.pop();
    printStack(s);
    s.push(x);
}

void printqueue(queue<int>s){
    if (s.empty()){
        return;
    }
    int x = s.front();
    cout<<x<<" ";

    s.pop();
    printqueue(s);
    s.push(x);
}

int main(){
queue<int> q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);
printqueue(q);
cout<<endl;
stack<int> st;
while(!q.empty()){
    int top = q.front();
    q.pop();
    st.push(top);
}
printStack(st);
cout<<endl;
while(!st.empty()){
    int top = st.top();
    st.pop();
    q.push(top);
}
printqueue(q);

    return 0;
}
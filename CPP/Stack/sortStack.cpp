#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int num = st.top();
    cout<<num<<" ";
    st.pop();
    printStack(st);
    st.push(num);
    cout<<endl;

    
}


void sort(stack<int> &st,int x){
//  check if stack empty or x < st.top(); push x
    if(st.empty() || (!st.empty() && x < st.top()))
    {
        st.push(x);
        return;
    }

int top = st.top();
st.pop();
sort(st,x);
st.push(top);


}


void sortStack(stack<int> &st)
{
// check for empty stack
if(st.empty()){
    return;
}
// get top element and pop
int num = st.top();
st.pop();
// recursive call 
sortStack(st);
//  sort
sort(st,num);

    
}





int main(){
    stack<int> st;
    st.push(1);
    st.push(4);
    st.push(9);
    st.push(2);
    st.push(3);
    printStack(st);
    sortStack(st);
    printStack(st);

    return 0;
}
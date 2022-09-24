#include<stack>
#include<iostream>
using namespace std;

void pushstack(stack<int> &st,stack<int> &minst,int data){
    
    if(st.empty()){
        // if stack is empty, put data in st and minst
        st.push(data);
        minst.push(data);
    }
    else{
        int minval = minst.top();
        if(data < minval){
            st.push(data);
            minst.push(data);
        }
        else{
            st.push(minval);
            minst.push(minval);
        }

    }
}

void popstack(stack<int> &st,stack <int> &minst){
    if(st.empty()){
        cout<<"Stack Underflow"<<endl;
        abort();
    }else{
st.pop();
    minst.pop();
    }
    
}

int getmin(stack<int> &st,stack<int> &minst){
    int minval = minst.top();
    return minval;
}


int main(){
    stack<int> st;
    stack<int> minst;
    int minval ;

    pushstack(st,minst,5);
    pushstack(st,minst,2);
    pushstack(st,minst,8);
    pushstack(st,minst,1);
    cout<<getmin(st,minst);
    popstack(st,minst);
cout<<getmin(st,minst);
pushstack(st,minst,1);
cout<<getmin(st,minst);
    return 0;

}
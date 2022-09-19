#include<iostream>
using namespace std;

class Stack{
    public:

    int *arr;
    int top;
    int size;
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data){
        if(size - top >1){
            top ++;
            arr[top] = data;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }

    }
    void pop(){
        if(top >=0){
            top --;
        }
        else{
            cout<<"Stack Underflow "<<endl;
        }

    }
    int peek(){
        if(top >=0 && top <size){
            return arr[top];
        }
        else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }

    }
    bool empty(){
        if(top == 0){
            return false;
        }
        else{
            return true;
        }

    }
    
};



int main(){
 
    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(44);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    
    cout<<st.empty()<<endl;
   return 0;

}
#include<iostream>
#include<stack>

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

int main(){

stack<int> s;
s.push(3);
s.push(4);
s.push(2);
s.push(1);

printStack(s);
// s.pop();



    return 0;
}
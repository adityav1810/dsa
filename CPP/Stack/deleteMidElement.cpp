#include <iostream>
#include <stack>

using namespace std;

int getlen(stack<int> s, int &len)
{
    if (s.empty())
    {
        return 0;
    }

    int temp = s.top();
    len++;
    s.pop();
    getlen(s, len);
    s.push(temp);

    return len;
}



void deleteMid(stack<int> &s , int count, int size){
if(count == size/ 2){
// mid element reached
s.pop();
return;
}
int num = s.top();
s.pop();
deleteMid(s,count+1,size);
s.push(num);



}
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
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);

    s.push(3);
    // s.push(4);
    s.push(5);
    cout<<"Before Deleting mid element :";
    printStack(s);
    cout<<endl;
    int stacklen = 0;
    stacklen = getlen(s, stacklen);
    
    int mid = s.size() / 2;
    
    int count = 0;
    deleteMid(s,count,s.size());
    cout<<"After Deleting mid element :";
    printStack(s);
   
        return 0;
}

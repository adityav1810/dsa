#include <iostream>
#include <stack>
using namespace std;

class SpecialStack
{

    stack<int> st;
    int min;

public:
    void push(int data)
    {
        if (st.empty())
        {
            st.push(data);
            min = data;
        }
        else
        {
            if (data < min)
            {
                st.push(2 * data - min);
                min = data;
            }
            else
            {
                st.push(data);
            }
        }
    }

    int pop()
    {
        if (st.empty())
        {
            cout << "Underflow";
            return -1;
        }
        int curr = st.top();
        st.pop();
        if (curr > min)
        {
            return curr;
        }
        else
        {
            int prevmin = min;
            int val = 2 * min - curr;
            min = val;
            return prevmin;
        }
    }
    int top()
    {
        if (st.empty())
        {
            cout << "Underflow";
            return -1;
        }
        int curr = st.top();
        if (curr < min)
        {
            return min;
        }
        else
        {
            return curr;
        }
    }
    bool isEmpty()
    {
        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int getmin(){
        if(st.empty()){
            return -1;
        }
        else{
            return min;
        }

    }
};


int main(){
SpecialStack st;
st.push(5);
st.push(9);
st.push(2);
st.push(1);
cout<<st.getmin()<<endl;
st.pop();

cout<<st.getmin();

    return 0;

}
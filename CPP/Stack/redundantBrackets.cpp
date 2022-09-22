#include<iostream>
#include<stack>
using namespace std;


bool solve(string s){
    stack<char> st;
    for(int i = 0; i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch =='+'|| ch =='-'|| ch =='*'|| ch =='/'){
            // Add opening bracket or operator to stack
            st.push(ch);
        }else{
            // closing bracket detected
            bool isRedundant = true;

            while(st.top()!='('){
                // traverse stack
                char top = st.top();
// if top is an operator; expression is not redundant
                if(top == '+' || ch =='-'|| ch =='*'|| ch =='/'){
                    isRedundant = false;
    
                }
                // pop for while loop
                st.pop();

            }
            if(isRedundant){
                return true;
            }
        }
    }
    return false;
}



int main(){
    
    string s = "((a+b)*c)";
    cout<<solve(s);




    return 0;
}
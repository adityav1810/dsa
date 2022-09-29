#include <iostream>
#include<bits/stdc++.h>
 #include<vector>
 #include<stack>
using namespace std;
 
vector<string> getSubstrings(string str)
{

 vector<string> res;
    // First loop for starting index
    for (int i = 0; i < str.length(); i++) {
        string subStr;
        // Second loop is generating sub-string
        for (int j = i; j < str.length(); j++) {
            subStr += str[j];
            // cout << subStr << endl;
            res.push_back(subStr);
        }
    }
    return res;
}


int calclen(string expr)
{
    // Declare a stack to hold the previous brackets.
    stack<char> temp;
    for (int i = 0; i < expr.length(); i++) {
        if (temp.empty()) {
             
            // If the stack is empty
            // just push the current bracket
            temp.push(expr[i]);
        }
        else if ((temp.top() == '(' && expr[i] == ')')
                 || (temp.top() == '{' && expr[i] == '}')
                 || (temp.top() == '[' && expr[i] == ']')) {
             
            // If we found any complete pair of bracket
            // then pop
            temp.pop();
        }
        else {
            temp.push(expr[i]);
        }
    }
    if (temp.empty()) {
         
        // If stack is empty return true
        return -1;
    }
    return expr.length();
}
 
int getLen(vector<string> substrings){
    vector<int> l;
    for(int i = 0; i<substrings.size();i++){
        l.push_back(calclen(substrings[i]));
    }

    return *max_element(l.begin(),l.end());



}



// Driver Code
 
int main()
{
    string str = "()())";
    vector <string> subStrings = getSubstrings(str);
    cout<<getLen(subStrings);

    return 0;
    //    this code is contributed by defcdr
}
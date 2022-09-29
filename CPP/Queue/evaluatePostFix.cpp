 int evaluatePostfix(string S)
    {
        
        // Method: traverse though string from left to right
        // if we encounter a number; put it in the stack
        // if we encounter an operation, pop twice; perform operation;put back in stack
        
        
        
        
        stack<int> st;
        
        for(int i = 0; i<S.length();i++){
            char ch = S[i];
            
            // if char is operator
            if(ch == '+' ||ch == '-'  ||ch == '*'  ||ch == '/' ){
                if(ch == '+'){
                    // add
                    int num2 = st.top();
                    st.pop();
                    int num1 =st.top();
                    st.pop();
                    st.push(num1 + num2);
                    
                }else if(ch == '-'){
                    // subtract
                    int num2 = st.top();
                    st.pop();
                    int num1 =st.top();
                    st.pop();
                    st.push(num1 - num2);
                    
                }else if(ch == '*'){
                    // multiply
                    int num2 = st.top();
                    st.pop();
                    int num1 =st.top();
                    st.pop();
                    st.push(num1 * num2);
                }else{
                    // division
                    int num2 = st.top();
                    st.pop();
                    int num1 =st.top();
                    st.pop();
                    st.push(num1 / num2);
                }
                
            }
            else{
                int ia = ch - '0';
                st.push(ia);
            }
            // is char is number
            
            
        }
        return st.top();
        
        
        
        
        
    }
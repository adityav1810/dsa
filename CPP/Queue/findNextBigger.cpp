
vector<long long> nextLargerElement(vector<long long> arr, int n){
     
    // create stack
    stack<int> s;
    s.push(-1);
    // reverse travrse through vector
    for(int i = n-1;i>=0;i--){
        // choose value to compare
        long long k = arr[i];
        // run through stack while next big element found or stack becomes empty
        while(!s.empty() && s.top() <=k){
            s.pop();
        }
            if(s.empty()){
                // no lnext big element found
                arr[i] = -1;
            }
            else{
                // top element is next bigger element
                arr[i] = s.top();

            }
            // push compared element to stack for next iter
            s.push(k);
        }

        
    
        return arr;
    }
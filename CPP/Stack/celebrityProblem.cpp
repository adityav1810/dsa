//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{private:
bool knows(vector<vector<int> >& M, int n , int A, int B){
    if(M[A][B] == 1){
        return true;
    }
    else{
        return false;
    }
    
}

    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // put all people in stack
        stack <int> celebs;
        for(int i = 0;i<n;i++){
            celebs.push(i);
        }
        
        // choose top 2 people and check if they know each other
        while(celebs.size() > 1){
            
            int A = celebs.top();
            celebs.pop();
            int B = celebs.top();
            celebs.pop();
            
            if(knows(M,n,A,B)){
                celebs.push(B);
            }
            else{
                celebs.push(A);
            }
            
        }
        // get last element of stack, he is potential celebrity
        
        int candidate = celebs.top();
        
        // verify if candidate is celebrity
        int rowcount = 0;
        for(int i = 0; i<n;i++){
            if(M[candidate][i] == 0){
                rowcount ++;
            }
        }
        if(rowcount != n)
            return -1;
        
     
        int colcount = 0;
        for(int i = 0;i<n;i++){
            if(M[i][candidate] == 1)
             colcount++;
        }
        if(colcount != n-1){
            return -1;
        }
        

        return candidate;

        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
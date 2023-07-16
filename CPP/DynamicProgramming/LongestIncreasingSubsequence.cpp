//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    int solve(int n,int a[],int currIdx,int prevIdx, vector<vector<int>> &dp ){
        
        if(currIdx == n){
            return 0;
        }
        int include = 0;
        // Handle case where solution already exists
        if(dp[currIdx][prevIdx+1] !=-1){
            return dp[currIdx][prevIdx + 1];
        }
        if(prevIdx == -1 || a[currIdx] > a[prevIdx]){
            include = 1 + solve(n,a,currIdx+1,currIdx,dp);
        }
        int exclude =  solve(n,a,currIdx+1,prevIdx,dp);
        // save solution to DP
        return dp[currIdx][prevIdx+1] =  max(include,exclude);

    }
    int solveTab(int n, int a[]){
        // create 2d DP
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        // Traverse DP
        // currIdx
        for(int i = n-1; i>=0; i--){
            // prevIdx
            
            for(int j = i;j>=-1; j--){
                int include = 0;
                
                if(j==-1 || a[i] > a[j]){
                    include = 1 + dp[i+1][i+1];
                }
                int exclude = dp[i+1][j+1];
                dp[i][j+1] = max(include,exclude);
                
            }
            
        }
        
        return dp[0][0];
    }
    

    int solveOpt(int n,int a[]){
        // 0 length sequence has 0 ans
        if(n== 0){
            return 0;
        }
        
        // Create answer
        vector<int> ans;
        ans.push_back(a[0]);
        
        // for each element in a
        for(int i = 1; i<n; i++){
            // If the element is greater than the last element of the ans array, add it to ans
            if(a[i] > ans.back()){
                ans.push_back(a[i]);
            }else{
                // If its not then find the next biggest number in the ans array and replace it
                int index = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
                ans[index] = a[i];
                
            }
        }
        return ans.size();
        
    }
    
    
    
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       
    // Create 2D DP  
    //   vector<vector<int>> dp(n,vector<int> (n+1,-1));
    //   return solve(n,a,0,-1,dp);
    //   return solveTab(n,a);
       return solveOpt(n,a);
       
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
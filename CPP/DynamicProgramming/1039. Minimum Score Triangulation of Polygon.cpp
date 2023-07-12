class Solution {
public:
    int solve(vector<int> &values,int i, int j,vector<vector<int>> &dp){
        // recursion to TopDown Base case : 2 sided polygon reached
        if(i+1 == j){
            return 0;
        }
        int ans = INT_MAX;
        // recursion to TopDownStep 3: Return value from DP is soln exists
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        for(int k = i+1 ; k<j; k++){
            ans = min(ans,values[i] * values[j]*values[k] + solve(values,i,k,dp)+solve(values,k,j,dp));
        }
        //recursion to TopDown Step 2 : Store ans in DP
        dp[i][j] =ans;
        return dp[i][j];
    }

    int solveBottomUp(vector<int> &values){
        int n = values.size();
        vector<vector<int>> dp(n,vector<int> (n,0));

        // Base Case : 
        for(int i = n-1; i>=0; i--){
            for(int j = i+2; j<n;j++){
                int ans = INT_MAX;
                for(int k = i+1; k<j;k++){
                    ans = min(ans,values[i] * values[j] * values[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }

        }
        return dp[0][n-1];



    }




    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        //recursion to TopDown  Step 1: Create DP
        vector<vector<int>> dp(n,vector<int> (n,-1));
        // return solve(values,0,n-1,dp);
        return solveBottomUp(values);
    }
};
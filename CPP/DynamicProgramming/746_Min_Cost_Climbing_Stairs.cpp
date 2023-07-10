class Solution {
public:

// Top Down Approach, Recursion + Memoization
// int solve(vector<int>& cost, int n,vector<int> &dp){
//     if(n<=1){
//         return cost[n];
//     }
//     // Step 3: if dp[n]!=-1, return dp[n]
//     if(dp[n]!=-1){
//         return dp[n];
//     }

//     // step 2 : store recursive solution
//     dp[n]= cost[n] + min(solve(cost,n-1,dp),solve(cost,n-2,dp));
//     return dp[n];
// }
int solve(vector<int> &cost,int n){
    vector<int> dp(n+1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i=2; i<n;i++){
        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // Step 1 : Create DP array
        // vector<int> dp(n+1,-1);

        int ans = solve(cost,n);
        return ans;
        
    }
};
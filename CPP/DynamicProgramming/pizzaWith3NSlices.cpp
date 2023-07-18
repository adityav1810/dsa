class Solution {
public:

int solve(int idx,vector<int> &slices,int n,int endIdx,vector<vector<int>>&dp){
    if(n==0 || idx >endIdx){
        return 0;
    }
    // Step 2 return present ans
    if(dp[idx][n]!=-1){
        return dp[idx][n];
    }


    // include or not include

    int include = slices[idx] + solve(idx + 2, slices,n-1,endIdx,dp);
    int exclude = solve(idx +1,slices,n,endIdx,dp);
    // Step 3 : Save answer in DP 
    dp[idx][n]= max(include,exclude);
    return dp[idx][n];
}


int solveTab(vector<int>& slices){
    int k = slices.size();
    // Create new 2D DP
    vector<vector<int>> dp(k+2,vector<int>(k+2,0));

    for(int idx = k-2;idx>=0;idx-- ){
        for(int n = 1;n<=k/3;n++){

            int include = slices[idx] + dp[idx + 2][n-1];
            int exclude = dp[idx+1][n];
            dp[idx][n] = max(include,exclude);

        }
    }
    int sol1 = dp[0][k/3];

    vector<vector<int>> dp2(k+2,vector<int>(k+2,0));

    for(int idx = k-1;idx>=1;idx-- ){
        for(int n = 1;n<=k/3;n++){

            int include = slices[idx] + dp2[idx + 2][n-1];
            int exclude = dp2[idx+1][n];
            dp2[idx][n] = max(include,exclude);

        }
    }

    int sol2 = dp2[1][k/3];

    return max(sol1,sol2);


    



}


    int maxSizeSlices(vector<int>& slices) {

        // int k = slices.size();
        // // Create new DP
        // vector<vector<int>> dp (k+1,vector(k+1,-1));
        // int opt1 = solve(0,slices,k/3,k-2,dp);
        // vector<vector<int>> dp2 (k+1,vector(k+1,-1));
        // int opt2 = solve(1,slices,k/3,k-1,dp2);
        // return max(opt1,opt2);
        return solveTab(slices);






    }
};
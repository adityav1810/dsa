class Solution {
public:
int solveRec(vector<int>& satisfaction , int idx , int time){
    if(idx == satisfaction.size()){
        return 0;
    }
    int include = (satisfaction[idx] * ( time + 1) )+ solveRec(satisfaction,idx+1,time+1);
    int exclude = solveRec(satisfaction,idx+1,time);
    return max(include,exclude);
}
int solveMem(vector<int>& satisfaction , int idx , int time,vector<vector<int>> &dp){
    if(idx == satisfaction.size()){
        return 0;
    }
    if(dp[idx][time] !=-1){
        return dp[idx][time];

    }
    int include = (satisfaction[idx] * ( time + 1) )+ solveMem(satisfaction,idx+1,time+1,dp);
    int exclude = solveMem(satisfaction,idx+1,time,dp);
    dp[idx][time] = max(include,exclude);
    return dp[idx][time];
}
int solveTab(vector<int>& satisfaction){
    // create DP array
    int n = satisfaction.size();
    vector<vector<int>> dp(n+1 ,vector<int>(n + 1 , 0));

    for(int i = n-1; i>=0; i--){
        for(int t = i; t>=0; t--){
    int include = (satisfaction[i] * ( t + 1) )+ dp[i+1][t+1];
    int exclude = dp[i+1][t];
    dp[i][t] = max(include,exclude);
            
        }
    }    
    return dp[0][0];
}





    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(satisfaction.size() + 1 ,vector<int>(satisfaction.size() + 1 , -1));
        // return solveRec(satisfaction,0,0);
        // return solveMem(satisfaction,0,0,dp);
        return solveTab(satisfaction);
    }
};
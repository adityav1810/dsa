class Solution {
public:
int mod = 1e9+7;
 int func(int n,int k, int target,vector<vector<int>>& dp){
        if(n==0){
            if(target==0)return 1;
            return 0;
        }
        if(dp[n][target]!=-1)return dp[n][target];
        int res=0;
        for(int i=1;i<=k;i++){
            if(i>target)break;
            res+=func(n-1,k,target-i,dp);
        }
        return dp[n][target]=res%mod;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
		vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return func(n,k,target,dp);
    }
};
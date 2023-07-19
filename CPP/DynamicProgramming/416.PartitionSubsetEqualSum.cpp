class Solution {
public:
bool solve(int idx,vector<int>&nums,int target,vector<vector<int>> &dp){
    // Base cases
    if(target == 0){
        return true;
    }
    if(idx>=nums.size() || target<0){
        return false;
    }
    if(dp[idx][target]!=-1){
        return dp[idx][target];
    }

    bool include = solve(idx+1,nums,target - nums[idx],dp);
    bool exclude = solve(idx+1,nums,target,dp);
    dp[idx][target] = (include || exclude);
    return dp[idx][target];

}

bool solveTab(vector<int>&nums,int target){
    int n = nums.size();
    vector<vector<int>> dp ( n+1,vector<int>(target+1,0));
    for(int i = 0; i<=n; i++){
        dp[i][0] = 1;
    }

    for(int i = n-1 ; i>=0;i--){
        for(int j = 0; j<=target;j++){
            bool incl =0;
            if(j-nums[i]>=0){
                incl = dp[i+1][j-nums[i]];
            }
            bool excl = dp[i+1][j];
            dp[i][j] = incl || excl;

        }
    }
    return dp[0][target];
}
bool solveTabSO(vector<int>&nums,int target){
    int n = nums.size();
    vector<vector<int>> dp ( n+1,vector<int>(target+1,0));

    vector<int> curr(target +1,0);
    vector<int> next (target +1,0);
    curr[0] = 1;
    next[0] = 1;

    for(int i = n-1 ; i>=0;i--){
        for(int j = 0; j<=target;j++){
            bool incl =0;
            if(j-nums[i]>=0){
                incl = next[j-nums[i]];
            }
            bool excl = next[j];
            curr[j] = incl || excl;
           

        }
         next = curr;
    }
    return curr[target];
}



    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int i = 0; i<nums.size();i++){
            target +=nums[i];
        }
        bool res = false;
        // vector<vector<int>> dp (nums.size(),vector<int>(target+1,-1));
        if(target %2 == 0){
            // res = solve(0,nums,target/2,dp);
            res = solveTab(nums,target/2);
        }
        return res;
        
    }
};

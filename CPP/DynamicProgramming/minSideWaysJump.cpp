class Solution {
public:
    // int solve(int currPos, int currLane,vector<int>& obstacles, vector<vector<int>>&dp){
    //     // Base Case : Curr  == n
    //     if(currPos == obstacles.size() - 1){
    //         return 0;
    //     }

    //     // currPos + 1 does not have an obstacle
    //     if(obstacles[currPos + 1] !=currLane ){
    //         return solve(currPos+1,currLane,obstacles,dp);

    //     }
    //     // TopDown Step 2 : Check if ans exists
    //     if(dp[currLane][currPos] !=-1){
    //         return dp[currLane][currPos];
    //     }
    //     else{
    //         int ans = INT_MAX;
    //         // currPos has an obstacle
    //         for(int i = 1; i<=3; i++){
    //             // only look at lanes other than the current Lane and does not have obstacle
    //             if(currLane != i && obstacles[currPos] != i){
    //                 ans = min(ans, 1+solve(currPos,i,obstacles,dp));
    //             }
                
    //         }
    //         // Top Down Step 3: Store ans
    //         dp[currLane][currPos] = ans;
    //         return dp[currLane][currPos];

    //     }   
    // }
    int solve(vector<int> &obstacles){
        int numLanes =4;
        int n = obstacles.size() - 1;
        // Create DP array
        vector<vector<int>> dp(numLanes,vector<int>(obstacles.size() , 1e9));

        // Step 2 : Analyze base case
        for(int i = 0; i<numLanes; i++){
            dp[i][n] = 0;
        }
        //  Step 3 : reverse topdown

        for(int pos =n - 1; pos>=0; pos-- ){
            for(int lane = 1; lane<=3; lane++){
                        if(obstacles[pos+ 1] !=lane ){
            dp[lane][pos] = dp[lane][pos+1];

        }
        else{
             int ans = 1e9;
            // currPos has an obstacle
            for(int i = 1; i<=3; i++){
                // only look at lanes other than the current Lane and does not have obstacle
                if(lane != i && obstacles[pos] != i){
                    ans = min(ans, 1+dp[i][pos+1]);
                }
                
            }
            // Top Down Step 3: Store ans
            dp[lane][pos] = ans;

        }


            }
        }
        return(min(dp[2][0],min(dp[1][0]+1,dp[3][0]+1)));


    }








    int minSideJumps(vector<int>& obstacles) {
        int numLanes = 4;

        // Top Down : S1 : Create DP
        // vector<vector<int>> dp(numLanes,vector<int>(obstacles.size() , -1));
        // return solve(0,2,obstacles,dp);
        return solve(obstacles);
        
    }
};
class Solution {
public:
int solve(int n , vector<int>& days, vector<int>& costs,int index,vector<int> &dp){
    // Base Case
    if(index >= n){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }

    // 1 Day pass
    int d1 = costs[0] + solve(n,days,costs,index+1,dp);
    int i ;

    // 7 Day pass
    for(i = index; i<n && days[i]< days[index] +7 ; i++);

    int d7 = costs[1] + solve(n,days,costs,i,dp);


    // 30 Day pass
    for(i = index; i<n && days[i] < days[index] +30 ; i++);
    int d30 = costs[2] + solve(n,days,costs, i,dp);

    dp[index] = min(d1,min(d7,d30));
    return dp[index];


}


int solveTab(vector<int>& days, vector<int>& costs){

    vector<int> dp(days.size()+1,INT_MAX);
    dp[days.size()] =0;

    for(int index = days.size()-1;index>=0;index--){

    // 1 Day pass
    int d1 = costs[0] + dp[index+1];
    int i ;

    // 7 Day pass
    for(i = index; i<days.size() && days[i]< days[index] +7 ; i++);

    int d7 = costs[1] + dp[i];


    // 30 Day pass
    for(i = index; i<days.size() && days[i] < days[index] +30 ; i++);
    int d30 = costs[2] + dp[i];
    dp[index] = min(d1,min(d7,d30));
    }

    return dp[0];



}



    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Create vector
        // vector<int> dp(days.size()+1,-1);
        // return solve(days.size(),days,costs,0,dp);
        return solveTab(days,costs);
    }
};
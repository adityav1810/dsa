#include <bits/stdc++.h> 
#include<vector>
// int solve(vector<int>& weight, vector<int> &value, int index, int maxWeight){

// 	// Base case
// 	if(index==0){
// 		if(weight[0] <=maxWeight){
// 			return value[0];
// 		}else{
// 			return 0;
// 		}
// 	}
// 	int include = 0;

// 	if(weight[index] <=maxWeight){
// 		include = value[index] + solve(weight,value,index-1,maxWeight - weight[index]);
// 	}
// 	int exclude = solve(weight,value,index-1,maxWeight);
// 	return max(include,exclude);

// }
// int solve(vector<int>& weight, vector<int> &value, 
// 			int index, int maxWeight,vector<vector<int>> &dp){

// 	// Base case
// 	if(index==0){
// 		if(weight[0] <=maxWeight){
// 			return value[0];
// 		}else{
// 			return 0;
// 		}
// 	}
// // Step 3:  Return answer if existing in DP
// 	if(dp[index][maxWeight]!=-1){
// 		return dp[index][maxWeight];
// 	}
// 	int include = 0;

// 	if(weight[index] <=maxWeight){
// 		include = value[index] + solve(weight,value,index-1,maxWeight - weight[index],dp);
// 	}
// 	int exclude = solve(weight,value,index-1,maxWeight,dp);
// // Step 2: Store Ans in dp
// 	dp[index][maxWeight] = max(include,exclude);
// 	return dp[index][maxWeight];
// }




int solve(vector<int>& weight, vector<int> &value, int index, int maxWeight){
	// Create DP
	vector<vector<int>>dp(index,vector<int>(maxWeight + 1,0));
	// Analyse Base Case
for(int w = weight[0]; w<=maxWeight; w++){

		if(weight[0]<=maxWeight){
			dp[0][w] = value[0];
		}else{
			dp[0][w] = 0;
		}
}

for(int i = 1; i<index; i++){
	for(int w = 0; w<=maxWeight; w++){
		int include = 0;
		if(weight[i] <= w){
			include = value[i] + dp[i-1][w-weight[i]];
		}
		int exclude = dp[i-1][w];
		dp[i][w] = max(include,exclude);
	}
}
return dp[index-1][maxWeight];

	}




int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	
	return solve(weight,value,n,maxWeight);
}
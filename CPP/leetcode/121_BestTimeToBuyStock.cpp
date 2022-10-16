class Solution {
public:
    int maxProfit(vector<int>& prices) {
//         Brute Force ;  TC : o(n^2) : TLE
        int maxprofit = -1;
        for(int i = 0;i<prices.size();i++){
            for(int j = prices.size() -1; j>=i;j--){
                int profit = prices[j] - prices[i];
                if(profit > maxprofit){
                    maxprofit = profit;
                }
            }
        }
        return maxprofit;
        
    }
};

/*
 def maxProfit(self, prices: List[int]) -> int:
        // DP SOLUTION IN PYTHON

        dp = [ [0] * len(prices) for _ in range(len(prices))]
        
        for i in range(len(prices)):
            for j in range(i+1,len(prices)):
                dp[i][j] = prices[j] - prices[i]
            
            
        
        
        return max(map(max, dp))
        
*/



    int maxProfit(vector<int>& prices) {
//         Optimized Approach ;  TC : o(n) 
        int maxprofit = 0;
        int minprice = INT_MAX;
        for(int i = 0;i<prices.size();i++){
            minprice = min(prices[i] , minprice);
            int profit = prices[i] - minprice;
            maxprofit = max(maxprofit , profit);
            }
        }
        return maxprofit;
        
    }
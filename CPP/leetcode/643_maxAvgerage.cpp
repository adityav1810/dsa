    double findMaxAverage(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int globalAvg = INT_MIN;
        int sum=0.0;
        for(int i = 0; i<k;i++){
            sum += nums[i];
        }
        globalAvg = sum;

        for(int i = 1; i<=nums.size()-k; i++){
            sum -=nums[i-1];
            sum+= nums[i+k-1];
            globalAvg = max(globalAvg,sum);
        }
        double ans = (double)globalAvg / (double)k;

        return ans;
    }
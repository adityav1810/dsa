int minSubArrayLen(int target, vector<int>& nums) {
        int windowSize = INT_MAX;
        int windowSum = 0;
        int windowStartIdx = 0;

        for(int windowEndIdx = 0; windowEndIdx <nums.size(); windowEndIdx++){
            windowSum += nums[windowEndIdx];
            while(windowSum >= target){
                windowSize = min(windowSize,windowEndIdx - windowStartIdx + 1);
                windowSum -= nums[windowStartIdx];
                windowStartIdx++;
            }
        }
        if(windowSize > nums.size()){
            return 0;
        }else{
            return windowSize;

        }
        
         
    }
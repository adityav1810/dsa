 #include<vector> 
  
   int findMaxConsecutiveOnes(vector<int>& nums) {
        int start = 0;
        int globalMax = 0;
        int end = 0;
        int count = 0;
        while(end < nums.size()){
        
        // # Expand the window
        //     # Process the current window   
        if(nums[end] !=0){
            count ++;
            globalMax = max(globalMax,count);

        }else{
                   // # Meet the condition to stop expansion
        //     # Contract the window
            count = 0;
        }
         end++;
        }
return globalMax;
    }

    int main(){
        vector<int> nums = (5,2);
        cout<<findMaxConsecutiveOnes(nums);
        return 0;
    }
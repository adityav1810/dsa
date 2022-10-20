vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    // Brute force, TC o(n)
        int wstart = 0;
        int wend = k;
        vector<int> res;
        while(wend <= nums.size()){
            int maxnum = *max_element(nums.begin() + wstart , nums.begin()+wend);
            
            res.push_back(maxnum);
            wstart ++;
            wend ++;
        }
        return res;
    }
class Solution {
public:
 static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

   int solve(vector<vector<int>>& envelopes){
       sort(envelopes.begin(),envelopes.end(),cmp);

        int n = envelopes.size();
        if(n == 0){
            return 0;
        }
        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for(int i = 1; i<n;i++){
            // if envelope can fit in ans

          
  
                int idx = lower_bound(ans.begin(),ans.end() , envelopes[i][1]) - ans.begin();
                if(idx >=ans.size()){
                    ans.push_back(envelopes[i][1]);
                }else{
                    ans[idx] = envelopes[i][1];

                }
                

        }
        return ans.size();

    }




    int maxEnvelopes(vector<vector<int>>& envelopes) {
        return solve(envelopes);
    }
};
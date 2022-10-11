class Solution {
public:
    // Brute Force Solution

    int getArea(int h,int w){
        return h * w;
    }
    int maxArea(vector<int>& arr) {
        int maxArea = INT_MIN;
        int l = 0;
        int r = arr.size()-1;
        
        for(int l = 0;l<arr.size();l++){
            for(int r = arr.size()-1;r>=l;r--){
            int area = getArea(min(arr[r],arr[l]),r-l);
                cout<<area<<endl;
                if(area > maxArea){
                    maxArea = area;
                }
                
                
            }
        }
        
        
        return maxArea;
        
        
    }
};


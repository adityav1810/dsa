class Solution {
public:
    
    int recurse(int n){
        if (n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        else{
            return(recurse(n-1) + recurse(n-2));
        }
    }
    
    int climbStairs(int n) {
    if (n==1){
        return 1;
    }  
    else if(n ==2){
        return 2;
    }
        else{
            return recurse(n-1) + recurse(n-2);
        }
        
        
        
    }
};
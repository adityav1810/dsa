bool unique(string s) {
    sort(s.begin(),s.end());
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])
        {
            return false;
            break;
        }
    }
    return true;
}

    int countGoodSubstrings(string s) {
        // sliding window 

        int count  =0;
        int k = 3;
        if(s.length() >=3){
            for(int start = 0; start < s.length()-k+1;start ++){
            if(unique(s.substr(start, k))){
                count ++;
            }
            
        }
        return count;

        }
        else{
            return 0;
        }
        
        
    }
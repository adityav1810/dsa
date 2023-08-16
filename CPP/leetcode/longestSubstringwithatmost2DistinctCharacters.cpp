int lengthOfLongestSubstring(string s) {
    // Write your code here.
    int start = 0; 
    int end = 0;
    int result = 0;
    unordered_map<char,int> m;
    
    while(end < s.length()){
        
        while( end < s.length() && m.size() <=2){
            m[s[end]] ++;
            end++;
            if(m.size()<=2){
            result = max(result,end-start);    
            }
            
        }
        while(m.size()>2){
         if(m[s[start]] == 1)   {
             m.erase(s[start]);
         }else{
             m[s[start]] --;
         }
         start ++;
        }
    }
    return result;
}
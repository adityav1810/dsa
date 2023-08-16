int lengthOfLongestSubstring(string s) {
        int start = 0;
        int subsize  =0;
        unordered_map<char,int> map;
        string substring= "";

        for(int end = 0; end <s.length(); end ++){
        //   Have we seen s[end] before and is map[s[end]] in substrinf range? 
        // NO
        if(map.count(s[end]) == 0 || map[s[end]] <start){
            // update id of s[end] in map
            map[s[end]] = end;
            // update size of substring
            subsize = max(subsize,end-start +1);
            substring+=s[end];
        }
        // YES
        else{
            // shrink window
            start = map[s[end]] +1;
            // update id of s[end] in map
            map[s[end]] = end;
           
        }
        }
        cout<<substring;
    
        return subsize;
    }
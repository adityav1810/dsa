int maxConsecutiveAnswers(string answerKey, int k) {
        int start =0;
        int end = 0;
        int maxVal = INT_MIN;

        unordered_map<char,int> mp;
        mp['T'] = 0;
        mp['F'] = 0;

        while(end < answerKey.length()){
            if(answerKey[end] =='T'){
                mp['T'] ++;
            }else{
                mp['F'] ++;
            }
            while(mp['T'] > k && mp['F'] > k){
                if(answerKey[start] == 'T'){
                mp['T']-- ;
            }else{
                mp['F'] --;
            }
            start ++;
            
            }
            maxVal = max(maxVal,end-start + 1);

            end++;

        }
        return maxVal;
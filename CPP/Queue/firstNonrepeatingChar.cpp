class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int> hmap;
		    queue<int> q;
		    string ans ="";
		    
		    for(int i = 0; i < A.length();i++){
		      //  traverse through string
		        char ch = A[i];
		      //  add count to map
		      
		        hmap[ch] ++;
		      
		      // add char to queue 
		      q.push(ch);
		      while(!q.empty()){
		          
		          if(hmap[q.front()] >1){
		              q.pop();
		          }
		          else{
		              ans.push_back(q.front());
		              break;
		          }
		      }
		       if(q.empty()){
		            ans.push_back('#');
		        } 
		}
		       
		 return ans;   
		}

};
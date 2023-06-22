//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    
    
    bool isValid(int r, int c , int n){
        // if r and c are valid idx on the chess board return true else return false
    if(r>=0 && r<n && c >=0 && c<n){
        return true;
    }else{
        return false;
    }
    
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here

	    int knightRow = KnightPos[0]-1;
	    int knightCol = KnightPos[1]-1;
	    
	    int targetRow = TargetPos[0]-1;
	    int targetCol = TargetPos[1]-1;
	    
	    int numSteps = 0;
	    int chessboard[N][N]={0};
	    
	    vector<vector<int>> visited( N , vector<int> (N, 0));
	    
	    visited[knightRow][knightCol] = 1;
	    
	    vector<int> delRow={2,1,-1,-2,-2,-1,1,2};
	    vector<int> delCol={1,2,2,1,-1,-2,-2,-1};
	    
	    if(knightRow<0 || knightCol < 0){
	        return -1;
	    }
	    
	    queue<pair<int,pair<int,int>>> q;
	    q.push({numSteps,{knightRow,knightCol}});
	    
	    while(!q.empty()){
	        int tStep = q.front().first + 1;
	        int r = q.front().second.first;
	        int c = q.front().second.second;
	        q.pop();
	        
	        for(int i = 0; i<8; i++){
	            if(isValid(r+delRow[i],c+delCol[i],N) && !visited[r+delRow[i]][c+delCol[i]]){
	                visited[r+delRow[i]][c+delCol[i]] = 1;
	                q.push({tStep,{r+delRow[i],c+delCol[i]}});
	                
	                
	                if(r+delRow[i] == targetRow && c+delCol[i] == targetCol){
	                numSteps = max(numSteps,tStep);    
	                }
	            }
	        }
	    }
	    if(numSteps == INT_MAX){
	        return -1;
	    }
	    
	    
	    return numSteps;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
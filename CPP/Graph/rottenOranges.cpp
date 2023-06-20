//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited( rows , vector<int> (cols, 0)); 
        int numFreshOranges = 0;
        
        for(int row = 0; row<rows;row++){
            for(int col = 0; col<cols;col++){
                if(grid[row][col] == 2){
                    q.push({{row,col},0});
                    visited[row][col] = 2;
                }
                    
                    if(grid[row][col] == 1){
                        numFreshOranges +=1;
                    }
                
            }
        }
        int time = 0;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        int numOrangesRottened = 0;
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);
            
            for(int i = 0; i<4;i++){
                int tempRow = row+delRow[i];
                int tempCol = col+delCol[i];
                if(tempRow>=0 && tempRow<rows && tempCol >=0 && tempCol<cols 
                && visited[tempRow][tempCol] == 0 && grid[tempRow][tempCol] ==1){
                    q.push({{tempRow,tempCol},t+1});
                    visited[tempRow][tempCol] = 2;
                    numOrangesRottened +=1;
                }
                
            }
        }
        if(numOrangesRottened != numFreshOranges){
            return -1;
        }
        
        return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
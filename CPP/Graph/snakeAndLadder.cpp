class Solution {
public:


    int snakesAndLadders(vector<vector<int>>& board) {

        // get board size
        int boardDim= board.size();

        // flatten the board and map each idx to a cell on the board
        vector<int> flatboard(boardDim*boardDim);
        int idx = 0;
        bool lToR = true;
        for(int i = boardDim-1; i>=0;i--){
            if(lToR){
                for(int j = 0; j<boardDim;j++){
                    flatboard[idx++] = board[i][j];
                }
            }else{
                for(int j = boardDim-1;j>=0;j--){
                    flatboard[idx++]=board[i][j];
                }
            }
            lToR = !lToR;
        }
        vector<int> visited(boardDim*boardDim,-1);
        queue<int> q;
        q.push(0);
        visited[0] = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            // if the last cell is reached 
            if(front == boardDim*boardDim-1){
                return visited[front];
            }
            // try all throws from curr +1 to curr + 6
            for(int i = 1; i<=6 ; i++){
                int next =front + i;
                // if curr reaches out of bound continue
                if(next >=boardDim*boardDim){
                    continue;
                }
                // if a snake or ladder is encountered go to the idx on the board
                if(flatboard[next]!=-1){
                    next = flatboard[next]-1;
                }
                // if no snake or ladder, add a step and move to next 
                if(visited[next] ==-1){
                    visited[next] = visited[front] + 1;
                    q.push(next);
                }
            }
        }
return -1;

        
    }
};
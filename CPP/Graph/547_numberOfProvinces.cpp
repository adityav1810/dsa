void dfs(int node,vector<int> &visited,vector<int> adjLs[]){
        visited[node] = 1;
        
        for(auto child: adjLs[node]){
            if(visited[child]!=1){
                dfs(child,visited,adjLs);

            }
        }
    }



    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int>adj[n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        vector<int>visited(n,0);
        int ans= 0;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                ans++;
            }
        }
        return ans;

    }
  void dfs(int node,vector<int> & visited,vector<int> adj[],vector<int> &ans){
    //   Visit current node
      visited[node] = 1;
      ans.push_back(node);
      
    //   explore children
    for(auto child: adj[node]){
        if(visited[child]!=1){
            dfs(child,visited,adj,ans);
        }
    }
    
      
  }
  
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V+1,0);
        vector<int> ans;
        dfs(0,visited,adj,ans);
        return ans;
    
    }
};
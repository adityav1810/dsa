    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int visited[V] = {0};
        visited[0] = 1;
        vector<int> bfs;
        queue <int> q;
        q.push(0);
        while(!q.empty()){
            // get parent
            int node = q.front();
            q.pop();
            // visit parent
            bfs.push_back(node);
            // explore children
            for(auto children : adj[node]){
                if(visited[children]!=1){
                    q.push(children);
                    visited[children] = 1;
                }
            }
        }
        return bfs;
        
        
    }
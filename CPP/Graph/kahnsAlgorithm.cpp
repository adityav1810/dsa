#include <bits/stdc++.h> 
#include<vector>


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adjacency list
    unordered_map<int,list<int>> adj;
    for(int i = 0; i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    

    // create indegree
    vector<int> indegree(v);
    for(auto i: adj){
        for(auto j:i.second){
            indegree[j]++;
        }
        
    }

    // when indegree of a node is 0, push node to queue
    queue<int> q;
    for(int i = 0; i<v;i++){
        if (indegree[i] == 0){
            q.push(i);
        }
    }

    // do bfs
    
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        
        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                
                q.push(neighbour);
            }
        }
        
    }
    return ans;
    
}
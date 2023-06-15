#include <bits/stdc++.h> 
#include <unordered_map>
#include<list>
#include<stack>
#include<vector>


void tsHelper(int node,vector<bool> &visited,stack<int> &ts, unordered_map<int,list<int>> &adj){
    visited[node] = 1;
    for(auto neighbours : adj[node]){
        if(!visited[neighbours]){
            tsHelper(neighbours, visited,ts, adj);
            visited[neighbours] = 1;
        }
    }
    ts.push(node);
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    // Create adjacency List
    unordered_map<int,list<int>> adj;
    for(int i = 0 ; i<e; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> visited(v);
    stack<int> ts;

    for(int i = 0; i<v;i++){
        if(!visited[i]){
            tsHelper(i,visited,ts,adj);
        }
    }
    vector<int> result;
    while(!ts.empty()){
        result.push_back(ts.top());
        ts.pop();
    }
    return result;
    



}
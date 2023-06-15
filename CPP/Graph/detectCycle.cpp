#include<list>
#include<unordered_map>
bool cycleDFS(int node, unordered_map<int,bool> &visited,
unordered_map<int,bool> &dfsVisited,unordered_map<int,list<int>> adj){
// visit the node
  visited[node] = true;
  dfsVisited[node] = true;
  // explore children
  for(auto neighbour : adj[node]){
    // if neighbour is not visited, visit it 
    if(!visited[neighbour]){
            bool cycledetected=cycleDFS(neighbour,visited,dfsVisited,adj);
            if(cycledetected)
                return true;
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }
  dfsVisited[node] = false;
  return false;

}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // create adjacency List
  unordered_map<int,list<int>> adj;
  for(int i = 0; i<edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;
    adj[u].push_back(v);
  }
  // create visited array
  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsVisited;
  for(int i = 1; i<=n;i++){
    if(!visited[i]){
      if (cycleDFS(i,visited,dfsVisited,adj)) {
        return 1;
      }
    }
  }
return 0;
}